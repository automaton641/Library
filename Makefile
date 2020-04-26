main: bin/test
	./bin/test

bin/test: bin/main.o
	gcc bin/main.o -o bin/test

bin/main.o: src/automaton641/test/main.c
	gcc src/automaton641/test/main.c -c -o bin/main.o
