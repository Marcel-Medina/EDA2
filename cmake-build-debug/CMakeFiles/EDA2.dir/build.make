# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/gori/Desktop/Enginyeria Matemàtica /2n trimestre/Estructura de Dades i Algoritmes/EDA2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/gori/Desktop/Enginyeria Matemàtica /2n trimestre/Estructura de Dades i Algoritmes/EDA2/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/EDA2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/EDA2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/EDA2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EDA2.dir/flags.make

CMakeFiles/EDA2.dir/main.c.o: CMakeFiles/EDA2.dir/flags.make
CMakeFiles/EDA2.dir/main.c.o: /Users/gori/Desktop/Enginyeria\ Matemàtica\ /2n\ trimestre/Estructura\ de\ Dades\ i\ Algoritmes/EDA2/main.c
CMakeFiles/EDA2.dir/main.c.o: CMakeFiles/EDA2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/gori/Desktop/Enginyeria Matemàtica /2n trimestre/Estructura de Dades i Algoritmes/EDA2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/EDA2.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/EDA2.dir/main.c.o -MF CMakeFiles/EDA2.dir/main.c.o.d -o CMakeFiles/EDA2.dir/main.c.o -c "/Users/gori/Desktop/Enginyeria Matemàtica /2n trimestre/Estructura de Dades i Algoritmes/EDA2/main.c"

CMakeFiles/EDA2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/EDA2.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/gori/Desktop/Enginyeria Matemàtica /2n trimestre/Estructura de Dades i Algoritmes/EDA2/main.c" > CMakeFiles/EDA2.dir/main.c.i

CMakeFiles/EDA2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/EDA2.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/gori/Desktop/Enginyeria Matemàtica /2n trimestre/Estructura de Dades i Algoritmes/EDA2/main.c" -o CMakeFiles/EDA2.dir/main.c.s

CMakeFiles/EDA2.dir/proves.c.o: CMakeFiles/EDA2.dir/flags.make
CMakeFiles/EDA2.dir/proves.c.o: /Users/gori/Desktop/Enginyeria\ Matemàtica\ /2n\ trimestre/Estructura\ de\ Dades\ i\ Algoritmes/EDA2/proves.c
CMakeFiles/EDA2.dir/proves.c.o: CMakeFiles/EDA2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/gori/Desktop/Enginyeria Matemàtica /2n trimestre/Estructura de Dades i Algoritmes/EDA2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/EDA2.dir/proves.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/EDA2.dir/proves.c.o -MF CMakeFiles/EDA2.dir/proves.c.o.d -o CMakeFiles/EDA2.dir/proves.c.o -c "/Users/gori/Desktop/Enginyeria Matemàtica /2n trimestre/Estructura de Dades i Algoritmes/EDA2/proves.c"

CMakeFiles/EDA2.dir/proves.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/EDA2.dir/proves.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/gori/Desktop/Enginyeria Matemàtica /2n trimestre/Estructura de Dades i Algoritmes/EDA2/proves.c" > CMakeFiles/EDA2.dir/proves.c.i

CMakeFiles/EDA2.dir/proves.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/EDA2.dir/proves.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/gori/Desktop/Enginyeria Matemàtica /2n trimestre/Estructura de Dades i Algoritmes/EDA2/proves.c" -o CMakeFiles/EDA2.dir/proves.c.s

# Object files for target EDA2
EDA2_OBJECTS = \
"CMakeFiles/EDA2.dir/main.c.o" \
"CMakeFiles/EDA2.dir/proves.c.o"

# External object files for target EDA2
EDA2_EXTERNAL_OBJECTS =

EDA2: CMakeFiles/EDA2.dir/main.c.o
EDA2: CMakeFiles/EDA2.dir/proves.c.o
EDA2: CMakeFiles/EDA2.dir/build.make
EDA2: CMakeFiles/EDA2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/gori/Desktop/Enginyeria Matemàtica /2n trimestre/Estructura de Dades i Algoritmes/EDA2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable EDA2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/EDA2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EDA2.dir/build: EDA2
.PHONY : CMakeFiles/EDA2.dir/build

CMakeFiles/EDA2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/EDA2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/EDA2.dir/clean

CMakeFiles/EDA2.dir/depend:
	cd "/Users/gori/Desktop/Enginyeria Matemàtica /2n trimestre/Estructura de Dades i Algoritmes/EDA2/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/gori/Desktop/Enginyeria Matemàtica /2n trimestre/Estructura de Dades i Algoritmes/EDA2" "/Users/gori/Desktop/Enginyeria Matemàtica /2n trimestre/Estructura de Dades i Algoritmes/EDA2" "/Users/gori/Desktop/Enginyeria Matemàtica /2n trimestre/Estructura de Dades i Algoritmes/EDA2/cmake-build-debug" "/Users/gori/Desktop/Enginyeria Matemàtica /2n trimestre/Estructura de Dades i Algoritmes/EDA2/cmake-build-debug" "/Users/gori/Desktop/Enginyeria Matemàtica /2n trimestre/Estructura de Dades i Algoritmes/EDA2/cmake-build-debug/CMakeFiles/EDA2.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/EDA2.dir/depend

