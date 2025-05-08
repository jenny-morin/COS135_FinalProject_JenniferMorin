ship: character.o alienTester.o
	gcc character.o alienTester.o -o ship

character.o: character.c character.h
	gcc character.c -c -o character.o

ship.o: character.c character.h ship.c ship.h
	gcc ship.c -c -o ship.o


alienTester.o: alienTester.c character.h
	gcc alienTester.c -c -o alienTester.o

clean:
	rm ship
	rm *.o