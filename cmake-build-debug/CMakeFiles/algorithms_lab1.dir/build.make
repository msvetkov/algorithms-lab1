# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\algorithms\algorithms-lab1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\algorithms\algorithms-lab1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/algorithms_lab1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/algorithms_lab1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/algorithms_lab1.dir/flags.make

CMakeFiles/algorithms_lab1.dir/main.cpp.obj: CMakeFiles/algorithms_lab1.dir/flags.make
CMakeFiles/algorithms_lab1.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\algorithms\algorithms-lab1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/algorithms_lab1.dir/main.cpp.obj"
	C:\PROGRA~1\mingw\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\algorithms_lab1.dir\main.cpp.obj -c C:\algorithms\algorithms-lab1\main.cpp

CMakeFiles/algorithms_lab1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/algorithms_lab1.dir/main.cpp.i"
	C:\PROGRA~1\mingw\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\algorithms\algorithms-lab1\main.cpp > CMakeFiles\algorithms_lab1.dir\main.cpp.i

CMakeFiles/algorithms_lab1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/algorithms_lab1.dir/main.cpp.s"
	C:\PROGRA~1\mingw\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\algorithms\algorithms-lab1\main.cpp -o CMakeFiles\algorithms_lab1.dir\main.cpp.s

# Object files for target algorithms_lab1
algorithms_lab1_OBJECTS = \
"CMakeFiles/algorithms_lab1.dir/main.cpp.obj"

# External object files for target algorithms_lab1
algorithms_lab1_EXTERNAL_OBJECTS =

algorithms_lab1.exe: CMakeFiles/algorithms_lab1.dir/main.cpp.obj
algorithms_lab1.exe: CMakeFiles/algorithms_lab1.dir/build.make
algorithms_lab1.exe: CMakeFiles/algorithms_lab1.dir/linklibs.rsp
algorithms_lab1.exe: CMakeFiles/algorithms_lab1.dir/objects1.rsp
algorithms_lab1.exe: CMakeFiles/algorithms_lab1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\algorithms\algorithms-lab1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable algorithms_lab1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\algorithms_lab1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/algorithms_lab1.dir/build: algorithms_lab1.exe

.PHONY : CMakeFiles/algorithms_lab1.dir/build

CMakeFiles/algorithms_lab1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\algorithms_lab1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/algorithms_lab1.dir/clean

CMakeFiles/algorithms_lab1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\algorithms\algorithms-lab1 C:\algorithms\algorithms-lab1 C:\algorithms\algorithms-lab1\cmake-build-debug C:\algorithms\algorithms-lab1\cmake-build-debug C:\algorithms\algorithms-lab1\cmake-build-debug\CMakeFiles\algorithms_lab1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/algorithms_lab1.dir/depend

