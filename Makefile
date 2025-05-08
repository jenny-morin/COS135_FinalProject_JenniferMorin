ship: character.o ship.o alienTester.o
	gcc character.o ship.o alienTester.o -o ship

character.o: character.c character.h
	gcc character.c -c -o character.o

ship.o: character.h ship.c ship.h
	gcc ship.c -c -o ship.o


alienTester.o: alienTester.c character.h ship.h
	gcc alienTester.c -c -o alienTester.o

clean:
	rm *.o
	rm ship
	