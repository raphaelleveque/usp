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
CMAKE_SOURCE_DIR = /Users/raphaelleveque/Desktop/cs/usp/SextoSemestre/algs-avancados/05

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/raphaelleveque/Desktop/cs/usp/SextoSemestre/algs-avancados/05/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/05.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/05.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/05.dir/flags.make

CMakeFiles/05.dir/RemovingDigits.cpp.o: CMakeFiles/05.dir/flags.make
CMakeFiles/05.dir/RemovingDigits.cpp.o: ../RemovingDigits.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/raphaelleveque/Desktop/cs/usp/SextoSemestre/algs-avancados/05/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/05.dir/RemovingDigits.cpp.o"
	/opt/homebrew/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/05.dir/RemovingDigits.cpp.o -c /Users/raphaelleveque/Desktop/cs/usp/SextoSemestre/algs-avancados/05/RemovingDigits.cpp

CMakeFiles/05.dir/RemovingDigits.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/05.dir/RemovingDigits.cpp.i"
	/opt/homebrew/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/raphaelleveque/Desktop/cs/usp/SextoSemestre/algs-avancados/05/RemovingDigits.cpp > CMakeFiles/05.dir/RemovingDigits.cpp.i

CMakeFiles/05.dir/RemovingDigits.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/05.dir/RemovingDigits.cpp.s"
	/opt/homebrew/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/raphaelleveque/Desktop/cs/usp/SextoSemestre/algs-avancados/05/RemovingDigits.cpp -o CMakeFiles/05.dir/RemovingDigits.cpp.s

# Object files for target 05
05_OBJECTS = \
"CMakeFiles/05.dir/RemovingDigits.cpp.o"

# External object files for target 05
05_EXTERNAL_OBJECTS =

05: CMakeFiles/05.dir/RemovingDigits.cpp.o
05: CMakeFiles/05.dir/build.make
05: CMakeFiles/05.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/raphaelleveque/Desktop/cs/usp/SextoSemestre/algs-avancados/05/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 05"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/05.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/05.dir/build: 05
.PHONY : CMakeFiles/05.dir/build

CMakeFiles/05.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/05.dir/cmake_clean.cmake
.PHONY : CMakeFiles/05.dir/clean

CMakeFiles/05.dir/depend:
	cd /Users/raphaelleveque/Desktop/cs/usp/SextoSemestre/algs-avancados/05/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/raphaelleveque/Desktop/cs/usp/SextoSemestre/algs-avancados/05 /Users/raphaelleveque/Desktop/cs/usp/SextoSemestre/algs-avancados/05 /Users/raphaelleveque/Desktop/cs/usp/SextoSemestre/algs-avancados/05/cmake-build-debug /Users/raphaelleveque/Desktop/cs/usp/SextoSemestre/algs-avancados/05/cmake-build-debug /Users/raphaelleveque/Desktop/cs/usp/SextoSemestre/algs-avancados/05/cmake-build-debug/CMakeFiles/05.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/05.dir/depend

