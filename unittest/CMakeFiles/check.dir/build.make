# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xeul/SRC/Pinocchio/pinocchio

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xeul/SRC/Pinocchio/pinocchio

# Utility rule file for check.

# Include the progress variables for this target.
include unittest/CMakeFiles/check.dir/progress.make

unittest/CMakeFiles/check:
	cd /home/xeul/SRC/Pinocchio/pinocchio/unittest && /usr/bin/ctest

check: unittest/CMakeFiles/check
check: unittest/CMakeFiles/check.dir/build.make
.PHONY : check

# Rule to build all files generated by this target.
unittest/CMakeFiles/check.dir/build: check
.PHONY : unittest/CMakeFiles/check.dir/build

unittest/CMakeFiles/check.dir/clean:
	cd /home/xeul/SRC/Pinocchio/pinocchio/unittest && $(CMAKE_COMMAND) -P CMakeFiles/check.dir/cmake_clean.cmake
.PHONY : unittest/CMakeFiles/check.dir/clean

unittest/CMakeFiles/check.dir/depend:
	cd /home/xeul/SRC/Pinocchio/pinocchio && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xeul/SRC/Pinocchio/pinocchio /home/xeul/SRC/Pinocchio/pinocchio/unittest /home/xeul/SRC/Pinocchio/pinocchio /home/xeul/SRC/Pinocchio/pinocchio/unittest /home/xeul/SRC/Pinocchio/pinocchio/unittest/CMakeFiles/check.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : unittest/CMakeFiles/check.dir/depend

