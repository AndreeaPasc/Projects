# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\andre\Documents\UTCN Computer Science\An1\Sem1\Computer Programming\C Programming. A Modern Approuch - K. N. KIng\Exercises\Chapter20\Ex7"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\andre\Documents\UTCN Computer Science\An1\Sem1\Computer Programming\C Programming. A Modern Approuch - K. N. KIng\Exercises\Chapter20\Ex7\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Ex7.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Ex7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ex7.dir/flags.make

CMakeFiles/Ex7.dir/main.c.obj: CMakeFiles/Ex7.dir/flags.make
CMakeFiles/Ex7.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\andre\Documents\UTCN Computer Science\An1\Sem1\Computer Programming\C Programming. A Modern Approuch - K. N. KIng\Exercises\Chapter20\Ex7\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Ex7.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Ex7.dir\main.c.obj   -c "C:\Users\andre\Documents\UTCN Computer Science\An1\Sem1\Computer Programming\C Programming. A Modern Approuch - K. N. KIng\Exercises\Chapter20\Ex7\main.c"

CMakeFiles/Ex7.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Ex7.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\andre\Documents\UTCN Computer Science\An1\Sem1\Computer Programming\C Programming. A Modern Approuch - K. N. KIng\Exercises\Chapter20\Ex7\main.c" > CMakeFiles\Ex7.dir\main.c.i

CMakeFiles/Ex7.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Ex7.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\andre\Documents\UTCN Computer Science\An1\Sem1\Computer Programming\C Programming. A Modern Approuch - K. N. KIng\Exercises\Chapter20\Ex7\main.c" -o CMakeFiles\Ex7.dir\main.c.s

# Object files for target Ex7
Ex7_OBJECTS = \
"CMakeFiles/Ex7.dir/main.c.obj"

# External object files for target Ex7
Ex7_EXTERNAL_OBJECTS =

Ex7.exe: CMakeFiles/Ex7.dir/main.c.obj
Ex7.exe: CMakeFiles/Ex7.dir/build.make
Ex7.exe: CMakeFiles/Ex7.dir/linklibs.rsp
Ex7.exe: CMakeFiles/Ex7.dir/objects1.rsp
Ex7.exe: CMakeFiles/Ex7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\andre\Documents\UTCN Computer Science\An1\Sem1\Computer Programming\C Programming. A Modern Approuch - K. N. KIng\Exercises\Chapter20\Ex7\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Ex7.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Ex7.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ex7.dir/build: Ex7.exe

.PHONY : CMakeFiles/Ex7.dir/build

CMakeFiles/Ex7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Ex7.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Ex7.dir/clean

CMakeFiles/Ex7.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\andre\Documents\UTCN Computer Science\An1\Sem1\Computer Programming\C Programming. A Modern Approuch - K. N. KIng\Exercises\Chapter20\Ex7" "C:\Users\andre\Documents\UTCN Computer Science\An1\Sem1\Computer Programming\C Programming. A Modern Approuch - K. N. KIng\Exercises\Chapter20\Ex7" "C:\Users\andre\Documents\UTCN Computer Science\An1\Sem1\Computer Programming\C Programming. A Modern Approuch - K. N. KIng\Exercises\Chapter20\Ex7\cmake-build-debug" "C:\Users\andre\Documents\UTCN Computer Science\An1\Sem1\Computer Programming\C Programming. A Modern Approuch - K. N. KIng\Exercises\Chapter20\Ex7\cmake-build-debug" "C:\Users\andre\Documents\UTCN Computer Science\An1\Sem1\Computer Programming\C Programming. A Modern Approuch - K. N. KIng\Exercises\Chapter20\Ex7\cmake-build-debug\CMakeFiles\Ex7.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Ex7.dir/depend

