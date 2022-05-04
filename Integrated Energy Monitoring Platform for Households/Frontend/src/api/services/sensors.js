import authHeader, { BASE_URL, HTTP } from "../http";

export default {
    allSensors() {
        return HTTP.get(BASE_URL + "/sensors", { headers: authHeader() }).then(
            (response) => {
                return response.data;
            }
        );
    },

    create(sensor) {
        return HTTP.post(BASE_URL + "/sensors", sensor, { headers: authHeader() }).then(
            (response) => {
                return response.data;
            }
        );
    },
    update(sensor) {
        return HTTP.put(BASE_URL + `/sensors/${sensor.id}`, sensor, { headers: authHeader() }).then(
            (response) => {
                return response.data;
            }
        );
    },

    delete(sensor){
        return HTTP.delete(BASE_URL + `/sensors/${sensor.id}`, { headers: authHeader() }).then(
            (response) => {
                return response.data;
            }
        );
    },
};