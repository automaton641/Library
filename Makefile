main: bin/test
	./bin/test

clean:
	rm -r bin/*

bin/test: bin/main.o bin/lib.o
	gcc -Isrc bin/main.o bin/lib.o -o bin/test `pkg-config --libs glew glfw3`

bin/main.o: src/automaton641/test/main.c
	gcc -Isrc src/automaton641/test/main.c -c -o bin/main.o

bin/lib.o: src/automaton641/library/lib.c src/automaton641/library/lib.h
	gcc -Isrc src/automaton641/library/lib.c -c -o bin/lib.o
