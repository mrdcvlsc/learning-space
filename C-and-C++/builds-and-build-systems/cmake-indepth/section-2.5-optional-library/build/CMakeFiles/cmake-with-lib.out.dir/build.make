# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/manaciel/Repo/cmake-indepth/section-2-optional-library

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/manaciel/Repo/cmake-indepth/section-2-optional-library/build

# Include any dependencies generated for this target.
include CMakeFiles/cmake-with-lib.out.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cmake-with-lib.out.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cmake-with-lib.out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cmake-with-lib.out.dir/flags.make

CMakeFiles/cmake-with-lib.out.dir/main.cpp.o: CMakeFiles/cmake-with-lib.out.dir/flags.make
CMakeFiles/cmake-with-lib.out.dir/main.cpp.o: ../main.cpp
CMakeFiles/cmake-with-lib.out.dir/main.cpp.o: CMakeFiles/cmake-with-lib.out.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/manaciel/Repo/cmake-indepth/section-2-optional-library/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cmake-with-lib.out.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cmake-with-lib.out.dir/main.cpp.o -MF CMakeFiles/cmake-with-lib.out.dir/main.cpp.o.d -o CMakeFiles/cmake-with-lib.out.dir/main.cpp.o -c /home/manaciel/Repo/cmake-indepth/section-2-optional-library/main.cpp

CMakeFiles/cmake-with-lib.out.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cmake-with-lib.out.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/manaciel/Repo/cmake-indepth/section-2-optional-library/main.cpp > CMakeFiles/cmake-with-lib.out.dir/main.cpp.i

CMakeFiles/cmake-with-lib.out.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cmake-with-lib.out.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/manaciel/Repo/cmake-indepth/section-2-optional-library/main.cpp -o CMakeFiles/cmake-with-lib.out.dir/main.cpp.s

# Object files for target cmake-with-lib.out
cmake__with__lib_out_OBJECTS = \
"CMakeFiles/cmake-with-lib.out.dir/main.cpp.o"

# External object files for target cmake-with-lib.out
cmake__with__lib_out_EXTERNAL_OBJECTS =

cmake-with-lib.out: CMakeFiles/cmake-with-lib.out.dir/main.cpp.o
cmake-with-lib.out: CMakeFiles/cmake-with-lib.out.dir/build.make
cmake-with-lib.out: MathFunctions/libmymath.a
cmake-with-lib.out: MathFunctions/libfoo.a
cmake-with-lib.out: CMakeFiles/cmake-with-lib.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/manaciel/Repo/cmake-indepth/section-2-optional-library/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cmake-with-lib.out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cmake-with-lib.out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cmake-with-lib.out.dir/build: cmake-with-lib.out
.PHONY : CMakeFiles/cmake-with-lib.out.dir/build

CMakeFiles/cmake-with-lib.out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cmake-with-lib.out.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cmake-with-lib.out.dir/clean

CMakeFiles/cmake-with-lib.out.dir/depend:
	cd /home/manaciel/Repo/cmake-indepth/section-2-optional-library/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/manaciel/Repo/cmake-indepth/section-2-optional-library /home/manaciel/Repo/cmake-indepth/section-2-optional-library /home/manaciel/Repo/cmake-indepth/section-2-optional-library/build /home/manaciel/Repo/cmake-indepth/section-2-optional-library/build /home/manaciel/Repo/cmake-indepth/section-2-optional-library/build/CMakeFiles/cmake-with-lib.out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cmake-with-lib.out.dir/depend

