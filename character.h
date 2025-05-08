#ifndef CHARACTER_H
#define CHARACTER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>

typedef struct Character Character;

struct Character{
    char* name;
    int health;
    char* job;
}; 



Character* createCharacter(char *name, char *job, int health);

void printCharacter(Character* aCharacter);

void freeCharacter(Character* aCharacter);

#endif