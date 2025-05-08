#include "character.c"
#include "ship.c"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

int main(){
    Character *Ripley = createCharacter("Ripley","Second in command",100);
    printCharacter(Ripley);  
    freeCharacter(Ripley);
    Ship* nostromo = createShip();
    int* onShip[6];

    FILE *fp = fopen("characterList.txt","r");

    if (fp==NULL){
        printf("Could not open file\n");
        exit(1);
    }

    char buffer[1024];
    char addChar[10];
    char a[256];
    char b[256];
    char c[256];

    for(int i = 0; i<6; i++){
    if(fgets(buffer, sizeof(buffer), fp)!=NULL){

        char *ptr = buffer + strlen(buffer)-1;
        while (isspace(*(ptr))) ptr--;
        *(ptr+1)=0;
        ptr = buffer;
        while (isspace(*ptr)) ptr++;

        char* token = strtok(buffer,";");
        strcpy(a,token);

        token= strtok(NULL,";");//NULL is used when you want the prevous strtok location
        strcpy(b,token);

        token= strtok(NULL,";");//NULL is used when you want the prevous strtok location
        strcpy(c,token);
        }
        int intOfC = atoi(c);
        printf("Y/N Would you like to add-\n%sName: %s; Rank: %s; Health %s;\t%s",BOLD,a,b,c,RESET);
        fgets(addChar, sizeof(addChar), stdin);
    
        if (strcmp(addChar,"Y\n")==0){
            Character *myChar = createCharacter(a,b,intOfC);
            //printCharacter(myChar);
            addCharacter(myChar,nostromo,i);  
            
        }
        else{
            printf("\n%sYou will be without your fearless %s%s\n\n",RED,b,RESET);
        }
        
    }
    //HAVE THIS LOOP
    printShip(nostromo);
    printf("\nWho would you like to send to look for the alien, you must search for the alien 8 times to %skill it%s and %sescape%s\n",RED,RESET,YEL,RESET);
    printf("Out of your crew type... \n1 for Dallas\n2 for Ripley\n3 for Parker\n4 for Lambert\n5 for Brett\n6 for Jonsey\n");
    fgets(addChar, sizeof(addChar), stdin);
    switch (atoi(addChar)){
        case 1:
            searchForAlien(1,nostromo);
            break;
        case 2:
            searchForAlien(2,nostromo);
            break;
        case 3:
            searchForAlien(3,nostromo);
            break;
        case 4:
            searchForAlien(4,nostromo);
            break;
        case 5:
            searchForAlien(5,nostromo);
            break;
        case 6:
            searchForAlien(6,nostromo);
            break;
    }
    
    
    printShip(nostromo);
    //PRINT AN ENDING STRING TELLING USER IF THEY WON OR LOST


    //FREE EVERYTHING
    
    fclose(fp);
}