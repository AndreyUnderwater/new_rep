all: p.exe
p.exe: p.o function.o
	gcc -o p.exe p.o function.o
p.o: p.c
	gcc -c p.c
function.o: function.c
	gcc -c function.c