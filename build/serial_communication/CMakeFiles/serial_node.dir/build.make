# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/enis/catkin_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/enis/catkin_ws/build

# Include any dependencies generated for this target.
include serial_communication/CMakeFiles/serial_node.dir/depend.make

# Include the progress variables for this target.
include serial_communication/CMakeFiles/serial_node.dir/progress.make

# Include the compile flags for this target's objects.
include serial_communication/CMakeFiles/serial_node.dir/flags.make

serial_communication/CMakeFiles/serial_node.dir/src/serial_example_node.cpp.o: serial_communication/CMakeFiles/serial_node.dir/flags.make
serial_communication/CMakeFiles/serial_node.dir/src/serial_example_node.cpp.o: /home/enis/catkin_ws/src/serial_communication/src/serial_example_node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/enis/catkin_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object serial_communication/CMakeFiles/serial_node.dir/src/serial_example_node.cpp.o"
	cd /home/enis/catkin_ws/build/serial_communication && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serial_node.dir/src/serial_example_node.cpp.o -c /home/enis/catkin_ws/src/serial_communication/src/serial_example_node.cpp

serial_communication/CMakeFiles/serial_node.dir/src/serial_example_node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serial_node.dir/src/serial_example_node.cpp.i"
	cd /home/enis/catkin_ws/build/serial_communication && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/enis/catkin_ws/src/serial_communication/src/serial_example_node.cpp > CMakeFiles/serial_node.dir/src/serial_example_node.cpp.i

serial_communication/CMakeFiles/serial_node.dir/src/serial_example_node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serial_node.dir/src/serial_example_node.cpp.s"
	cd /home/enis/catkin_ws/build/serial_communication && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/enis/catkin_ws/src/serial_communication/src/serial_example_node.cpp -o CMakeFiles/serial_node.dir/src/serial_example_node.cpp.s

serial_communication/CMakeFiles/serial_node.dir/src/serial_example_node.cpp.o.requires:

.PHONY : serial_communication/CMakeFiles/serial_node.dir/src/serial_example_node.cpp.o.requires

serial_communication/CMakeFiles/serial_node.dir/src/serial_example_node.cpp.o.provides: serial_communication/CMakeFiles/serial_node.dir/src/serial_example_node.cpp.o.requires
	$(MAKE) -f serial_communication/CMakeFiles/serial_node.dir/build.make serial_communication/CMakeFiles/serial_node.dir/src/serial_example_node.cpp.o.provides.build
.PHONY : serial_communication/CMakeFiles/serial_node.dir/src/serial_example_node.cpp.o.provides

serial_communication/CMakeFiles/serial_node.dir/src/serial_example_node.cpp.o.provides.build: serial_communication/CMakeFiles/serial_node.dir/src/serial_example_node.cpp.o


# Object files for target serial_node
serial_node_OBJECTS = \
"CMakeFiles/serial_node.dir/src/serial_example_node.cpp.o"

# External object files for target serial_node
serial_node_EXTERNAL_OBJECTS =

/home/enis/catkin_ws/devel/lib/serial_communication/serial_node: serial_communication/CMakeFiles/serial_node.dir/src/serial_example_node.cpp.o
/home/enis/catkin_ws/devel/lib/serial_communication/serial_node: serial_communication/CMakeFiles/serial_node.dir/build.make
/home/enis/catkin_ws/devel/lib/serial_communication/serial_node: serial_communication/CMakeFiles/serial_node.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/enis/catkin_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/enis/catkin_ws/devel/lib/serial_communication/serial_node"
	cd /home/enis/catkin_ws/build/serial_communication && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/serial_node.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
serial_communication/CMakeFiles/serial_node.dir/build: /home/enis/catkin_ws/devel/lib/serial_communication/serial_node

.PHONY : serial_communication/CMakeFiles/serial_node.dir/build

serial_communication/CMakeFiles/serial_node.dir/requires: serial_communication/CMakeFiles/serial_node.dir/src/serial_example_node.cpp.o.requires

.PHONY : serial_communication/CMakeFiles/serial_node.dir/requires

serial_communication/CMakeFiles/serial_node.dir/clean:
	cd /home/enis/catkin_ws/build/serial_communication && $(CMAKE_COMMAND) -P CMakeFiles/serial_node.dir/cmake_clean.cmake
.PHONY : serial_communication/CMakeFiles/serial_node.dir/clean

serial_communication/CMakeFiles/serial_node.dir/depend:
	cd /home/enis/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/enis/catkin_ws/src /home/enis/catkin_ws/src/serial_communication /home/enis/catkin_ws/build /home/enis/catkin_ws/build/serial_communication /home/enis/catkin_ws/build/serial_communication/CMakeFiles/serial_node.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : serial_communication/CMakeFiles/serial_node.dir/depend
