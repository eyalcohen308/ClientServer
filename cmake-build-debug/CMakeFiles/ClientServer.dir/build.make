# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /snap/clion/57/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/57/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/eyal/CLionProjects/ClientServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/eyal/CLionProjects/ClientServer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ClientServer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ClientServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ClientServer.dir/flags.make

CMakeFiles/ClientServer.dir/main.cpp.o: CMakeFiles/ClientServer.dir/flags.make
CMakeFiles/ClientServer.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eyal/CLionProjects/ClientServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ClientServer.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ClientServer.dir/main.cpp.o -c /home/eyal/CLionProjects/ClientServer/main.cpp

CMakeFiles/ClientServer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ClientServer.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eyal/CLionProjects/ClientServer/main.cpp > CMakeFiles/ClientServer.dir/main.cpp.i

CMakeFiles/ClientServer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ClientServer.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eyal/CLionProjects/ClientServer/main.cpp -o CMakeFiles/ClientServer.dir/main.cpp.s

# Object files for target ClientServer
ClientServer_OBJECTS = \
"CMakeFiles/ClientServer.dir/main.cpp.o"

# External object files for target ClientServer
ClientServer_EXTERNAL_OBJECTS =

ClientServer: CMakeFiles/ClientServer.dir/main.cpp.o
ClientServer: CMakeFiles/ClientServer.dir/build.make
ClientServer: CMakeFiles/ClientServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/eyal/CLionProjects/ClientServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ClientServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ClientServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ClientServer.dir/build: ClientServer

.PHONY : CMakeFiles/ClientServer.dir/build

CMakeFiles/ClientServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ClientServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ClientServer.dir/clean

CMakeFiles/ClientServer.dir/depend:
	cd /home/eyal/CLionProjects/ClientServer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eyal/CLionProjects/ClientServer /home/eyal/CLionProjects/ClientServer /home/eyal/CLionProjects/ClientServer/cmake-build-debug /home/eyal/CLionProjects/ClientServer/cmake-build-debug /home/eyal/CLionProjects/ClientServer/cmake-build-debug/CMakeFiles/ClientServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ClientServer.dir/depend

