#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp> //core glm functionality
#include <glm/gtc/matrix_transform.hpp> //glm extension for generating common transformation matrices
#include <glm/gtc/matrix_inverse.hpp> //glm extension for computing inverse matrices
#include <glm/gtc/type_ptr.hpp> //glm extension for accessing the internal data structure of glm types

#include "Window.h"
#include "Shader.hpp"
#include "Camera.hpp"
#include "Model3D.hpp"
#include "SkyBox.hpp"

#include <iostream>

// window
gps::Window myWindow;

// matrices
glm::mat4 model;
//glm::mat4 model1;
glm::mat4 view;
glm::mat4 projection;
glm::mat3 normalMatrix;

// light parameters
glm::vec3 lightDir;
glm::vec3 lightColor;
glm::vec3 pointLight;
GLuint pointDirLoc;

// shader uniform locations
GLuint modelLoc;
GLuint viewLoc;
GLuint projectionLoc;
GLuint normalMatrixLoc;
GLuint lightDirLoc;
GLuint lightColorLoc;
GLuint pointLoc;

glm::mat4 lightRotation;
GLfloat lightAngle = 40.0f;
//const unsigned int SHADOW_WIDTH = 2048;
//const unsigned int SHADOW_HEIGHT = 2048;

const unsigned int SHADOW_WIDTH = 2048;
const unsigned int SHADOW_HEIGHT = 2048;

GLuint shadowMapFBO;
GLuint depthMapTexture;

gps::Shader depthMapShader;
gps::Shader lightShader;
gps::Shader waterShader;

// camera
gps::Camera myCamera(
    glm::vec3(-30.f, 50.0f, -100.0f),
    glm::vec3(400.0f, 0.0f, 40.0f),
    glm::vec3(0.0f, 1.0f, 0.0f));

GLfloat cameraSpeed = 10.0f;

GLboolean pressedKeys[1024];

// water
GLfloat vertices[] = {
    -1, -1, -1, 
    1, 1, -1,
    1, -1, -1,
    1, 1, 1
};
GLuint verticesVAO;
GLuint waterVBO;

// models
GLfloat angle;

gps::Model3D ground;
gps::Model3D cabin;
gps::Model3D lightCube;
gps::Model3D logGround;
gps::Model3D treeA;
gps::Model3D campFire;
gps::Model3D car;
gps::Model3D water;
gps::Model3D grass;
gps::Model3D boat;
gps::Model3D person1;
gps::Model3D person2;
gps::Model3D person3;

//gps::Model3D treeC;
//gps::Model3D treeB;

// shaders
gps::Shader myBasicShader;
gps::Shader skyboxShader;

// skybox
gps::SkyBox mySkyBox;

bool boatAnimation = false, carAnimation = false;
float boatDelta = 0.0f, carDelta = 0.0f;
bool cameraAnimation = true;
float deltaWater = -1.1f;

GLenum glCheckError_(const char *file, int line)
{
	GLenum errorCode;
	while ((errorCode = glGetError()) != GL_NO_ERROR) {
		std::string error;
		switch (errorCode) {
            case GL_INVALID_ENUM:
                error = "INVALID_ENUM";
                break;
            case GL_INVALID_VALUE:
                error = "INVALID_VALUE";
                break;
            case GL_INVALID_OPERATION:
                error = "INVALID_OPERATION";
                break;
            case GL_STACK_OVERFLOW:
                error = "STACK_OVERFLOW";
                break;
            case GL_STACK_UNDERFLOW:
                error = "STACK_UNDERFLOW";
                break;
            case GL_OUT_OF_MEMORY:
                error = "OUT_OF_MEMORY";
                break;
            case GL_INVALID_FRAMEBUFFER_OPERATION:
                error = "INVALID_FRAMEBUFFER_OPERATION";
                break;
        }
		std::cout << error << " | " << file << " (" << line << ")" << std::endl;
	}
	return errorCode;
}
#define glCheckError() glCheckError_(__FILE__, __LINE__)

void windowResizeCallback(GLFWwindow* window, int width, int height) {
	fprintf(stdout, "Window resized! New width: %d , and height: %d\n", width, height);
	//TODO

}

void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }

	if (key >= 0 && key < 1024) {
        if (action == GLFW_PRESS) {
            pressedKeys[key] = true;
        } else if (action == GLFW_RELEASE) {
            pressedKeys[key] = false;
        }
    }
}

bool firstMouse = true;
float yaw = -90.0f;
float pitch = 0.0f;
float lastX = 400, lastY = 300;

void mouseCallback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.2f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    myCamera.rotate(pitch, yaw);

    view = myCamera.getViewMatrix();
}

void processMovement() {
	if (pressedKeys[GLFW_KEY_W]) {
		myCamera.move(gps::MOVE_FORWARD, cameraSpeed);
		//update view matrix
        view = myCamera.getViewMatrix();
        myBasicShader.useShaderProgram();
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        // compute normal matrix for teapot
        normalMatrix = glm::mat3(glm::inverseTranspose(view*model));
	}

	if (pressedKeys[GLFW_KEY_S]) {
		myCamera.move(gps::MOVE_BACKWARD, cameraSpeed);
        //update view matrix
        view = myCamera.getViewMatrix();
        myBasicShader.useShaderProgram();
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        // compute normal matrix for teapot
        normalMatrix = glm::mat3(glm::inverseTranspose(view*model));
	}

	if (pressedKeys[GLFW_KEY_A]) {
		myCamera.move(gps::MOVE_LEFT, cameraSpeed);
        //update view matrix
        view = myCamera.getViewMatrix();
        myBasicShader.useShaderProgram();
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        // compute normal matrix for teapot
        normalMatrix = glm::mat3(glm::inverseTranspose(view*model));
	}

	if (pressedKeys[GLFW_KEY_D]) {
		myCamera.move(gps::MOVE_RIGHT, cameraSpeed);
        //update view matrix
        view = myCamera.getViewMatrix();
        myBasicShader.useShaderProgram();
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        // compute normal matrix for teapot
        normalMatrix = glm::mat3(glm::inverseTranspose(view*model));
	}


    if (pressedKeys[GLFW_KEY_J]) {
        lightAngle -= 1.0f;
    }

    if (pressedKeys[GLFW_KEY_L]) {
        lightAngle += 1.0f;
    }

    if (pressedKeys[GLFW_KEY_Z]) {
        boatAnimation = true;
        boatDelta += 0.3;
    }

    if (pressedKeys[GLFW_KEY_X]) {
        boatAnimation = false;
        boatDelta -= 0.3;
    }

    if (glfwGetKey(myWindow.getWindow(), GLFW_KEY_O)) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

    if (glfwGetKey(myWindow.getWindow(), GLFW_KEY_P)) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }

    if (pressedKeys[GLFW_KEY_I]) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
    }

    if (pressedKeys[GLFW_KEY_T]) {
        if (cameraAnimation) {
            cameraAnimation = false;
            myCamera.move(gps::MOVE_FORWARD, 10.0f);
            myCamera.move(gps::MOVE_LEFT, 3.0f);
        }
        angle += 3.0f;
        myCamera.rotate(0, angle);
        //update view matrix
        view = myCamera.getViewMatrix();
        myBasicShader.useShaderProgram();
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        // compute normal matrix for teapot
        normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
    }
    myBasicShader.useShaderProgram();
    glm::mat4 view = myCamera.getViewMatrix();
    GLint viewLoc = glGetUniformLocation(myBasicShader.shaderProgram, "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
}
/*
void boat_animation() {
    if (boatAnimation) {
        boatDelta += 0.3;
        
        if (boatDelta <= 30)
            boatAnimation = !boatAnimation;
        
    }
    else {
        boatDelta -= 0.3;
        
        if (boatDelta >= -30)
           boatAnimation = !boatAnimation;
        
    }
}
*/

void waterAnimation() {
     deltaWater += 0.001f;
     if (deltaWater > -1.095)
         while(deltaWater >= -1.1f)
            deltaWater -= 0.001f;
}

/*
void initWaterVAO() {
    glGenBuffers(1, &waterVBO);
    glBindBuffer(GL_ARRAY_BUFFER, waterVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenVertexArrays(1, &verticesVAO);
    glBindVertexArray(verticesVAO);
    glBindBuffer(GL_ARRAY_BUFFER, waterVBO);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), NULL);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
}
*/

void initOpenGLWindow() {
    myWindow.Create(3000, 1500, "OpenGL Project Core");
}

void setWindowCallbacks() {
	glfwSetWindowSizeCallback(myWindow.getWindow(), windowResizeCallback);
    glfwSetKeyCallback(myWindow.getWindow(), keyboardCallback);
    glfwSetCursorPosCallback(myWindow.getWindow(), mouseCallback);
    //glfwSetInputMode(myWindow.getWindow(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    glfwSetInputMode(myWindow.getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void initOpenGLState() {
	glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
	glViewport(0, 0, myWindow.getWindowDimensions().width, myWindow.getWindowDimensions().height);
    glEnable(GL_FRAMEBUFFER_SRGB);
	glEnable(GL_DEPTH_TEST); // enable depth-testing
	glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"
	glEnable(GL_CULL_FACE); // cull face
	glCullFace(GL_BACK); // cull back face
	glFrontFace(GL_CCW); // GL_CCW for counter clock-wise
}

void initSkyBox() {

    std::vector<const GLchar*> faces;
    faces.push_back("textures/skybox/nightsky_rt.tga");
    faces.push_back("textures/skybox/nightsky_lf.tga");
    faces.push_back("textures/skybox/nightsky_up3.tga");
    faces.push_back("textures/skybox/nightsky_dn.tga");
    faces.push_back("textures/skybox/nightsky_bk.tga");
    faces.push_back("textures/skybox/nightsky_ft.tga");

    mySkyBox.Load(faces);

    view = myCamera.getViewMatrix();
    glUniformMatrix4fv(glGetUniformLocation(skyboxShader.shaderProgram, "view"), 1, GL_FALSE,
        glm::value_ptr(view));

    projection = glm::perspective(glm::radians(45.0f), (float)myWindow.getWindowDimensions().width / (float)myWindow.getWindowDimensions().height, 0.1f, 1000.0f);
    glUniformMatrix4fv(glGetUniformLocation(skyboxShader.shaderProgram, "projection"), 1, GL_FALSE,
        glm::value_ptr(projection));
}

void initModels() {
    campFire.LoadModel("models/fire/1/Campfire.obj");
    ground.LoadModel("models/ground/ground.obj");
    cabin.LoadModel("models/cabin/Alpine/Alpine_chalet.obj");
    lightCube.LoadModel("models/cube/cube.obj");
    logGround.LoadModel("models/log/hi_obj.obj");
    treeA.LoadModel("models/treeA/Tree.obj");
    car.LoadModel("models/car/Shelby.obj");
    water.LoadModel("models/water/water.obj");
    grass.LoadModel("models/grass/Grass_02.obj");
    boat.LoadModel("models/boat/OldBoat.obj");
    person1.LoadModel("models/person1/muro.obj");
    person2.LoadModel("models/person2/Stacy.obj");
    person3.LoadModel("models/person3/Alfred.obj");
}

void initShaders() {
    skyboxShader.loadShader("shaders/skybox/skyboxShader.vert", "shaders/skybox/skyboxShader.frag");
    skyboxShader.useShaderProgram();
	myBasicShader.loadShader("shaders/basic.vert", "shaders/basic.frag");
    myBasicShader.useShaderProgram();
    depthMapShader.loadShader("shaders/depthMap.vert", "shaders/depthMap.frag");
    depthMapShader.useShaderProgram();
}

void initUniforms() {
    myBasicShader.useShaderProgram();

    // create model matrix for teapot
    model = glm::mat4(1.0f);
    // create model matrix for teapot
    modelLoc = glGetUniformLocation(myBasicShader.shaderProgram, "model");

    // get view matrix for current camera
    view = myCamera.getViewMatrix();
    viewLoc = glGetUniformLocation(myBasicShader.shaderProgram, "view");
    // send view matrix to shader
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

    // compute normal matrix for teapot
    normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
    normalMatrixLoc = glGetUniformLocation(myBasicShader.shaderProgram, "normalMatrix");

    // create projection matrix
    projection = glm::perspective(glm::radians(45.0f),
        (float)myWindow.getWindowDimensions().width / (float)myWindow.getWindowDimensions().height,
        0.1f, 1000.0f);
    projectionLoc = glGetUniformLocation(myBasicShader.shaderProgram, "projection");

    // send projection matrix to shader
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

    //-------------------------------------------------------------------------------------------------------------------
    //1st light source - directional light
    //set the light direction (direction towards the light)
    //lightDir = glm::vec3(10.0f, 30.0f, 10.0f);
    lightDir = glm::vec3(30.0f, 30.0f, 10.0f);
    lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
    lightDirLoc = glGetUniformLocation(myBasicShader.shaderProgram, "lightDir");
    // send light dir to shader
    glUniform3fv(lightDirLoc, 1, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));

    //set light color

    lightColor = glm::vec3(0.137255f, 0.137255f, 0.556863f); //navy blue
    //lightColor = glm::vec3(0.0, 0.0, 0.5); //dark blue
    //lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //white light
    lightColorLoc = glGetUniformLocation(myBasicShader.shaderProgram, "lightColor");
    // send light color to shader
    glUniform3fv(lightColorLoc, 1, glm::value_ptr(lightColor));

    //-------------------------------------------------------------------------------------------------------------------
    //2nd light source - point light
    pointLight = glm::vec3(80.0f, 1.0f, 200.0f); //point light position
    pointLoc = glGetUniformLocation(myBasicShader.shaderProgram, "pointLight");
    glUniform3fv(pointLoc, 1, glm::value_ptr(pointLight));

}


void initFBO() {
    //TODO - Create the FBO, the depth texture and attach the depth texture to the FBO
    glGenFramebuffers(1, &shadowMapFBO);
    glGenTextures(1, &depthMapTexture);
    glBindTexture(GL_TEXTURE_2D, depthMapTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    float borderColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glBindFramebuffer(GL_FRAMEBUFFER, shadowMapFBO);
    glDrawBuffer(GL_NONE);
    glReadBuffer(GL_NONE);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMapTexture, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

glm::mat4 computeLightSpaceTrMatrix() {
    //TODO - Return the light-space transformation matrix
    glm::mat4 lightView = glm::lookAt(glm::mat3(lightRotation) * lightDir, glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    const GLfloat near_plane = 0.1f, far_plane = 1000.0f;

    glm::mat4 lightProjection = glm::ortho(-800.0f, 800.0f, -800.0f, 800.0f, near_plane, far_plane);
    glm::mat4 lightSpaceTrMatrix = lightProjection * lightView;
    return lightSpaceTrMatrix;
}

void renderLog(gps::Shader shader) {
    shader.useShaderProgram();
    model = glm::translate(glm::mat4(1.0f), glm::vec3(85.0f, 0.0f, 210.0f));
    model = glm::scale(model, glm::vec3(0.25f, 0.25f, 0.25f));
    //model = glm::rotate(model, glm::radians(5.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
    normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
    ////send normal matrix data to shader
    glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
    logGround.Draw(shader);
 }

void renderLog2(gps::Shader shader) {
    shader.useShaderProgram();
    model = glm::translate(glm::mat4(1.0f), glm::vec3(65.0f, 1.0f, 200.0f));
    model = glm::scale(model, glm::vec3(0.25f, 0.25f, 0.25f));
    model = glm::rotate(model, glm::radians(55.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
    normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
    ////send normal matrix data to shader
    glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
    logGround.Draw(shader);
}

void renderLog3(gps::Shader shader) {
    shader.useShaderProgram();
    model = glm::translate(glm::mat4(1.0f), glm::vec3(70.0f, 1.0f, 210.0f));
    model = glm::scale(model, glm::vec3(0.25f, 0.25f, 0.25f));
    model = glm::rotate(model, glm::radians(130.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
    normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
    ////send normal matrix data to shader
    glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
    logGround.Draw(shader);
}


void renderCar(gps::Shader shader) {
    shader.useShaderProgram();
    model = glm::translate(glm::mat4(1.0f), glm::vec3(10.0f, 3.5f, 150.0f));
    model = glm::scale(model, glm::vec3(3.3f, 3.3f, 3.3f));
    model = glm::rotate(model, glm::radians(225.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(5.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
    normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
    ////send normal matrix data to shader
    glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
    car.Draw(shader);
}
 
void renderBoat(gps::Shader shader) {
    shader.useShaderProgram();
    
    /*
    if (boatAnimation) {
        boat_animation();
    }
    */

    model = glm::translate(glm::mat4(1.0f), glm::vec3(150.0f, -9.0f, boatDelta /*50.f*/)); //50.0f
    model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
    //model = glm::rotate(model, glm::radians(225.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
    normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
    ////send normal matrix data to shader
    glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
    boat.Draw(shader);

}

void renderFire(gps::Shader shader) {
    shader.useShaderProgram();
    model = glm::translate(glm::mat4(1.0f), glm::vec3(80.0f, 0.0f, 200.0f));
    model = glm::scale(model, glm::vec3(0.05f, 0.05f, 0.05f));
    model = glm::rotate(model, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
    normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
    ////send normal matrix data to shader
    glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
    campFire.Draw(shader);
}

void renderWater(gps::Shader shader) {
    shader.useShaderProgram();

    if (true)
        waterAnimation();

    model = glm::scale(glm::mat4(1.0f), glm::vec3(50.0f, 25.5, 55.0f)); //25.0f
    model = glm::translate(model, glm::vec3(1.75f, deltaWater, 0.0f));//-1.1f
    glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
    normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
    ////send normal matrix data to shader
    glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
    water.Draw(shader);
    /*
    //shader.loadShader("shaders/waterVertex.vert", "shaders/waterFragment.frag");
    shader.useShaderProgram();

    glBindVertexArray(verticesVAO);
    model = glm::scale(glm::mat4(1.0f), glm::vec3(200.0f, 150.0f, 250.0f));
    model = glm::translate(model, glm::vec3(1.0f, -0.2f, 0.0f));

    glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
    glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));

    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
    */
    /*
    for (int i = 700; i < 750; i++) {
        model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f));
        for (int j = 700; j < 750; j++) {
            model = glm::translate(glm::mat4(1.0f), glm::vec3(i, 1.0f, j));
            glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
            //glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            //normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
            //glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
            glDrawArrays(GL_TRIANGLES, 0, 4);
        }
    }
    */
}

void renderPerson1(gps::Shader shader) {
    shader.useShaderProgram();
    model = glm::translate(glm::mat4(1.0f), glm::vec3(93.0f, -1.0f, 210.0f));
    model = glm::rotate(model, glm::radians(130.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::scale(model, glm::vec3(0.05f, 0.05f, 0.05f));
    glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
    normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
    ////send normal matrix data to shader
    glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
    person1.Draw(shader);
}

void renderPerson2(gps::Shader shader) {
    shader.useShaderProgram();
    model = glm::translate(glm::mat4(1.0f), glm::vec3(72.0f, 0.5f, 200.0f));
    model = glm::rotate(model, glm::radians(130.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::scale(model, glm::vec3(0.8f, 0.8f, 0.8f));
    glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
    normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
    ////send normal matrix data to shader
    glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
    person2.Draw(shader);
}

void renderPerson3(gps::Shader shader) {
    shader.useShaderProgram();
    model = glm::translate(glm::mat4(1.0f), glm::vec3(83.0f, 0.5f, 210.0f));
    model = glm::rotate(model, glm::radians(130.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::scale(model, glm::vec3(0.8f, 0.8f, 0.8f));
    glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
    normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
    ////send normal matrix data to shader
    glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
    person3.Draw(shader);
}

void renderCabin(gps::Shader shader) {
    shader.useShaderProgram();
    model = glm::translate(glm::mat4(1.0f), glm::vec3(30.0f, 13.0f, 180.0f));
    model = glm::rotate(model, glm::radians(130.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(4.3f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));

    glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
    normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
    glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));

    cabin.Draw(shader);
}

void renderGround(gps::Shader shader) {
    shader.useShaderProgram();
    GLfloat unghi = 90.0f;
    model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
    model = glm::scale(model, glm::vec3(20.0f, 20.0f, 20.0f));
    /*
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
    glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
    */
    glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
    normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
    glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
    ground.Draw(shader);
    /*
    for (int i = 0; i < 50; i++) {
        model = glm::translate(glm::mat4(1.0f), glm::vec3(1.0f));
        for (int j = 0; j < 50; j++) {
            model = glm::translate(glm::mat4(1.0f), glm::vec3(i * 20, 0, j * 20));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
            glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
            ground.Draw(shader);
        }
    }
    */
}

void renderGrass(gps::Shader shader) {
    shader.useShaderProgram();
    for (float i = -10; i < 0; i += 5) {
        for (float j = -30; j < 40; j += 5) {
            model = glm::translate(glm::mat4(1.0f), glm::vec3(i * 10, -1.0f, j * 10));
            model = glm::scale(model, glm::vec3(8.0f, 8.0f, 8.0f));
            glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
            normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
            ////send normal matrix data to shader
            glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
            grass.Draw(shader);
        }
    }

    for (float i = 0; i < 45; i += 5) {
        for (float j = 28; j < 40; j += 5) {
            model = glm::translate(glm::mat4(1.0f), glm::vec3(i * 10, -1.0f, j * 10));
            model = glm::scale(model, glm::vec3(8.0f, 8.0f, 8.0f));
            glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
            normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
            ////send normal matrix data to shader
            glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
            grass.Draw(shader);
        }
    }

    for (float i = -19; i < -5; i += 5) {
        for (float j = -29; j < 39; j += 5) {
            model = glm::translate(glm::mat4(1.0f), glm::vec3(i * 10, -1.0f, j * 10));
            model = glm::scale(model, glm::vec3(8.0f, 8.0f, 8.0f));
            glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
            normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
            ////send normal matrix data to shader
            glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
            grass.Draw(shader);
        }
    }

    for (float i = -10; i < 37; i += 5) {
        for (float j = 29; j < 37; j += 5) {
            model = glm::translate(glm::mat4(1.0f), glm::vec3(i * 10, -1.0f, j * 10));
            model = glm::scale(model, glm::vec3(8.0f, 8.0f, 8.0f));
            glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
            normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
            ////send normal matrix data to shader
            glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
            grass.Draw(shader);
        }
    }
}

void renderTree(gps::Shader shader){
    
    shader.useShaderProgram();
    for (float i = -15; i < 0; i += 5) {
        for (float j = -30; j < 40; j += 5) {
                model = glm::translate(glm::mat4(1.0f), glm::vec3(i * 10, 0.0f, j * 10));
                model = glm::scale(model, glm::vec3(10.0f, 10.0f, 10.0f));
                glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
                normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
                ////send normal matrix data to shader
                glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
                treeA.Draw(shader);
        }
    }

    for (float i = 0; i < 45; i += 5) {
        for (float j = 30; j < 40; j += 5) {
            model = glm::translate(glm::mat4(1.0f), glm::vec3(i * 10, 0.0f, j * 10));
            model = glm::scale(model, glm::vec3(10.0f, 10.0f, 10.0f));
            glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
            normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
            ////send normal matrix data to shader
            glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
            treeA.Draw(shader);
        }
    }

    for (float i = -17; i < -2; i += 5) {
        for (float j = -27; j < 37; j += 5) {
            model = glm::translate(glm::mat4(1.0f), glm::vec3(i * 10, 0.0f, j * 10));
            model = glm::scale(model, glm::vec3(10.0f, 10.0f, 10.0f));
            glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
            normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
            ////send normal matrix data to shader
            glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
            treeA.Draw(shader);
        }
    }

    for (float i = -7; i < 27; i += 5) {
        for (float j = 27; j < 37; j += 5) {
            model = glm::translate(glm::mat4(1.0f), glm::vec3(i * 10, 0.0f, j * 10));
            model = glm::scale(model, glm::vec3(10.0f, 10.0f, 10.0f));
            glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
            normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
            ////send normal matrix data to shader
            glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
            treeA.Draw(shader);
        }
    }

    for (float i = -15; i < 0; i += 5) {
        for (float j = -30; j < 40; j += 5) {
            model = glm::translate(glm::mat4(1.0f), glm::vec3(i * 10, 0.0f, j * 10));
            model = glm::scale(model, glm::vec3(10.0f, 10.0f, 10.0f));
            glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
            normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
            ////send normal matrix data to shader
            glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
            treeA.Draw(shader);
        }
    }

    for (float i = 30; i < 40; i += 5) {
        for (float j = -30; j < 40; j += 5) {
            model = glm::translate(glm::mat4(1.0f), glm::vec3(i * 10, 0.0f, j * 10));
            model = glm::scale(model, glm::vec3(10.0f, 10.0f, 10.0f));
            glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
            normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
            ////send normal matrix data to shader
            glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
            treeA.Draw(shader);
        }
    }

    for (float i = -10; i < 45; i += 5) {
        for (float j = -40; j < -30; j += 5) {
            model = glm::translate(glm::mat4(1.0f), glm::vec3(i * 10, 0.0f, j * 10));
            model = glm::scale(model, glm::vec3(10.0f, 10.0f, 10.0f));
            glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
            normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
            ////send normal matrix data to shader
            glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
            treeA.Draw(shader);
        }
    }
}


/*
void renderLight(gps::Shader shader) {
    lightShader.useShaderProgram();

    glUniformMatrix4fv(glGetUniformLocation(lightShader.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));

    model = lightRotation;
    model = glm::translate(model, 2.0f * lightDir);
    model = glm::scale(model, glm::vec3(0.1f, 0.1f, 0.1f));
    glUniformMatrix4fv(glGetUniformLocation(lightShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));

    lightCube.Draw(lightShader);
}
*/

void renderScene() {
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    /*
    depthMapShader.useShaderProgram();
    glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "lightSpaceTrMatrix"), 1, GL_FALSE, glm::value_ptr(computeLightSpaceTrMatrix()));
    glViewport(0, 0, SHADOW_WIDTH, SHADOW_HEIGHT);
    glBindFramebuffer(GL_FRAMEBUFFER, shadowMapFBO);
    glClear(GL_DEPTH_BUFFER_BIT);
    renderCabin(depthMapShader, 1);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    glViewport(0, 0, (float)myWindow.getWindowDimensions().width, (float)myWindow.getWindowDimensions().height);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    myBasicShader.useShaderProgram();

    view = myCamera.getViewMatrix();
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

    lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
    glUniform3fv(lightDirLoc, 1, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));

    glActiveTexture(GL_TEXTURE3);
    glBindTexture(GL_TEXTURE_2D, depthMapTexture);
    glUniform1i(glGetUniformLocation(myBasicShader.shaderProgram, "shadowMap"), 3);

    glUniformMatrix4fv(glGetUniformLocation(myBasicShader.shaderProgram, "lightSpaceTrMatrix"),
        1,
        GL_FALSE,
        glm::value_ptr(computeLightSpaceTrMatrix()));
    */

    depthMapShader.useShaderProgram();
    glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "lightSpaceTrMatrix"), 1, GL_FALSE, glm::value_ptr(computeLightSpaceTrMatrix()));
    glViewport(0, 0, SHADOW_WIDTH, SHADOW_HEIGHT);
    glBindFramebuffer(GL_FRAMEBUFFER, shadowMapFBO);
    glClear(GL_DEPTH_BUFFER_BIT);

    renderLog(depthMapShader);
    renderLog2(depthMapShader);
    renderLog3(depthMapShader);
    renderFire(depthMapShader);
    renderCabin(depthMapShader);
    renderCar(depthMapShader);
    renderGrass(depthMapShader);
    renderBoat(depthMapShader);
    renderTree(depthMapShader);
    renderGround(depthMapShader);
    renderWater(depthMapShader);
    renderPerson1(depthMapShader);
    renderPerson2(depthMapShader);
    renderPerson3(depthMapShader);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    glViewport(0, 0, (float)myWindow.getWindowDimensions().width, (float)myWindow.getWindowDimensions().height);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    myBasicShader.useShaderProgram();

    view = myCamera.getViewMatrix();
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

    lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    glUniform3fv(lightDirLoc, 1, glm::value_ptr(lightDir));

    glActiveTexture(GL_TEXTURE3);
    glBindTexture(GL_TEXTURE_2D, depthMapTexture);
    glUniform1i(glGetUniformLocation(myBasicShader.shaderProgram, "shadowMap"), 3);

    glUniformMatrix4fv(glGetUniformLocation(myBasicShader.shaderProgram, "lightSpaceTrMatrix"),
        1,
        GL_FALSE,
        glm::value_ptr(computeLightSpaceTrMatrix()));

    renderLog(myBasicShader);
    renderLog2(myBasicShader);
    renderLog3(myBasicShader);
    renderFire(myBasicShader);
    renderCabin(myBasicShader);
    renderCar(myBasicShader);
    renderGrass(myBasicShader);
    renderBoat(myBasicShader);
    renderTree(myBasicShader);
    renderGround(myBasicShader);
    renderWater(myBasicShader);
    renderPerson1(myBasicShader);
    renderPerson2(myBasicShader);
    renderPerson3(myBasicShader);

    mySkyBox.Draw(skyboxShader, view, projection);

    //cameraAnimation();
}

void cleanup() {
    glDeleteTextures(1, &depthMapTexture);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glDeleteFramebuffers(1, &shadowMapFBO);
    myWindow.Delete();
    //cleanup code for your own data
}

int main(int argc, const char * argv[]) {

    try {
        initOpenGLWindow();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    initOpenGLState();
	initModels();
	initShaders();
    initSkyBox();
	initUniforms();
    initFBO();
    setWindowCallbacks();

    glCheckError();

	// application loop
	while (!glfwWindowShouldClose(myWindow.getWindow())) {
        processMovement();
	    renderScene();

		glfwPollEvents();
		glfwSwapBuffers(myWindow.getWindow());
        
		glCheckError();
	}

	cleanup();
    
    return EXIT_SUCCESS;
}
