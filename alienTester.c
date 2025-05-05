#include "character.c"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    Character *Ripley = createCharacter("Ripley","Second in command",100);
    printCharacter(Ripley);  
    freeCharacter(Ripley);

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
        printf("Y/N Would you like to add- Name: %s; Rank: %s; Health %s;\t",a,b,c);
        fgets(addChar, sizeof(addChar), stdin);
        //printf("%s\n",addChar);
        if (strcmp(addChar,"Y\n")==0){
            Character *myChar = createCharacter(a,b,intOfC);
            printCharacter(myChar);
            //printf("worked");
        }
        else{
            printf("You will be without your fearless %s\n",b);
        }
    }
    fclose(fp);
}