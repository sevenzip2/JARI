# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/user/JARI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/JARI/build

# Include any dependencies generated for this target.
include random/test/CMakeFiles/random_local_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include random/test/CMakeFiles/random_local_test.dir/compiler_depend.make

# Include the progress variables for this target.
include random/test/CMakeFiles/random_local_test.dir/progress.make

# Include the compile flags for this target's objects.
include random/test/CMakeFiles/random_local_test.dir/flags.make

random/test/CMakeFiles/random_local_test.dir/random_test.cpp.o: random/test/CMakeFiles/random_local_test.dir/flags.make
random/test/CMakeFiles/random_local_test.dir/random_test.cpp.o: /home/user/JARI/random/test/random_test.cpp
random/test/CMakeFiles/random_local_test.dir/random_test.cpp.o: random/test/CMakeFiles/random_local_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user/JARI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object random/test/CMakeFiles/random_local_test.dir/random_test.cpp.o"
	cd /home/user/JARI/build/random/test && /usr/sbin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT random/test/CMakeFiles/random_local_test.dir/random_test.cpp.o -MF CMakeFiles/random_local_test.dir/random_test.cpp.o.d -o CMakeFiles/random_local_test.dir/random_test.cpp.o -c /home/user/JARI/random/test/random_test.cpp

random/test/CMakeFiles/random_local_test.dir/random_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/random_local_test.dir/random_test.cpp.i"
	cd /home/user/JARI/build/random/test && /usr/sbin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/JARI/random/test/random_test.cpp > CMakeFiles/random_local_test.dir/random_test.cpp.i

random/test/CMakeFiles/random_local_test.dir/random_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/random_local_test.dir/random_test.cpp.s"
	cd /home/user/JARI/build/random/test && /usr/sbin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/JARI/random/test/random_test.cpp -o CMakeFiles/random_local_test.dir/random_test.cpp.s

# Object files for target random_local_test
random_local_test_OBJECTS = \
"CMakeFiles/random_local_test.dir/random_test.cpp.o"

# External object files for target random_local_test
random_local_test_EXTERNAL_OBJECTS =

random/test/random_local_test: random/test/CMakeFiles/random_local_test.dir/random_test.cpp.o
random/test/random_local_test: random/test/CMakeFiles/random_local_test.dir/build.make
random/test/random_local_test: random/test/CMakeFiles/random_local_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/user/JARI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable random_local_test"
	cd /home/user/JARI/build/random/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/random_local_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
random/test/CMakeFiles/random_local_test.dir/build: random/test/random_local_test
.PHONY : random/test/CMakeFiles/random_local_test.dir/build

random/test/CMakeFiles/random_local_test.dir/clean:
	cd /home/user/JARI/build/random/test && $(CMAKE_COMMAND) -P CMakeFiles/random_local_test.dir/cmake_clean.cmake
.PHONY : random/test/CMakeFiles/random_local_test.dir/clean

random/test/CMakeFiles/random_local_test.dir/depend:
	cd /home/user/JARI/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/JARI /home/user/JARI/random/test /home/user/JARI/build /home/user/JARI/build/random/test /home/user/JARI/build/random/test/CMakeFiles/random_local_test.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : random/test/CMakeFiles/random_local_test.dir/depend

