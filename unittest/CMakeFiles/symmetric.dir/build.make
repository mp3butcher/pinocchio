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

# Include any dependencies generated for this target.
include unittest/CMakeFiles/symmetric.dir/depend.make

# Include the progress variables for this target.
include unittest/CMakeFiles/symmetric.dir/progress.make

# Include the compile flags for this target's objects.
include unittest/CMakeFiles/symmetric.dir/flags.make

unittest/CMakeFiles/symmetric.dir/symmetric.cpp.o: unittest/CMakeFiles/symmetric.dir/flags.make
unittest/CMakeFiles/symmetric.dir/symmetric.cpp.o: unittest/symmetric.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/xeul/SRC/Pinocchio/pinocchio/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object unittest/CMakeFiles/symmetric.dir/symmetric.cpp.o"
	cd /home/xeul/SRC/Pinocchio/pinocchio/unittest && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/symmetric.dir/symmetric.cpp.o -c /home/xeul/SRC/Pinocchio/pinocchio/unittest/symmetric.cpp

unittest/CMakeFiles/symmetric.dir/symmetric.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/symmetric.dir/symmetric.cpp.i"
	cd /home/xeul/SRC/Pinocchio/pinocchio/unittest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/xeul/SRC/Pinocchio/pinocchio/unittest/symmetric.cpp > CMakeFiles/symmetric.dir/symmetric.cpp.i

unittest/CMakeFiles/symmetric.dir/symmetric.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/symmetric.dir/symmetric.cpp.s"
	cd /home/xeul/SRC/Pinocchio/pinocchio/unittest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/xeul/SRC/Pinocchio/pinocchio/unittest/symmetric.cpp -o CMakeFiles/symmetric.dir/symmetric.cpp.s

unittest/CMakeFiles/symmetric.dir/symmetric.cpp.o.requires:
.PHONY : unittest/CMakeFiles/symmetric.dir/symmetric.cpp.o.requires

unittest/CMakeFiles/symmetric.dir/symmetric.cpp.o.provides: unittest/CMakeFiles/symmetric.dir/symmetric.cpp.o.requires
	$(MAKE) -f unittest/CMakeFiles/symmetric.dir/build.make unittest/CMakeFiles/symmetric.dir/symmetric.cpp.o.provides.build
.PHONY : unittest/CMakeFiles/symmetric.dir/symmetric.cpp.o.provides

unittest/CMakeFiles/symmetric.dir/symmetric.cpp.o.provides.build: unittest/CMakeFiles/symmetric.dir/symmetric.cpp.o

# Object files for target symmetric
symmetric_OBJECTS = \
"CMakeFiles/symmetric.dir/symmetric.cpp.o"

# External object files for target symmetric
symmetric_EXTERNAL_OBJECTS =

unittest/symmetric: unittest/CMakeFiles/symmetric.dir/symmetric.cpp.o
unittest/symmetric: unittest/CMakeFiles/symmetric.dir/build.make
unittest/symmetric: unittest/CMakeFiles/symmetric.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable symmetric"
	cd /home/xeul/SRC/Pinocchio/pinocchio/unittest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/symmetric.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
unittest/CMakeFiles/symmetric.dir/build: unittest/symmetric
.PHONY : unittest/CMakeFiles/symmetric.dir/build

unittest/CMakeFiles/symmetric.dir/requires: unittest/CMakeFiles/symmetric.dir/symmetric.cpp.o.requires
.PHONY : unittest/CMakeFiles/symmetric.dir/requires

unittest/CMakeFiles/symmetric.dir/clean:
	cd /home/xeul/SRC/Pinocchio/pinocchio/unittest && $(CMAKE_COMMAND) -P CMakeFiles/symmetric.dir/cmake_clean.cmake
.PHONY : unittest/CMakeFiles/symmetric.dir/clean

unittest/CMakeFiles/symmetric.dir/depend:
	cd /home/xeul/SRC/Pinocchio/pinocchio && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xeul/SRC/Pinocchio/pinocchio /home/xeul/SRC/Pinocchio/pinocchio/unittest /home/xeul/SRC/Pinocchio/pinocchio /home/xeul/SRC/Pinocchio/pinocchio/unittest /home/xeul/SRC/Pinocchio/pinocchio/unittest/CMakeFiles/symmetric.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : unittest/CMakeFiles/symmetric.dir/depend

