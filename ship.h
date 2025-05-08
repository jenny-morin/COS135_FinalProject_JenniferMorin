#ifndef SHIP_H
#define SHIP_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "character.h"
//do i include the character files?

typedef struct Ship Ship;

struct Ship{
    char* name;
    Character** crew;
    bool blownUp;
    int points;
};

Ship* createShip();

void addCharacter(Character *aCharacter, Ship* aShip, int place);

void searchForAlien(int person, Ship* aShip);

void printShip(Ship* aShip);

//void freeShip(Ship* aShip);

#endif