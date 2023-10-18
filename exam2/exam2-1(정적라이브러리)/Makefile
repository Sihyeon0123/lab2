OBJECTS = lib/add.o lib/sub.o lib/multiply.o lib/divide.o

all: libtest

libtest: lib/libmath.a
	gcc -I./lib -L./lib libtest.c -lmath -o libtest

lib/libmath.a: $(OBJECTS)
	ar rcs lib/libmath.a $(OBJECTS)

lib/add.o : lib/add.c
	gcc -c lib/add.c -o lib/add.o

lib/sub.o : lib/sub.c
	gcc -c lib/sub.c -o lib/sub.o

lib/multiply.o : lib/multiply.c
	gcc -c lib/multiply.c -o lib/multiply.o

lib/divide.o : lib/divide.c
	gcc -c lib/divide.c -o lib/divide.o

clean:
	rm -f lib/add.o lib/sub.o lib/multiply.o lib/divide.o lib/libmath.a libtest 
