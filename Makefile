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

linker_flags = `pkg-config --libs glew glfw3` -pthread
includes = -Isrc

main: execute_gui

execute_gui: $(gui_executable)
	./$(gui_executable)

execute_test: $(test_executable)
	./$(test_executable)

debug_test: $(test_executable)
	gdb $(test_executable)

clean:
	rm -r bin/*

$(test_executable): $(test_dependencies)
	gcc $(includes) $(test_sources) -o $(test_executable) $(linker_flags)

$(gui_executable): $(gui_dependencies)
	gcc $(includes) $(gui_sources) -o $(gui_executable) $(linker_flags)
