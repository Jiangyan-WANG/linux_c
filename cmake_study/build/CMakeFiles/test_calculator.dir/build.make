# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wjy/Desktop/cmake_study

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wjy/Desktop/cmake_study/build

# Include any dependencies generated for this target.
include CMakeFiles/test_calculator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_calculator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_calculator.dir/flags.make

CMakeFiles/test_calculator.dir/add.c.o: CMakeFiles/test_calculator.dir/flags.make
CMakeFiles/test_calculator.dir/add.c.o: ../add.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wjy/Desktop/cmake_study/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test_calculator.dir/add.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_calculator.dir/add.c.o   -c /home/wjy/Desktop/cmake_study/add.c

CMakeFiles/test_calculator.dir/add.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_calculator.dir/add.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wjy/Desktop/cmake_study/add.c > CMakeFiles/test_calculator.dir/add.c.i

CMakeFiles/test_calculator.dir/add.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_calculator.dir/add.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wjy/Desktop/cmake_study/add.c -o CMakeFiles/test_calculator.dir/add.c.s

CMakeFiles/test_calculator.dir/add.c.o.requires:

.PHONY : CMakeFiles/test_calculator.dir/add.c.o.requires

CMakeFiles/test_calculator.dir/add.c.o.provides: CMakeFiles/test_calculator.dir/add.c.o.requires
	$(MAKE) -f CMakeFiles/test_calculator.dir/build.make CMakeFiles/test_calculator.dir/add.c.o.provides.build
.PHONY : CMakeFiles/test_calculator.dir/add.c.o.provides

CMakeFiles/test_calculator.dir/add.c.o.provides.build: CMakeFiles/test_calculator.dir/add.c.o


CMakeFiles/test_calculator.dir/sub.c.o: CMakeFiles/test_calculator.dir/flags.make
CMakeFiles/test_calculator.dir/sub.c.o: ../sub.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wjy/Desktop/cmake_study/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/test_calculator.dir/sub.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_calculator.dir/sub.c.o   -c /home/wjy/Desktop/cmake_study/sub.c

CMakeFiles/test_calculator.dir/sub.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_calculator.dir/sub.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wjy/Desktop/cmake_study/sub.c > CMakeFiles/test_calculator.dir/sub.c.i

CMakeFiles/test_calculator.dir/sub.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_calculator.dir/sub.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wjy/Desktop/cmake_study/sub.c -o CMakeFiles/test_calculator.dir/sub.c.s

CMakeFiles/test_calculator.dir/sub.c.o.requires:

.PHONY : CMakeFiles/test_calculator.dir/sub.c.o.requires

CMakeFiles/test_calculator.dir/sub.c.o.provides: CMakeFiles/test_calculator.dir/sub.c.o.requires
	$(MAKE) -f CMakeFiles/test_calculator.dir/build.make CMakeFiles/test_calculator.dir/sub.c.o.provides.build
.PHONY : CMakeFiles/test_calculator.dir/sub.c.o.provides

CMakeFiles/test_calculator.dir/sub.c.o.provides.build: CMakeFiles/test_calculator.dir/sub.c.o


CMakeFiles/test_calculator.dir/mul.c.o: CMakeFiles/test_calculator.dir/flags.make
CMakeFiles/test_calculator.dir/mul.c.o: ../mul.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wjy/Desktop/cmake_study/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/test_calculator.dir/mul.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_calculator.dir/mul.c.o   -c /home/wjy/Desktop/cmake_study/mul.c

CMakeFiles/test_calculator.dir/mul.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_calculator.dir/mul.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wjy/Desktop/cmake_study/mul.c > CMakeFiles/test_calculator.dir/mul.c.i

CMakeFiles/test_calculator.dir/mul.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_calculator.dir/mul.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wjy/Desktop/cmake_study/mul.c -o CMakeFiles/test_calculator.dir/mul.c.s

CMakeFiles/test_calculator.dir/mul.c.o.requires:

.PHONY : CMakeFiles/test_calculator.dir/mul.c.o.requires

CMakeFiles/test_calculator.dir/mul.c.o.provides: CMakeFiles/test_calculator.dir/mul.c.o.requires
	$(MAKE) -f CMakeFiles/test_calculator.dir/build.make CMakeFiles/test_calculator.dir/mul.c.o.provides.build
.PHONY : CMakeFiles/test_calculator.dir/mul.c.o.provides

CMakeFiles/test_calculator.dir/mul.c.o.provides.build: CMakeFiles/test_calculator.dir/mul.c.o


CMakeFiles/test_calculator.dir/div.c.o: CMakeFiles/test_calculator.dir/flags.make
CMakeFiles/test_calculator.dir/div.c.o: ../div.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wjy/Desktop/cmake_study/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/test_calculator.dir/div.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_calculator.dir/div.c.o   -c /home/wjy/Desktop/cmake_study/div.c

CMakeFiles/test_calculator.dir/div.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_calculator.dir/div.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wjy/Desktop/cmake_study/div.c > CMakeFiles/test_calculator.dir/div.c.i

CMakeFiles/test_calculator.dir/div.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_calculator.dir/div.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wjy/Desktop/cmake_study/div.c -o CMakeFiles/test_calculator.dir/div.c.s

CMakeFiles/test_calculator.dir/div.c.o.requires:

.PHONY : CMakeFiles/test_calculator.dir/div.c.o.requires

CMakeFiles/test_calculator.dir/div.c.o.provides: CMakeFiles/test_calculator.dir/div.c.o.requires
	$(MAKE) -f CMakeFiles/test_calculator.dir/build.make CMakeFiles/test_calculator.dir/div.c.o.provides.build
.PHONY : CMakeFiles/test_calculator.dir/div.c.o.provides

CMakeFiles/test_calculator.dir/div.c.o.provides.build: CMakeFiles/test_calculator.dir/div.c.o


CMakeFiles/test_calculator.dir/test.c.o: CMakeFiles/test_calculator.dir/flags.make
CMakeFiles/test_calculator.dir/test.c.o: ../test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wjy/Desktop/cmake_study/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/test_calculator.dir/test.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_calculator.dir/test.c.o   -c /home/wjy/Desktop/cmake_study/test.c

CMakeFiles/test_calculator.dir/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_calculator.dir/test.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wjy/Desktop/cmake_study/test.c > CMakeFiles/test_calculator.dir/test.c.i

CMakeFiles/test_calculator.dir/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_calculator.dir/test.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wjy/Desktop/cmake_study/test.c -o CMakeFiles/test_calculator.dir/test.c.s

CMakeFiles/test_calculator.dir/test.c.o.requires:

.PHONY : CMakeFiles/test_calculator.dir/test.c.o.requires

CMakeFiles/test_calculator.dir/test.c.o.provides: CMakeFiles/test_calculator.dir/test.c.o.requires
	$(MAKE) -f CMakeFiles/test_calculator.dir/build.make CMakeFiles/test_calculator.dir/test.c.o.provides.build
.PHONY : CMakeFiles/test_calculator.dir/test.c.o.provides

CMakeFiles/test_calculator.dir/test.c.o.provides.build: CMakeFiles/test_calculator.dir/test.c.o


# Object files for target test_calculator
test_calculator_OBJECTS = \
"CMakeFiles/test_calculator.dir/add.c.o" \
"CMakeFiles/test_calculator.dir/sub.c.o" \
"CMakeFiles/test_calculator.dir/mul.c.o" \
"CMakeFiles/test_calculator.dir/div.c.o" \
"CMakeFiles/test_calculator.dir/test.c.o"

# External object files for target test_calculator
test_calculator_EXTERNAL_OBJECTS =

test_calculator: CMakeFiles/test_calculator.dir/add.c.o
test_calculator: CMakeFiles/test_calculator.dir/sub.c.o
test_calculator: CMakeFiles/test_calculator.dir/mul.c.o
test_calculator: CMakeFiles/test_calculator.dir/div.c.o
test_calculator: CMakeFiles/test_calculator.dir/test.c.o
test_calculator: CMakeFiles/test_calculator.dir/build.make
test_calculator: CMakeFiles/test_calculator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wjy/Desktop/cmake_study/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable test_calculator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_calculator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_calculator.dir/build: test_calculator

.PHONY : CMakeFiles/test_calculator.dir/build

CMakeFiles/test_calculator.dir/requires: CMakeFiles/test_calculator.dir/add.c.o.requires
CMakeFiles/test_calculator.dir/requires: CMakeFiles/test_calculator.dir/sub.c.o.requires
CMakeFiles/test_calculator.dir/requires: CMakeFiles/test_calculator.dir/mul.c.o.requires
CMakeFiles/test_calculator.dir/requires: CMakeFiles/test_calculator.dir/div.c.o.requires
CMakeFiles/test_calculator.dir/requires: CMakeFiles/test_calculator.dir/test.c.o.requires

.PHONY : CMakeFiles/test_calculator.dir/requires

CMakeFiles/test_calculator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_calculator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_calculator.dir/clean

CMakeFiles/test_calculator.dir/depend:
	cd /home/wjy/Desktop/cmake_study/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wjy/Desktop/cmake_study /home/wjy/Desktop/cmake_study /home/wjy/Desktop/cmake_study/build /home/wjy/Desktop/cmake_study/build /home/wjy/Desktop/cmake_study/build/CMakeFiles/test_calculator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_calculator.dir/depend

