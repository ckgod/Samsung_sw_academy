# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ckg/CLionProjects/BOJproject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ckg/CLionProjects/BOJproject/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BOJproject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BOJproject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BOJproject.dir/flags.make

CMakeFiles/BOJproject.dir/Divide_Conquer/ad_time.cpp.o: CMakeFiles/BOJproject.dir/flags.make
CMakeFiles/BOJproject.dir/Divide_Conquer/ad_time.cpp.o: ../Divide_Conquer/ad_time.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ckg/CLionProjects/BOJproject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BOJproject.dir/Divide_Conquer/ad_time.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BOJproject.dir/Divide_Conquer/ad_time.cpp.o -c /Users/ckg/CLionProjects/BOJproject/Divide_Conquer/ad_time.cpp

CMakeFiles/BOJproject.dir/Divide_Conquer/ad_time.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BOJproject.dir/Divide_Conquer/ad_time.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ckg/CLionProjects/BOJproject/Divide_Conquer/ad_time.cpp > CMakeFiles/BOJproject.dir/Divide_Conquer/ad_time.cpp.i

CMakeFiles/BOJproject.dir/Divide_Conquer/ad_time.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BOJproject.dir/Divide_Conquer/ad_time.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ckg/CLionProjects/BOJproject/Divide_Conquer/ad_time.cpp -o CMakeFiles/BOJproject.dir/Divide_Conquer/ad_time.cpp.s

# Object files for target BOJproject
BOJproject_OBJECTS = \
"CMakeFiles/BOJproject.dir/Divide_Conquer/ad_time.cpp.o"

# External object files for target BOJproject
BOJproject_EXTERNAL_OBJECTS =

BOJproject: CMakeFiles/BOJproject.dir/Divide_Conquer/ad_time.cpp.o
BOJproject: CMakeFiles/BOJproject.dir/build.make
BOJproject: CMakeFiles/BOJproject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ckg/CLionProjects/BOJproject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BOJproject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BOJproject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BOJproject.dir/build: BOJproject

.PHONY : CMakeFiles/BOJproject.dir/build

CMakeFiles/BOJproject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BOJproject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BOJproject.dir/clean

CMakeFiles/BOJproject.dir/depend:
	cd /Users/ckg/CLionProjects/BOJproject/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ckg/CLionProjects/BOJproject /Users/ckg/CLionProjects/BOJproject /Users/ckg/CLionProjects/BOJproject/cmake-build-debug /Users/ckg/CLionProjects/BOJproject/cmake-build-debug /Users/ckg/CLionProjects/BOJproject/cmake-build-debug/CMakeFiles/BOJproject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BOJproject.dir/depend

