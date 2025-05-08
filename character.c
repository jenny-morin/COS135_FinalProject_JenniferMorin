#include "character.h"

Character* createCharacter(char *name, char *job, int health){
    Character* j = malloc(sizeof(Character));
    j->name = malloc(sizeof(char)*(strlen(name)+2)); 
    j->job = malloc(sizeof(char)*(strlen(job)+2));
    strcpy(j->name,name);
    strcpy(j->job,job);
    j->health = health;
    return j;
}

void printCharacter(Character* aCharacter){
    printf("Name: %s  \nJob: %s \nHealth: %d \n",aCharacter->name,aCharacter->job,aCharacter->health);
}

void freeCharacter(Character* aCharacter){
    if (aCharacter!=NULL){
    free(aCharacter->name);
    aCharacter->name=NULL;
    free(aCharacter->job);
    aCharacter->job=NULL;
    free(aCharacter);
    aCharacter=NULL;
    }
}