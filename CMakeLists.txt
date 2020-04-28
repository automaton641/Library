 
cmake_minimum_required(VERSION 3.13.4)
project (TheProject)

set(LIBRARY_SOURCES
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
add_library( Library ${LIBRARY_SOURCES} )
target_include_directories(Library PRIVATE src)

#add_library(lang_lib libsrc1.cc libsrc2.cc libsrc3.cc)
add_executable(lang src/automaton641/lang/main.c )
target_link_libraries(lang Library )
target_include_directories(lang PRIVATE src)
target_link_libraries(lang pthread)
target_link_libraries(lang GLEW)
target_link_libraries(lang GLU)
target_link_libraries(lang GL)
target_link_libraries(lang glfw)
