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
CMAKE_SOURCE_DIR = "C:\Users\andre\Documents\UTCN Computer Science\An1\Sem1\Computer Programming\C Programming. A Modern Approuch - K. N. KIng\Programming Projects\Chapter17\P5"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\andre\Documents\UTCN Computer Science\An1\Sem1\Computer Programming\C Programming. A Modern Approuch - K. N. KIng\Programming Projects\Chapter17\P5\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/P5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/P5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/P5.dir/flags.make

CMakeFiles/P5.dir/main.c.obj: CMakeFiles/P5.dir/flags.make
CMakeFiles/P5.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\andre\Documents\UTCN Computer Science\An1\Sem1\Computer Programming\C Programming. A Modern Approuch - K. N. KIng\Programming Projects\Chapter17\P5\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/P5.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\P5.dir\main.c.obj   -c "C:\Users\andre\Documents\UTCN Computer Science\An1\Sem1\Computer Programming\C Programming. A Modern Approuch - K. N. KIng\Programming Projects\Chapter17\P5\main.c"

CMakeFiles/P5.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/P5.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\andre\Documents\UTCN Computer Science\An1\Sem1\Computer Programming\C Programming. A Modern Approuch - K. N. KIng\Programming Projects\Chapter17\P5\main.c" > CMakeFiles\P5.dir\main.c.i

CMakeFiles/P5.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/P5.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\andre\Documents\UTCN Computer Science\An1\Sem1\Computer Programming\C Programming. A Modern Approuch - K. N. KIng\Programming Projects\Chapter17\P5\main.c" -o CMakeFiles\P5.dir\main.c.s

# Object files for target P5
P5_OBJECTS = \
"CMakeFiles/P5.dir/main.c.obj"

# External object files for target P5
P5_EXTERNAL_OBJECTS =

P5.exe: CMakeFiles/P5.dir/main.c.obj
P5.exe: CMakeFiles/P5.dir/build.make
P5.exe: CMakeFiles/P5.dir/linklibs.rsp
P5.exe: CMakeFiles/P5.dir/objects1.rsp
P5.exe: CMakeFiles/P5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\andre\Documents\UTCN Computer Science\An1\Sem1\Computer Programming\C Programming. A Modern Approuch - K. N. KIng\Programming Projects\Chapter17\P5\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable P5.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\P5.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/P5.dir/build: P5.exe

.PHONY : CMakeFiles/P5.dir/build

CMakeFiles/P5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\P5.dir\cmake_clean.cmake
.PHONY : CMakeFiles/P5.dir/clean

CMakeFiles/P5.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\andre\Documents\UTCN Computer Science\An1\Sem1\Computer Programming\C Programming. A Modern Approuch - K. N. KIng\Programming Projects\Chapter17\P5" "C:\Users\andre\Documents\UTCN Computer Science\An1\Sem1\Computer Programming\C Programming. A Modern Approuch - K. N. KIng\Programming Projects\Chapter17\P5" "C:\Users\andre\Documents\UTCN Computer Science\An1\Sem1\Computer Programming\C Programming. A Modern Approuch - K. N. KIng\Programming Projects\Chapter17\P5\cmake-build-debug" "C:\Users\andre\Documents\UTCN Computer Science\An1\Sem1\Computer Programming\C Programming. A Modern Approuch - K. N. KIng\Programming Projects\Chapter17\P5\cmake-build-debug" "C:\Users\andre\Documents\UTCN Computer Science\An1\Sem1\Computer Programming\C Programming. A Modern Approuch - K. N. KIng\Programming Projects\Chapter17\P5\cmake-build-debug\CMakeFiles\P5.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/P5.dir/depend

