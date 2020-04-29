
cmake_minimum_required(VERSION 3.13.4)
project (TheProject)
set( library_sources
./src/automaton641/library/lib_character.h
./src/automaton641/library/lib_automaton_display.c
./src/automaton641/library/lib_color.c
./src/automaton641/library/lib_automaton.c
./src/automaton641/library/lib_array.c
./src/automaton641/library/lib_window.h
./src/automaton641/library/lib_bidimensional.c
./src/automaton641/library/lib_automaton.h
./src/automaton641/library/lib_lang.h
./src/automaton641/library/lib.h
./src/automaton641/library/lib_color.h
./src/automaton641/library/lib_array.h
./src/automaton641/library/lib_general.c
./src/automaton641/library/lib_application.c
./src/automaton641/library/lib_general.h
./src/automaton641/library/lib_character.c
./src/automaton641/library/lib_window.c
./src/automaton641/library/lib_widget.c
./src/automaton641/library/lib_lang.c
./src/automaton641/library/lib_widget.h
./src/automaton641/library/lib_bidimensional.h
./src/automaton641/library/lib_includes.h
./src/automaton641/library/lib_application.h
./src/automaton641/library/lib_automaton_display.h
./src/automaton641/library/lib_string.h
)
add_library(library ${library_sources} )
target_include_directories( library PRIVATE ./src/ )

add_executable( gui
./src/automaton641/gui/main.c
)
target_include_directories( gui PRIVATE ./src/ )
target_link_libraries( gui library )
target_link_libraries( gui pthread )
target_link_libraries( gui GLEW )
target_link_libraries( gui GLU )
target_link_libraries( gui GL )
target_link_libraries( gui glfw )
