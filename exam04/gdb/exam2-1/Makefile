OBJECTS = lib/add.o lib/sub.o lib/multiply.o lib/divide.o

all: add.out sub.out multiply.out divide.out

add.out: lib/libmath.a
	gcc -I./lib -L./lib add.c -lmath -o add.out -g

sub.out: lib/libmath.a
	gcc -I./lib -L./lib sub.c -lmath -o sub.out -g

multiply.out: lib/libmath.a
	gcc -I./lib -L./lib multiply.c -lmath -o multiply.out -g

divide.out: lib/libmath.a
	gcc -I./lib -L./lib divide.c -lmath -o divide.out -g

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
	rm -f lib/add.o lib/sub.o lib/multiply.o lib/divide.o lib/libmath.a add.out sub.out multiply.out divide.out calc.out
