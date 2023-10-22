OBJECTS = lib/add.o lib/sub.o lib/multiply.o lib/divide.o

all: calc.out

calc.out: lib/libmath.so
	gcc -I./lib -L/root/exam2-2/lib calc.c -Wl,--rpath=/root/exam2-2/lib -o calc.out -lmath -pg

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
	rm -f lib/add.o lib/sub.o lib/multiply.o lib/divide.o lib/libmath.a libtest lib/libmath.so lib/libmath.so.1.0.1 calc.out
