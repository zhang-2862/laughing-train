# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Clion\CLion 2021.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Clion\CLion 2021.1.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\ClionProjects\C++Projects\pointer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\ClionProjects\C++Projects\pointer\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pointer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pointer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pointer.dir/flags.make

CMakeFiles/pointer.dir/main.cpp.obj: CMakeFiles/pointer.dir/flags.make
CMakeFiles/pointer.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ClionProjects\C++Projects\pointer\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pointer.dir/main.cpp.obj"
	"C:\PROGRA~2\Clion mingw\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pointer.dir\main.cpp.obj -c D:\ClionProjects\C++Projects\pointer\main.cpp

CMakeFiles/pointer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pointer.dir/main.cpp.i"
	"C:\PROGRA~2\Clion mingw\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ClionProjects\C++Projects\pointer\main.cpp > CMakeFiles\pointer.dir\main.cpp.i

CMakeFiles/pointer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pointer.dir/main.cpp.s"
	"C:\PROGRA~2\Clion mingw\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ClionProjects\C++Projects\pointer\main.cpp -o CMakeFiles\pointer.dir\main.cpp.s

# Object files for target pointer
pointer_OBJECTS = \
"CMakeFiles/pointer.dir/main.cpp.obj"

# External object files for target pointer
pointer_EXTERNAL_OBJECTS =

pointer.exe: CMakeFiles/pointer.dir/main.cpp.obj
pointer.exe: CMakeFiles/pointer.dir/build.make
pointer.exe: CMakeFiles/pointer.dir/linklibs.rsp
pointer.exe: CMakeFiles/pointer.dir/objects1.rsp
pointer.exe: CMakeFiles/pointer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\ClionProjects\C++Projects\pointer\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pointer.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\pointer.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pointer.dir/build: pointer.exe

.PHONY : CMakeFiles/pointer.dir/build

CMakeFiles/pointer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\pointer.dir\cmake_clean.cmake
.PHONY : CMakeFiles/pointer.dir/clean

CMakeFiles/pointer.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\ClionProjects\C++Projects\pointer D:\ClionProjects\C++Projects\pointer D:\ClionProjects\C++Projects\pointer\cmake-build-debug D:\ClionProjects\C++Projects\pointer\cmake-build-debug D:\ClionProjects\C++Projects\pointer\cmake-build-debug\CMakeFiles\pointer.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pointer.dir/depend

