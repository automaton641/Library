lib_sources = $(wildcard src/automaton641/library/*.c)
lib_headers = $(wildcard src/automaton641/library/*.h)

test_sources =  $(wildcard src/automaton641/test/*.c) $(lib_sources)
test_headers = $(wildcard src/automaton641/test/*.h) $(lib_headers)
test_dependencies = $(test_sources) $(test_headers)
test_executable = bin/test

gui_sources =  $(wildcard src/automaton641/gui/*.c) $(lib_sources)
gui_headers = $(wildcard src/automaton641/gui/*.h) $(lib_headers)
gui_dependencies = $(gui_sources) $(gui_headers)
gui_executable = bin/gui


lang_sources =  $(wildcard src/automaton641/lang/*.c) $(lib_sources)
lang_headers = $(wildcard src/automaton641/lang/*.h) $(lib_headers)
lang_dependencies = $(lang_sources) $(lang_headers)
lang_executable = bin/lang

linker_flags = `pkg-config --libs glew glfw3` -pthread
includes = -Isrc

main: execute_lang

execute_lang: $(lang_executable)
	./$(lang_executable)

execute_gui: $(gui_executable)
	./$(gui_executable)

execute_test: $(test_executable)
	./$(test_executable)

debug_test: $(test_executable)
	gdb $(test_executable)

clean:
	rm -r bin/*

$(lang_executable): $(lang_dependencies)
	gcc $(includes) $(lang_sources) -o $(lang_executable) $(linker_flags)

$(test_executable): $(test_dependencies)
	gcc $(includes) $(test_sources) -o $(test_executable) $(linker_flags)

$(gui_executable): $(gui_dependencies)
	gcc $(includes) $(gui_sources) -o $(gui_executable) $(linker_flags)
