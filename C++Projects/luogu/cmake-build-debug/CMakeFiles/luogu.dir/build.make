# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = "D:\Clion\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Clion\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\ClionProjects\C++Projects\luogu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\ClionProjects\C++Projects\luogu\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/luogu.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/luogu.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/luogu.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/luogu.dir/flags.make

CMakeFiles/luogu.dir/main.cpp.obj: CMakeFiles/luogu.dir/flags.make
CMakeFiles/luogu.dir/main.cpp.obj: ../main.cpp
CMakeFiles/luogu.dir/main.cpp.obj: CMakeFiles/luogu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ClionProjects\C++Projects\luogu\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/luogu.dir/main.cpp.obj"
	"D:\Clion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/luogu.dir/main.cpp.obj -MF CMakeFiles\luogu.dir\main.cpp.obj.d -o CMakeFiles\luogu.dir\main.cpp.obj -c D:\ClionProjects\C++Projects\luogu\main.cpp

CMakeFiles/luogu.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/luogu.dir/main.cpp.i"
	"D:\Clion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ClionProjects\C++Projects\luogu\main.cpp > CMakeFiles\luogu.dir\main.cpp.i

CMakeFiles/luogu.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/luogu.dir/main.cpp.s"
	"D:\Clion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ClionProjects\C++Projects\luogu\main.cpp -o CMakeFiles\luogu.dir\main.cpp.s

# Object files for target luogu
luogu_OBJECTS = \
"CMakeFiles/luogu.dir/main.cpp.obj"

# External object files for target luogu
luogu_EXTERNAL_OBJECTS =

luogu.exe: CMakeFiles/luogu.dir/main.cpp.obj
luogu.exe: CMakeFiles/luogu.dir/build.make
luogu.exe: CMakeFiles/luogu.dir/linklibs.rsp
luogu.exe: CMakeFiles/luogu.dir/objects1.rsp
luogu.exe: CMakeFiles/luogu.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\ClionProjects\C++Projects\luogu\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable luogu.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\luogu.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/luogu.dir/build: luogu.exe
.PHONY : CMakeFiles/luogu.dir/build

CMakeFiles/luogu.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\luogu.dir\cmake_clean.cmake
.PHONY : CMakeFiles/luogu.dir/clean

CMakeFiles/luogu.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\ClionProjects\C++Projects\luogu D:\ClionProjects\C++Projects\luogu D:\ClionProjects\C++Projects\luogu\cmake-build-debug D:\ClionProjects\C++Projects\luogu\cmake-build-debug D:\ClionProjects\C++Projects\luogu\cmake-build-debug\CMakeFiles\luogu.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/luogu.dir/depend

