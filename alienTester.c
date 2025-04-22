#include "character.c"

int main(){
    Character *Ripley = createCharacter("Ripley","Second in command",100);
    printCharacter(Ripley);  
    freeCharacter(Ripley);
}