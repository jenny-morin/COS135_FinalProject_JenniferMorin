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
    j->name = malloc(sizeof(char)*(strlen("NOSTROMO")+2));

    strcpy(j->name,"NOSTROMO");

    for (int i = 0; i<6;i++){
        j->crew[i]=NULL;
    }
    return j;

}

void addCharacter(Character *aCharacter, Ship* aShip, int place){
    aShip->crew[place]= aCharacter;
}

void searchForAlien(int person, Ship* aShip){
    if (aShip->crew[person]==NULL){
        printf("You choose someone not in your crew, your turn is wasted\n");
    }
    else if (aShip->crew[person]->health == 0){
        printf("%s is already %sdead%s, your turn is wasted\n",aShip->crew[person]->name,RED,RESET);
    }
    else if(aShip->crew[person]->health == 1){
        aShip->crew[person]->health =0;
        printf("In searching for the alien %s has %sdied%s\n",aShip->crew[person]->name,RED,RESET);
    }
    else{
    int probability = 100;
    probability = rand() % probability;
    if (probability>20){
        int n =aShip->crew[person]->health;
        n = rand() % n;
        aShip->crew[person]->health-=n;
        if (aShip->crew[person]->health==0){
            printf("In searching for the alien %s has %sdied%s\n",aShip->crew[person]->name,RED,RESET);
        }
        else{
        printf("\n%s's health has been lowered to %d\n",aShip->crew[person]->name,aShip->crew[person]->health);
        }
    }
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

void endGame(Ship* aShip){
    int checker = 0;
    for(int i =0;i<5;i++){
        if (aShip->crew[i]!=NULL && aShip->crew[i]->health != 0){
            
            printf("%s%s has made it off this ship and escaped!\n%s",YEL,aShip->crew[i]->name,RESET);
            checker++;

        }
    }
    
    if (checker == 0){
        if (aShip->crew[5]!=NULL){
            printf("%sEveryone except Jonsey has died, and he's a cat so you lost%s\n",RED,RESET);
        }
        else{
        printf("%sYOU LOSE\n%s",RED,RESET);
        }
    }
    
}

void freeShip(Ship* aShip){
    
    
    for(int i =0;i<6;i++){
        
        freeCharacter(aShip->crew[i]);
    }
    free(aShip->crew);
    free(aShip->name);
    free(aShip);
}