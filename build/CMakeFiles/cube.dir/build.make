# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/docker/Documents/tucil_dai

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/docker/Documents/tucil_dai/build

# Include any dependencies generated for this target.
include CMakeFiles/cube.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cube.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cube.dir/flags.make

CMakeFiles/cube.dir/src/main.cpp.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/docker/Documents/tucil_dai/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cube.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cube.dir/src/main.cpp.o -c /home/docker/Documents/tucil_dai/src/main.cpp

CMakeFiles/cube.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cube.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/docker/Documents/tucil_dai/src/main.cpp > CMakeFiles/cube.dir/src/main.cpp.i

CMakeFiles/cube.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cube.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/docker/Documents/tucil_dai/src/main.cpp -o CMakeFiles/cube.dir/src/main.cpp.s

CMakeFiles/cube.dir/src/open_gl_utils.cpp.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/src/open_gl_utils.cpp.o: ../src/open_gl_utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/docker/Documents/tucil_dai/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cube.dir/src/open_gl_utils.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cube.dir/src/open_gl_utils.cpp.o -c /home/docker/Documents/tucil_dai/src/open_gl_utils.cpp

CMakeFiles/cube.dir/src/open_gl_utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cube.dir/src/open_gl_utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/docker/Documents/tucil_dai/src/open_gl_utils.cpp > CMakeFiles/cube.dir/src/open_gl_utils.cpp.i

CMakeFiles/cube.dir/src/open_gl_utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cube.dir/src/open_gl_utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/docker/Documents/tucil_dai/src/open_gl_utils.cpp -o CMakeFiles/cube.dir/src/open_gl_utils.cpp.s

CMakeFiles/cube.dir/src/steep_ascent.cpp.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/src/steep_ascent.cpp.o: ../src/steep_ascent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/docker/Documents/tucil_dai/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cube.dir/src/steep_ascent.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cube.dir/src/steep_ascent.cpp.o -c /home/docker/Documents/tucil_dai/src/steep_ascent.cpp

CMakeFiles/cube.dir/src/steep_ascent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cube.dir/src/steep_ascent.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/docker/Documents/tucil_dai/src/steep_ascent.cpp > CMakeFiles/cube.dir/src/steep_ascent.cpp.i

CMakeFiles/cube.dir/src/steep_ascent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cube.dir/src/steep_ascent.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/docker/Documents/tucil_dai/src/steep_ascent.cpp -o CMakeFiles/cube.dir/src/steep_ascent.cpp.s

CMakeFiles/cube.dir/src/cube.cpp.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/src/cube.cpp.o: ../src/cube.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/docker/Documents/tucil_dai/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/cube.dir/src/cube.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cube.dir/src/cube.cpp.o -c /home/docker/Documents/tucil_dai/src/cube.cpp

CMakeFiles/cube.dir/src/cube.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cube.dir/src/cube.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/docker/Documents/tucil_dai/src/cube.cpp > CMakeFiles/cube.dir/src/cube.cpp.i

CMakeFiles/cube.dir/src/cube.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cube.dir/src/cube.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/docker/Documents/tucil_dai/src/cube.cpp -o CMakeFiles/cube.dir/src/cube.cpp.s

CMakeFiles/cube.dir/src/side_ways.cpp.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/src/side_ways.cpp.o: ../src/side_ways.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/docker/Documents/tucil_dai/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/cube.dir/src/side_ways.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cube.dir/src/side_ways.cpp.o -c /home/docker/Documents/tucil_dai/src/side_ways.cpp

CMakeFiles/cube.dir/src/side_ways.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cube.dir/src/side_ways.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/docker/Documents/tucil_dai/src/side_ways.cpp > CMakeFiles/cube.dir/src/side_ways.cpp.i

CMakeFiles/cube.dir/src/side_ways.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cube.dir/src/side_ways.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/docker/Documents/tucil_dai/src/side_ways.cpp -o CMakeFiles/cube.dir/src/side_ways.cpp.s

CMakeFiles/cube.dir/src/random_restart.cpp.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/src/random_restart.cpp.o: ../src/random_restart.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/docker/Documents/tucil_dai/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/cube.dir/src/random_restart.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cube.dir/src/random_restart.cpp.o -c /home/docker/Documents/tucil_dai/src/random_restart.cpp

CMakeFiles/cube.dir/src/random_restart.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cube.dir/src/random_restart.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/docker/Documents/tucil_dai/src/random_restart.cpp > CMakeFiles/cube.dir/src/random_restart.cpp.i

CMakeFiles/cube.dir/src/random_restart.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cube.dir/src/random_restart.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/docker/Documents/tucil_dai/src/random_restart.cpp -o CMakeFiles/cube.dir/src/random_restart.cpp.s

CMakeFiles/cube.dir/src/stochastic.cpp.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/src/stochastic.cpp.o: ../src/stochastic.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/docker/Documents/tucil_dai/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/cube.dir/src/stochastic.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cube.dir/src/stochastic.cpp.o -c /home/docker/Documents/tucil_dai/src/stochastic.cpp

CMakeFiles/cube.dir/src/stochastic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cube.dir/src/stochastic.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/docker/Documents/tucil_dai/src/stochastic.cpp > CMakeFiles/cube.dir/src/stochastic.cpp.i

CMakeFiles/cube.dir/src/stochastic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cube.dir/src/stochastic.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/docker/Documents/tucil_dai/src/stochastic.cpp -o CMakeFiles/cube.dir/src/stochastic.cpp.s

CMakeFiles/cube.dir/src/simulated_annealing.cpp.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/src/simulated_annealing.cpp.o: ../src/simulated_annealing.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/docker/Documents/tucil_dai/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/cube.dir/src/simulated_annealing.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cube.dir/src/simulated_annealing.cpp.o -c /home/docker/Documents/tucil_dai/src/simulated_annealing.cpp

CMakeFiles/cube.dir/src/simulated_annealing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cube.dir/src/simulated_annealing.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/docker/Documents/tucil_dai/src/simulated_annealing.cpp > CMakeFiles/cube.dir/src/simulated_annealing.cpp.i

CMakeFiles/cube.dir/src/simulated_annealing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cube.dir/src/simulated_annealing.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/docker/Documents/tucil_dai/src/simulated_annealing.cpp -o CMakeFiles/cube.dir/src/simulated_annealing.cpp.s

CMakeFiles/cube.dir/src/genetic_algorithm.cpp.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/src/genetic_algorithm.cpp.o: ../src/genetic_algorithm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/docker/Documents/tucil_dai/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/cube.dir/src/genetic_algorithm.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cube.dir/src/genetic_algorithm.cpp.o -c /home/docker/Documents/tucil_dai/src/genetic_algorithm.cpp

CMakeFiles/cube.dir/src/genetic_algorithm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cube.dir/src/genetic_algorithm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/docker/Documents/tucil_dai/src/genetic_algorithm.cpp > CMakeFiles/cube.dir/src/genetic_algorithm.cpp.i

CMakeFiles/cube.dir/src/genetic_algorithm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cube.dir/src/genetic_algorithm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/docker/Documents/tucil_dai/src/genetic_algorithm.cpp -o CMakeFiles/cube.dir/src/genetic_algorithm.cpp.s

# Object files for target cube
cube_OBJECTS = \
"CMakeFiles/cube.dir/src/main.cpp.o" \
"CMakeFiles/cube.dir/src/open_gl_utils.cpp.o" \
"CMakeFiles/cube.dir/src/steep_ascent.cpp.o" \
"CMakeFiles/cube.dir/src/cube.cpp.o" \
"CMakeFiles/cube.dir/src/side_ways.cpp.o" \
"CMakeFiles/cube.dir/src/random_restart.cpp.o" \
"CMakeFiles/cube.dir/src/stochastic.cpp.o" \
"CMakeFiles/cube.dir/src/simulated_annealing.cpp.o" \
"CMakeFiles/cube.dir/src/genetic_algorithm.cpp.o"

# External object files for target cube
cube_EXTERNAL_OBJECTS =

cube: CMakeFiles/cube.dir/src/main.cpp.o
cube: CMakeFiles/cube.dir/src/open_gl_utils.cpp.o
cube: CMakeFiles/cube.dir/src/steep_ascent.cpp.o
cube: CMakeFiles/cube.dir/src/cube.cpp.o
cube: CMakeFiles/cube.dir/src/side_ways.cpp.o
cube: CMakeFiles/cube.dir/src/random_restart.cpp.o
cube: CMakeFiles/cube.dir/src/stochastic.cpp.o
cube: CMakeFiles/cube.dir/src/simulated_annealing.cpp.o
cube: CMakeFiles/cube.dir/src/genetic_algorithm.cpp.o
cube: CMakeFiles/cube.dir/build.make
cube: /usr/lib/x86_64-linux-gnu/libGL.so
cube: /usr/lib/x86_64-linux-gnu/libGLU.so
cube: /usr/lib/x86_64-linux-gnu/libglut.so
cube: /usr/lib/x86_64-linux-gnu/libXmu.so
cube: /usr/lib/x86_64-linux-gnu/libXi.so
cube: CMakeFiles/cube.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/docker/Documents/tucil_dai/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable cube"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cube.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cube.dir/build: cube

.PHONY : CMakeFiles/cube.dir/build

CMakeFiles/cube.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cube.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cube.dir/clean

CMakeFiles/cube.dir/depend:
	cd /home/docker/Documents/tucil_dai/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/docker/Documents/tucil_dai /home/docker/Documents/tucil_dai /home/docker/Documents/tucil_dai/build /home/docker/Documents/tucil_dai/build /home/docker/Documents/tucil_dai/build/CMakeFiles/cube.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cube.dir/depend

