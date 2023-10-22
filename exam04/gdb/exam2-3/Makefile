OBJECTS = lib/add.o lib/sub.o lib/multiply.o lib/divide.o


all: add.out sub.out multiply.out divide.out

add.out: lib/libmath.so
	gcc -g -rdynamic add.c -ldl -o add.out

sub.out: lib/libmath.so
	gcc -g -rdynamic subtract.c -ldl -o sub.out

multiply.out: lib/libmath.so
	gcc -g -rdynamic multiply.c -ldl -o multiply.out

divide.out: lib/libmath.so
	gcc -g -rdynamic divide.c -ldl -o divide.out
	
lib/libmath.so : lib/libmath.so.1.0.1
	ln -s libmath.so.1.0.1 lib/libmath.so

lib/libmath.so.1.0.1: $(OBJECTS)
	gcc -shared -Wl,-soname,libmath.so.1 -o lib/libmath.so.1.0.1 $(OBJECTS)

lib/add.o : lib/add.c
	gcc -c lib/add.c -o lib/add.o

lib/sub.o : lib/sub.c
	gcc -c lib/sub.c -o lib/sub.o

lib/multiply.o : lib/multiply.c
	gcc -c lib/multiply.c -o lib/multiply.o

lib/divide.o : lib/divide.c
	gcc -c lib/divide.c -o lib/divide.o

clean:
	rm -f lib/add.o lib/sub.o lib/multiply.o lib/divide.o lib/libmath.a libtest lib/libmath.so lib/libmath.so.1.0.1  add.out sub.out multiply.out divide.out
