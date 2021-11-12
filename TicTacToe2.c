#include <stdlib.h>
#include <stdio.h>
#include "methods.h"

int main(int argc, char *argv[]) {
    int movesCounter = 0;
    int movesLimit = strtol(argv[1], 0, 10);
    char gameWindow[8][8] = {
        { 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        { 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        { 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        { 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        { 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        { 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        { 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        { 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
    };


    if(strcmp(argv[0], "./a.out")) {
        printf("Nazwa pliku wykonawczego zostala zmieniona\n");
        return 1;
    }

    play(&movesCounter, gameWindow, &movesLimit);
    return 0;
}