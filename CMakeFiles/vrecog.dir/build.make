# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/pedroalves/Midiacom/cpp/vrecog

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pedroalves/Midiacom/cpp/vrecog

# Include any dependencies generated for this target.
include CMakeFiles/vrecog.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/vrecog.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vrecog.dir/flags.make

CMakeFiles/vrecog.dir/src/Main.cpp.o: CMakeFiles/vrecog.dir/flags.make
CMakeFiles/vrecog.dir/src/Main.cpp.o: src/Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pedroalves/Midiacom/cpp/vrecog/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/vrecog.dir/src/Main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vrecog.dir/src/Main.cpp.o -c /home/pedroalves/Midiacom/cpp/vrecog/src/Main.cpp

CMakeFiles/vrecog.dir/src/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vrecog.dir/src/Main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pedroalves/Midiacom/cpp/vrecog/src/Main.cpp > CMakeFiles/vrecog.dir/src/Main.cpp.i

CMakeFiles/vrecog.dir/src/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vrecog.dir/src/Main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pedroalves/Midiacom/cpp/vrecog/src/Main.cpp -o CMakeFiles/vrecog.dir/src/Main.cpp.s

CMakeFiles/vrecog.dir/src/Main.cpp.o.requires:

.PHONY : CMakeFiles/vrecog.dir/src/Main.cpp.o.requires

CMakeFiles/vrecog.dir/src/Main.cpp.o.provides: CMakeFiles/vrecog.dir/src/Main.cpp.o.requires
	$(MAKE) -f CMakeFiles/vrecog.dir/build.make CMakeFiles/vrecog.dir/src/Main.cpp.o.provides.build
.PHONY : CMakeFiles/vrecog.dir/src/Main.cpp.o.provides

CMakeFiles/vrecog.dir/src/Main.cpp.o.provides.build: CMakeFiles/vrecog.dir/src/Main.cpp.o


# Object files for target vrecog
vrecog_OBJECTS = \
"CMakeFiles/vrecog.dir/src/Main.cpp.o"

# External object files for target vrecog
vrecog_EXTERNAL_OBJECTS =

vrecog: CMakeFiles/vrecog.dir/src/Main.cpp.o
vrecog: CMakeFiles/vrecog.dir/build.make
vrecog: CMakeFiles/vrecog.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pedroalves/Midiacom/cpp/vrecog/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable vrecog"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vrecog.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vrecog.dir/build: vrecog

.PHONY : CMakeFiles/vrecog.dir/build

CMakeFiles/vrecog.dir/requires: CMakeFiles/vrecog.dir/src/Main.cpp.o.requires

.PHONY : CMakeFiles/vrecog.dir/requires

CMakeFiles/vrecog.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vrecog.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vrecog.dir/clean

CMakeFiles/vrecog.dir/depend:
	cd /home/pedroalves/Midiacom/cpp/vrecog && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pedroalves/Midiacom/cpp/vrecog /home/pedroalves/Midiacom/cpp/vrecog /home/pedroalves/Midiacom/cpp/vrecog /home/pedroalves/Midiacom/cpp/vrecog /home/pedroalves/Midiacom/cpp/vrecog/CMakeFiles/vrecog.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vrecog.dir/depend

