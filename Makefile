all: bin/det_app

bin/det_app: obj/main.o obj/matrix.o
	mkdir -p bin
	gcc obj/main.o obj/matrix.o -o bin/det_app -lm

obj/main.o: src/main.c include/matrix.h
	mkdir -p obj
	gcc -Iinclude -Wall -c src/main.c -o obj/main.o

obj/matrix.o: src/matrix.c include/matrix.h
	mkdir -p obj
	gcc -Iinclude -Wall -c src/matrix.c -o obj/matrix.o

clean:
	rm -rf obj bin
