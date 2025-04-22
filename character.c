#include "character.h"

Character* createCharacter(char *name, char *job, int health){
    Character* j = malloc(sizeof(Character));
    j->name = malloc(sizeof(char)*strlen(name)); 
    j->job = malloc(sizeof(char)*strlen(job));
    strcpy(j->name,name);
    strcpy(j->job,job);
    j->health = health;
    return j;
}

void printCharacter(Character* aCharacter){
    printf("Name: %s  \nJob: %s \nHealth(0-100): %d \n",aCharacter->name,aCharacter->job,aCharacter->health);
}

void freeCharacter(Character* aCharacter){
    free(aCharacter->name);
    free(aCharacter->job);
    free(aCharacter);
}