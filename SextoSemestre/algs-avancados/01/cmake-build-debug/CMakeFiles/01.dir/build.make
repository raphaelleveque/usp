# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/raphaelleveque/Desktop/cs/usp/SextoSemestre/algs-avancados/01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/raphaelleveque/Desktop/cs/usp/SextoSemestre/algs-avancados/01/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/01.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/01.dir/flags.make

CMakeFiles/01.dir/buildStairs.cpp.o: CMakeFiles/01.dir/flags.make
CMakeFiles/01.dir/buildStairs.cpp.o: ../buildStairs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/raphaelleveque/Desktop/cs/usp/SextoSemestre/algs-avancados/01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/01.dir/buildStairs.cpp.o"
	/opt/homebrew/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/01.dir/buildStairs.cpp.o -c /Users/raphaelleveque/Desktop/cs/usp/SextoSemestre/algs-avancados/01/buildStairs.cpp

CMakeFiles/01.dir/buildStairs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/01.dir/buildStairs.cpp.i"
	/opt/homebrew/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/raphaelleveque/Desktop/cs/usp/SextoSemestre/algs-avancados/01/buildStairs.cpp > CMakeFiles/01.dir/buildStairs.cpp.i

CMakeFiles/01.dir/buildStairs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/01.dir/buildStairs.cpp.s"
	/opt/homebrew/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/raphaelleveque/Desktop/cs/usp/SextoSemestre/algs-avancados/01/buildStairs.cpp -o CMakeFiles/01.dir/buildStairs.cpp.s

# Object files for target 01
01_OBJECTS = \
"CMakeFiles/01.dir/buildStairs.cpp.o"

# External object files for target 01
01_EXTERNAL_OBJECTS =

01: CMakeFiles/01.dir/buildStairs.cpp.o
01: CMakeFiles/01.dir/build.make
01: CMakeFiles/01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/raphaelleveque/Desktop/cs/usp/SextoSemestre/algs-avancados/01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 01"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/01.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/01.dir/build: 01
.PHONY : CMakeFiles/01.dir/build

CMakeFiles/01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/01.dir/cmake_clean.cmake
.PHONY : CMakeFiles/01.dir/clean

CMakeFiles/01.dir/depend:
	cd /Users/raphaelleveque/Desktop/cs/usp/SextoSemestre/algs-avancados/01/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/raphaelleveque/Desktop/cs/usp/SextoSemestre/algs-avancados/01 /Users/raphaelleveque/Desktop/cs/usp/SextoSemestre/algs-avancados/01 /Users/raphaelleveque/Desktop/cs/usp/SextoSemestre/algs-avancados/01/cmake-build-debug /Users/raphaelleveque/Desktop/cs/usp/SextoSemestre/algs-avancados/01/cmake-build-debug /Users/raphaelleveque/Desktop/cs/usp/SextoSemestre/algs-avancados/01/cmake-build-debug/CMakeFiles/01.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/01.dir/depend

