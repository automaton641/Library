# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /home/automaton641/Library

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/automaton641/Library/build

# Include any dependencies generated for this target.
include CMakeFiles/Library.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Library.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Library.dir/flags.make

CMakeFiles/Library.dir/src/automaton641/library/lib_automaton_display.c.o: CMakeFiles/Library.dir/flags.make
CMakeFiles/Library.dir/src/automaton641/library/lib_automaton_display.c.o: ../src/automaton641/library/lib_automaton_display.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/automaton641/Library/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Library.dir/src/automaton641/library/lib_automaton_display.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Library.dir/src/automaton641/library/lib_automaton_display.c.o   -c /home/automaton641/Library/src/automaton641/library/lib_automaton_display.c

CMakeFiles/Library.dir/src/automaton641/library/lib_automaton_display.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Library.dir/src/automaton641/library/lib_automaton_display.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/automaton641/Library/src/automaton641/library/lib_automaton_display.c > CMakeFiles/Library.dir/src/automaton641/library/lib_automaton_display.c.i

CMakeFiles/Library.dir/src/automaton641/library/lib_automaton_display.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Library.dir/src/automaton641/library/lib_automaton_display.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/automaton641/Library/src/automaton641/library/lib_automaton_display.c -o CMakeFiles/Library.dir/src/automaton641/library/lib_automaton_display.c.s

CMakeFiles/Library.dir/src/automaton641/library/lib_color.c.o: CMakeFiles/Library.dir/flags.make
CMakeFiles/Library.dir/src/automaton641/library/lib_color.c.o: ../src/automaton641/library/lib_color.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/automaton641/Library/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Library.dir/src/automaton641/library/lib_color.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Library.dir/src/automaton641/library/lib_color.c.o   -c /home/automaton641/Library/src/automaton641/library/lib_color.c

CMakeFiles/Library.dir/src/automaton641/library/lib_color.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Library.dir/src/automaton641/library/lib_color.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/automaton641/Library/src/automaton641/library/lib_color.c > CMakeFiles/Library.dir/src/automaton641/library/lib_color.c.i

CMakeFiles/Library.dir/src/automaton641/library/lib_color.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Library.dir/src/automaton641/library/lib_color.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/automaton641/Library/src/automaton641/library/lib_color.c -o CMakeFiles/Library.dir/src/automaton641/library/lib_color.c.s

CMakeFiles/Library.dir/src/automaton641/library/lib_automaton.c.o: CMakeFiles/Library.dir/flags.make
CMakeFiles/Library.dir/src/automaton641/library/lib_automaton.c.o: ../src/automaton641/library/lib_automaton.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/automaton641/Library/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Library.dir/src/automaton641/library/lib_automaton.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Library.dir/src/automaton641/library/lib_automaton.c.o   -c /home/automaton641/Library/src/automaton641/library/lib_automaton.c

CMakeFiles/Library.dir/src/automaton641/library/lib_automaton.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Library.dir/src/automaton641/library/lib_automaton.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/automaton641/Library/src/automaton641/library/lib_automaton.c > CMakeFiles/Library.dir/src/automaton641/library/lib_automaton.c.i

CMakeFiles/Library.dir/src/automaton641/library/lib_automaton.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Library.dir/src/automaton641/library/lib_automaton.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/automaton641/Library/src/automaton641/library/lib_automaton.c -o CMakeFiles/Library.dir/src/automaton641/library/lib_automaton.c.s

CMakeFiles/Library.dir/src/automaton641/library/lib_array.c.o: CMakeFiles/Library.dir/flags.make
CMakeFiles/Library.dir/src/automaton641/library/lib_array.c.o: ../src/automaton641/library/lib_array.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/automaton641/Library/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Library.dir/src/automaton641/library/lib_array.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Library.dir/src/automaton641/library/lib_array.c.o   -c /home/automaton641/Library/src/automaton641/library/lib_array.c

CMakeFiles/Library.dir/src/automaton641/library/lib_array.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Library.dir/src/automaton641/library/lib_array.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/automaton641/Library/src/automaton641/library/lib_array.c > CMakeFiles/Library.dir/src/automaton641/library/lib_array.c.i

CMakeFiles/Library.dir/src/automaton641/library/lib_array.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Library.dir/src/automaton641/library/lib_array.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/automaton641/Library/src/automaton641/library/lib_array.c -o CMakeFiles/Library.dir/src/automaton641/library/lib_array.c.s

CMakeFiles/Library.dir/src/automaton641/library/lib_bidimensional.c.o: CMakeFiles/Library.dir/flags.make
CMakeFiles/Library.dir/src/automaton641/library/lib_bidimensional.c.o: ../src/automaton641/library/lib_bidimensional.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/automaton641/Library/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Library.dir/src/automaton641/library/lib_bidimensional.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Library.dir/src/automaton641/library/lib_bidimensional.c.o   -c /home/automaton641/Library/src/automaton641/library/lib_bidimensional.c

CMakeFiles/Library.dir/src/automaton641/library/lib_bidimensional.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Library.dir/src/automaton641/library/lib_bidimensional.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/automaton641/Library/src/automaton641/library/lib_bidimensional.c > CMakeFiles/Library.dir/src/automaton641/library/lib_bidimensional.c.i

CMakeFiles/Library.dir/src/automaton641/library/lib_bidimensional.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Library.dir/src/automaton641/library/lib_bidimensional.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/automaton641/Library/src/automaton641/library/lib_bidimensional.c -o CMakeFiles/Library.dir/src/automaton641/library/lib_bidimensional.c.s

CMakeFiles/Library.dir/src/automaton641/library/lib_general.c.o: CMakeFiles/Library.dir/flags.make
CMakeFiles/Library.dir/src/automaton641/library/lib_general.c.o: ../src/automaton641/library/lib_general.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/automaton641/Library/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Library.dir/src/automaton641/library/lib_general.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Library.dir/src/automaton641/library/lib_general.c.o   -c /home/automaton641/Library/src/automaton641/library/lib_general.c

CMakeFiles/Library.dir/src/automaton641/library/lib_general.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Library.dir/src/automaton641/library/lib_general.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/automaton641/Library/src/automaton641/library/lib_general.c > CMakeFiles/Library.dir/src/automaton641/library/lib_general.c.i

CMakeFiles/Library.dir/src/automaton641/library/lib_general.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Library.dir/src/automaton641/library/lib_general.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/automaton641/Library/src/automaton641/library/lib_general.c -o CMakeFiles/Library.dir/src/automaton641/library/lib_general.c.s

CMakeFiles/Library.dir/src/automaton641/library/lib_application.c.o: CMakeFiles/Library.dir/flags.make
CMakeFiles/Library.dir/src/automaton641/library/lib_application.c.o: ../src/automaton641/library/lib_application.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/automaton641/Library/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/Library.dir/src/automaton641/library/lib_application.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Library.dir/src/automaton641/library/lib_application.c.o   -c /home/automaton641/Library/src/automaton641/library/lib_application.c

CMakeFiles/Library.dir/src/automaton641/library/lib_application.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Library.dir/src/automaton641/library/lib_application.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/automaton641/Library/src/automaton641/library/lib_application.c > CMakeFiles/Library.dir/src/automaton641/library/lib_application.c.i

CMakeFiles/Library.dir/src/automaton641/library/lib_application.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Library.dir/src/automaton641/library/lib_application.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/automaton641/Library/src/automaton641/library/lib_application.c -o CMakeFiles/Library.dir/src/automaton641/library/lib_application.c.s

CMakeFiles/Library.dir/src/automaton641/library/lib_character.c.o: CMakeFiles/Library.dir/flags.make
CMakeFiles/Library.dir/src/automaton641/library/lib_character.c.o: ../src/automaton641/library/lib_character.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/automaton641/Library/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/Library.dir/src/automaton641/library/lib_character.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Library.dir/src/automaton641/library/lib_character.c.o   -c /home/automaton641/Library/src/automaton641/library/lib_character.c

CMakeFiles/Library.dir/src/automaton641/library/lib_character.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Library.dir/src/automaton641/library/lib_character.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/automaton641/Library/src/automaton641/library/lib_character.c > CMakeFiles/Library.dir/src/automaton641/library/lib_character.c.i

CMakeFiles/Library.dir/src/automaton641/library/lib_character.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Library.dir/src/automaton641/library/lib_character.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/automaton641/Library/src/automaton641/library/lib_character.c -o CMakeFiles/Library.dir/src/automaton641/library/lib_character.c.s

CMakeFiles/Library.dir/src/automaton641/library/lib_window.c.o: CMakeFiles/Library.dir/flags.make
CMakeFiles/Library.dir/src/automaton641/library/lib_window.c.o: ../src/automaton641/library/lib_window.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/automaton641/Library/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/Library.dir/src/automaton641/library/lib_window.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Library.dir/src/automaton641/library/lib_window.c.o   -c /home/automaton641/Library/src/automaton641/library/lib_window.c

CMakeFiles/Library.dir/src/automaton641/library/lib_window.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Library.dir/src/automaton641/library/lib_window.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/automaton641/Library/src/automaton641/library/lib_window.c > CMakeFiles/Library.dir/src/automaton641/library/lib_window.c.i

CMakeFiles/Library.dir/src/automaton641/library/lib_window.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Library.dir/src/automaton641/library/lib_window.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/automaton641/Library/src/automaton641/library/lib_window.c -o CMakeFiles/Library.dir/src/automaton641/library/lib_window.c.s

CMakeFiles/Library.dir/src/automaton641/library/lib_widget.c.o: CMakeFiles/Library.dir/flags.make
CMakeFiles/Library.dir/src/automaton641/library/lib_widget.c.o: ../src/automaton641/library/lib_widget.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/automaton641/Library/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/Library.dir/src/automaton641/library/lib_widget.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Library.dir/src/automaton641/library/lib_widget.c.o   -c /home/automaton641/Library/src/automaton641/library/lib_widget.c

CMakeFiles/Library.dir/src/automaton641/library/lib_widget.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Library.dir/src/automaton641/library/lib_widget.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/automaton641/Library/src/automaton641/library/lib_widget.c > CMakeFiles/Library.dir/src/automaton641/library/lib_widget.c.i

CMakeFiles/Library.dir/src/automaton641/library/lib_widget.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Library.dir/src/automaton641/library/lib_widget.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/automaton641/Library/src/automaton641/library/lib_widget.c -o CMakeFiles/Library.dir/src/automaton641/library/lib_widget.c.s

CMakeFiles/Library.dir/src/automaton641/library/lib_lang.c.o: CMakeFiles/Library.dir/flags.make
CMakeFiles/Library.dir/src/automaton641/library/lib_lang.c.o: ../src/automaton641/library/lib_lang.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/automaton641/Library/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/Library.dir/src/automaton641/library/lib_lang.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Library.dir/src/automaton641/library/lib_lang.c.o   -c /home/automaton641/Library/src/automaton641/library/lib_lang.c

CMakeFiles/Library.dir/src/automaton641/library/lib_lang.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Library.dir/src/automaton641/library/lib_lang.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/automaton641/Library/src/automaton641/library/lib_lang.c > CMakeFiles/Library.dir/src/automaton641/library/lib_lang.c.i

CMakeFiles/Library.dir/src/automaton641/library/lib_lang.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Library.dir/src/automaton641/library/lib_lang.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/automaton641/Library/src/automaton641/library/lib_lang.c -o CMakeFiles/Library.dir/src/automaton641/library/lib_lang.c.s

# Object files for target Library
Library_OBJECTS = \
"CMakeFiles/Library.dir/src/automaton641/library/lib_automaton_display.c.o" \
"CMakeFiles/Library.dir/src/automaton641/library/lib_color.c.o" \
"CMakeFiles/Library.dir/src/automaton641/library/lib_automaton.c.o" \
"CMakeFiles/Library.dir/src/automaton641/library/lib_array.c.o" \
"CMakeFiles/Library.dir/src/automaton641/library/lib_bidimensional.c.o" \
"CMakeFiles/Library.dir/src/automaton641/library/lib_general.c.o" \
"CMakeFiles/Library.dir/src/automaton641/library/lib_application.c.o" \
"CMakeFiles/Library.dir/src/automaton641/library/lib_character.c.o" \
"CMakeFiles/Library.dir/src/automaton641/library/lib_window.c.o" \
"CMakeFiles/Library.dir/src/automaton641/library/lib_widget.c.o" \
"CMakeFiles/Library.dir/src/automaton641/library/lib_lang.c.o"

# External object files for target Library
Library_EXTERNAL_OBJECTS =

libLibrary.a: CMakeFiles/Library.dir/src/automaton641/library/lib_automaton_display.c.o
libLibrary.a: CMakeFiles/Library.dir/src/automaton641/library/lib_color.c.o
libLibrary.a: CMakeFiles/Library.dir/src/automaton641/library/lib_automaton.c.o
libLibrary.a: CMakeFiles/Library.dir/src/automaton641/library/lib_array.c.o
libLibrary.a: CMakeFiles/Library.dir/src/automaton641/library/lib_bidimensional.c.o
libLibrary.a: CMakeFiles/Library.dir/src/automaton641/library/lib_general.c.o
libLibrary.a: CMakeFiles/Library.dir/src/automaton641/library/lib_application.c.o
libLibrary.a: CMakeFiles/Library.dir/src/automaton641/library/lib_character.c.o
libLibrary.a: CMakeFiles/Library.dir/src/automaton641/library/lib_window.c.o
libLibrary.a: CMakeFiles/Library.dir/src/automaton641/library/lib_widget.c.o
libLibrary.a: CMakeFiles/Library.dir/src/automaton641/library/lib_lang.c.o
libLibrary.a: CMakeFiles/Library.dir/build.make
libLibrary.a: CMakeFiles/Library.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/automaton641/Library/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking C static library libLibrary.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Library.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Library.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Library.dir/build: libLibrary.a

.PHONY : CMakeFiles/Library.dir/build

CMakeFiles/Library.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Library.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Library.dir/clean

CMakeFiles/Library.dir/depend:
	cd /home/automaton641/Library/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/automaton641/Library /home/automaton641/Library /home/automaton641/Library/build /home/automaton641/Library/build /home/automaton641/Library/build/CMakeFiles/Library.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Library.dir/depend
