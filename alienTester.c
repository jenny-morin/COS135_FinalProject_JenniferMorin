#include "character.c"

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

    for(int i = 0; i<6; i++){
    if(fgets(buffer, sizeof(buffer), fp)!=NULL){
        printf("Would you like to add: %s\n",buffer);
        //cut this string up into the three parameters queen
        Character *c = createCharacter("Ripley","Second in command",100);
        printCharacter(Ripley); 
        }
    }
    fclose(fp);





    /*char buffer[20];
    printf("How was your day today?(from 1-10):\n");
    fgets(buffer, sizeof(buffer), stdin);
    int input = atoi(buffer);
    switch(input){
        case 1:
            printf("It can only get better from here\n");
            break;
        case 2:
        case 3:
        case 4:
            printf("I hope it will get better\n");
            break;
        case 5:
        case 6:
        case 7:
            printf("Not to bad, it could be worse\n");
            break;
        case 8:
        case 9:
            printf("Wow thats pretty good!\n");
            break;
        case 10:
            printf("Yippee!!!!\n");
            break;
        default:
            printf("Invalid number\n");
            break;
    }
            */
}