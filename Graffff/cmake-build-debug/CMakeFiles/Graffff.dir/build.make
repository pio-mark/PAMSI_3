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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Piotrek\CLionProjects\Graffff

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Piotrek\CLionProjects\Graffff\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Graffff.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Graffff.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Graffff.dir/flags.make

CMakeFiles/Graffff.dir/main.cpp.obj: CMakeFiles/Graffff.dir/flags.make
CMakeFiles/Graffff.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Piotrek\CLionProjects\Graffff\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Graffff.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Graffff.dir\main.cpp.obj -c C:\Users\Piotrek\CLionProjects\Graffff\main.cpp

CMakeFiles/Graffff.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Graffff.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Piotrek\CLionProjects\Graffff\main.cpp > CMakeFiles\Graffff.dir\main.cpp.i

CMakeFiles/Graffff.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Graffff.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Piotrek\CLionProjects\Graffff\main.cpp -o CMakeFiles\Graffff.dir\main.cpp.s

CMakeFiles/Graffff.dir/Graf.cpp.obj: CMakeFiles/Graffff.dir/flags.make
CMakeFiles/Graffff.dir/Graf.cpp.obj: ../Graf.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Piotrek\CLionProjects\Graffff\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Graffff.dir/Graf.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Graffff.dir\Graf.cpp.obj -c C:\Users\Piotrek\CLionProjects\Graffff\Graf.cpp

CMakeFiles/Graffff.dir/Graf.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Graffff.dir/Graf.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Piotrek\CLionProjects\Graffff\Graf.cpp > CMakeFiles\Graffff.dir\Graf.cpp.i

CMakeFiles/Graffff.dir/Graf.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Graffff.dir/Graf.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Piotrek\CLionProjects\Graffff\Graf.cpp -o CMakeFiles\Graffff.dir\Graf.cpp.s

# Object files for target Graffff
Graffff_OBJECTS = \
"CMakeFiles/Graffff.dir/main.cpp.obj" \
"CMakeFiles/Graffff.dir/Graf.cpp.obj"

# External object files for target Graffff
Graffff_EXTERNAL_OBJECTS =

Graffff.exe: CMakeFiles/Graffff.dir/main.cpp.obj
Graffff.exe: CMakeFiles/Graffff.dir/Graf.cpp.obj
Graffff.exe: CMakeFiles/Graffff.dir/build.make
Graffff.exe: CMakeFiles/Graffff.dir/linklibs.rsp
Graffff.exe: CMakeFiles/Graffff.dir/objects1.rsp
Graffff.exe: CMakeFiles/Graffff.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Piotrek\CLionProjects\Graffff\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Graffff.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Graffff.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Graffff.dir/build: Graffff.exe

.PHONY : CMakeFiles/Graffff.dir/build

CMakeFiles/Graffff.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Graffff.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Graffff.dir/clean

CMakeFiles/Graffff.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Piotrek\CLionProjects\Graffff C:\Users\Piotrek\CLionProjects\Graffff C:\Users\Piotrek\CLionProjects\Graffff\cmake-build-debug C:\Users\Piotrek\CLionProjects\Graffff\cmake-build-debug C:\Users\Piotrek\CLionProjects\Graffff\cmake-build-debug\CMakeFiles\Graffff.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Graffff.dir/depend

