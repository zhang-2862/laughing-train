# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = "D:\Clion\CLion 2022.2.4\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Clion\CLion 2022.2.4\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\ClionProjects\laughing-train\C++Projects\niuke KY3 The number of divisors"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\ClionProjects\laughing-train\C++Projects\niuke KY3 The number of divisors\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/niuke_KY3_The_number_of_divisors_.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/niuke_KY3_The_number_of_divisors_.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/niuke_KY3_The_number_of_divisors_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/niuke_KY3_The_number_of_divisors_.dir/flags.make

CMakeFiles/niuke_KY3_The_number_of_divisors_.dir/main.cpp.obj: CMakeFiles/niuke_KY3_The_number_of_divisors_.dir/flags.make
CMakeFiles/niuke_KY3_The_number_of_divisors_.dir/main.cpp.obj: D:/ClionProjects/laughing-train/C++Projects/niuke\ KY3\ The\ number\ of\ divisors/main.cpp
CMakeFiles/niuke_KY3_The_number_of_divisors_.dir/main.cpp.obj: CMakeFiles/niuke_KY3_The_number_of_divisors_.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\ClionProjects\laughing-train\C++Projects\niuke KY3 The number of divisors\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/niuke_KY3_The_number_of_divisors_.dir/main.cpp.obj"
	"D:\Clion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/niuke_KY3_The_number_of_divisors_.dir/main.cpp.obj -MF CMakeFiles\niuke_KY3_The_number_of_divisors_.dir\main.cpp.obj.d -o CMakeFiles\niuke_KY3_The_number_of_divisors_.dir\main.cpp.obj -c "D:\ClionProjects\laughing-train\C++Projects\niuke KY3 The number of divisors\main.cpp"

CMakeFiles/niuke_KY3_The_number_of_divisors_.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/niuke_KY3_The_number_of_divisors_.dir/main.cpp.i"
	"D:\Clion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\ClionProjects\laughing-train\C++Projects\niuke KY3 The number of divisors\main.cpp" > CMakeFiles\niuke_KY3_The_number_of_divisors_.dir\main.cpp.i

CMakeFiles/niuke_KY3_The_number_of_divisors_.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/niuke_KY3_The_number_of_divisors_.dir/main.cpp.s"
	"D:\Clion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\ClionProjects\laughing-train\C++Projects\niuke KY3 The number of divisors\main.cpp" -o CMakeFiles\niuke_KY3_The_number_of_divisors_.dir\main.cpp.s

# Object files for target niuke_KY3_The_number_of_divisors_
niuke_KY3_The_number_of_divisors__OBJECTS = \
"CMakeFiles/niuke_KY3_The_number_of_divisors_.dir/main.cpp.obj"

# External object files for target niuke_KY3_The_number_of_divisors_
niuke_KY3_The_number_of_divisors__EXTERNAL_OBJECTS =

niuke_KY3_The_number_of_divisors_.exe: CMakeFiles/niuke_KY3_The_number_of_divisors_.dir/main.cpp.obj
niuke_KY3_The_number_of_divisors_.exe: CMakeFiles/niuke_KY3_The_number_of_divisors_.dir/build.make
niuke_KY3_The_number_of_divisors_.exe: CMakeFiles/niuke_KY3_The_number_of_divisors_.dir/linkLibs.rsp
niuke_KY3_The_number_of_divisors_.exe: CMakeFiles/niuke_KY3_The_number_of_divisors_.dir/objects1.rsp
niuke_KY3_The_number_of_divisors_.exe: CMakeFiles/niuke_KY3_The_number_of_divisors_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="D:\ClionProjects\laughing-train\C++Projects\niuke KY3 The number of divisors\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable niuke_KY3_The_number_of_divisors_.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\niuke_KY3_The_number_of_divisors_.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/niuke_KY3_The_number_of_divisors_.dir/build: niuke_KY3_The_number_of_divisors_.exe
.PHONY : CMakeFiles/niuke_KY3_The_number_of_divisors_.dir/build

CMakeFiles/niuke_KY3_The_number_of_divisors_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\niuke_KY3_The_number_of_divisors_.dir\cmake_clean.cmake
.PHONY : CMakeFiles/niuke_KY3_The_number_of_divisors_.dir/clean

CMakeFiles/niuke_KY3_The_number_of_divisors_.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\ClionProjects\laughing-train\C++Projects\niuke KY3 The number of divisors" "D:\ClionProjects\laughing-train\C++Projects\niuke KY3 The number of divisors" "D:\ClionProjects\laughing-train\C++Projects\niuke KY3 The number of divisors\cmake-build-debug" "D:\ClionProjects\laughing-train\C++Projects\niuke KY3 The number of divisors\cmake-build-debug" "D:\ClionProjects\laughing-train\C++Projects\niuke KY3 The number of divisors\cmake-build-debug\CMakeFiles\niuke_KY3_The_number_of_divisors_.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/niuke_KY3_The_number_of_divisors_.dir/depend
