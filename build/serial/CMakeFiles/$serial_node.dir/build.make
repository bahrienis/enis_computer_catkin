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
include serial/CMakeFiles/$serial_node.dir/depend.make

# Include the progress variables for this target.
include serial/CMakeFiles/$serial_node.dir/progress.make

# Include the compile flags for this target's objects.
include serial/CMakeFiles/$serial_node.dir/flags.make

serial/CMakeFiles/$serial_node.dir/requires:

.PHONY : serial/CMakeFiles/$serial_node.dir/requires

serial/CMakeFiles/$serial_node.dir/clean:
	cd /home/enis/catkin_ws/build/serial && $(CMAKE_COMMAND) -P "CMakeFiles/\$$serial_node.dir/cmake_clean.cmake"
.PHONY : serial/CMakeFiles/$serial_node.dir/clean

serial/CMakeFiles/$serial_node.dir/depend:
	cd /home/enis/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/enis/catkin_ws/src /home/enis/catkin_ws/src/serial /home/enis/catkin_ws/build /home/enis/catkin_ws/build/serial "/home/enis/catkin_ws/build/serial/CMakeFiles/\$$serial_node.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : serial/CMakeFiles/$serial_node.dir/depend

