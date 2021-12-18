CC = gcc
EXEC = LePendu

all : $(EXEC)
	make clean && ./$(EXEC)

$(EXEC) : LePendu.o Fonctions.o
	$(CC) LePendu.o Fonctions.o -o LePendu 

Fonctions.o : Fonctions.c
	$(CC) -o Fonctions.o -c Fonctions.c

LePendu.o : LePendu.c
	$(CC) -o LePendu.o -c LePendu.c

clean:
	rm -f *.o
