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
CMAKE_SOURCE_DIR = /home/manaciel/Repo/cmake-indepth/section-3-library-usesage-requirement

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/manaciel/Repo/cmake-indepth/section-3-library-usesage-requirement/build

# Include any dependencies generated for this target.
include MathFunctions/CMakeFiles/foo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include MathFunctions/CMakeFiles/foo.dir/compiler_depend.make

# Include the progress variables for this target.
include MathFunctions/CMakeFiles/foo.dir/progress.make

# Include the compile flags for this target's objects.
include MathFunctions/CMakeFiles/foo.dir/flags.make

MathFunctions/CMakeFiles/foo.dir/Foo.cpp.o: MathFunctions/CMakeFiles/foo.dir/flags.make
MathFunctions/CMakeFiles/foo.dir/Foo.cpp.o: ../MathFunctions/Foo.cpp
MathFunctions/CMakeFiles/foo.dir/Foo.cpp.o: MathFunctions/CMakeFiles/foo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/manaciel/Repo/cmake-indepth/section-3-library-usesage-requirement/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object MathFunctions/CMakeFiles/foo.dir/Foo.cpp.o"
	cd /home/manaciel/Repo/cmake-indepth/section-3-library-usesage-requirement/build/MathFunctions && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT MathFunctions/CMakeFiles/foo.dir/Foo.cpp.o -MF CMakeFiles/foo.dir/Foo.cpp.o.d -o CMakeFiles/foo.dir/Foo.cpp.o -c /home/manaciel/Repo/cmake-indepth/section-3-library-usesage-requirement/MathFunctions/Foo.cpp

MathFunctions/CMakeFiles/foo.dir/Foo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/foo.dir/Foo.cpp.i"
	cd /home/manaciel/Repo/cmake-indepth/section-3-library-usesage-requirement/build/MathFunctions && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/manaciel/Repo/cmake-indepth/section-3-library-usesage-requirement/MathFunctions/Foo.cpp > CMakeFiles/foo.dir/Foo.cpp.i

MathFunctions/CMakeFiles/foo.dir/Foo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/foo.dir/Foo.cpp.s"
	cd /home/manaciel/Repo/cmake-indepth/section-3-library-usesage-requirement/build/MathFunctions && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/manaciel/Repo/cmake-indepth/section-3-library-usesage-requirement/MathFunctions/Foo.cpp -o CMakeFiles/foo.dir/Foo.cpp.s

# Object files for target foo
foo_OBJECTS = \
"CMakeFiles/foo.dir/Foo.cpp.o"

# External object files for target foo
foo_EXTERNAL_OBJECTS =

MathFunctions/libfoo.a: MathFunctions/CMakeFiles/foo.dir/Foo.cpp.o
MathFunctions/libfoo.a: MathFunctions/CMakeFiles/foo.dir/build.make
MathFunctions/libfoo.a: MathFunctions/CMakeFiles/foo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/manaciel/Repo/cmake-indepth/section-3-library-usesage-requirement/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libfoo.a"
	cd /home/manaciel/Repo/cmake-indepth/section-3-library-usesage-requirement/build/MathFunctions && $(CMAKE_COMMAND) -P CMakeFiles/foo.dir/cmake_clean_target.cmake
	cd /home/manaciel/Repo/cmake-indepth/section-3-library-usesage-requirement/build/MathFunctions && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/foo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
MathFunctions/CMakeFiles/foo.dir/build: MathFunctions/libfoo.a
.PHONY : MathFunctions/CMakeFiles/foo.dir/build

MathFunctions/CMakeFiles/foo.dir/clean:
	cd /home/manaciel/Repo/cmake-indepth/section-3-library-usesage-requirement/build/MathFunctions && $(CMAKE_COMMAND) -P CMakeFiles/foo.dir/cmake_clean.cmake
.PHONY : MathFunctions/CMakeFiles/foo.dir/clean

MathFunctions/CMakeFiles/foo.dir/depend:
	cd /home/manaciel/Repo/cmake-indepth/section-3-library-usesage-requirement/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/manaciel/Repo/cmake-indepth/section-3-library-usesage-requirement /home/manaciel/Repo/cmake-indepth/section-3-library-usesage-requirement/MathFunctions /home/manaciel/Repo/cmake-indepth/section-3-library-usesage-requirement/build /home/manaciel/Repo/cmake-indepth/section-3-library-usesage-requirement/build/MathFunctions /home/manaciel/Repo/cmake-indepth/section-3-library-usesage-requirement/build/MathFunctions/CMakeFiles/foo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : MathFunctions/CMakeFiles/foo.dir/depend

