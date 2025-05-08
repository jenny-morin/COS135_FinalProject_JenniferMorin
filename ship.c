#include "ship.h"


#define BOLD "\e[0;1m"
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define RESET "\e[0m"

Ship* createShip(){
    Ship* j = malloc(sizeof(Ship));
    j->crew = malloc(sizeof(Character*)*6);
    j->name = malloc(sizeof(char)*strlen("NOSTROMO"));
    j->blownUp = malloc(sizeof(bool));
    j->points = 0;
    strcpy(j->name,"NOSTROMO");
    j->blownUp = false;
    for (int i = 0; i<6;i++){
        j->crew[i]=NULL;
    }
    return j;

}

void addCharacter(Character *aCharacter, Ship* aShip, int place){
    aShip->crew[place]= aCharacter;
}

void searchForAlien(int person, Ship* aShip){
    int probability = 100;
    probability = rand() % probability;
    if (probability>20){
        int n =aShip->crew[person]->health;
        n = rand() % n;
        aShip->crew[person]->health-=n;
    }
}


void printShip(Ship* aShip){
    printf("\n%sOn the %s your crew includes:%s\n\n",BLU,aShip->name,RESET);
    for (int i = 0; i<6 ; i++){
        if (aShip->crew[i] != NULL){
            if (aShip->crew[i]->health != 0){
                printCharacter(aShip->crew[i]);
                printf("\n");
            }
            else{
                printf("%s%s has died%s\n",RED,aShip->crew[i]->name,RESET);
                printf("\n");
            }
        }
    }
}

//void freeShip(Ship* aShip);