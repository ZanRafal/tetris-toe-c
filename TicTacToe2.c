#include <stdlib.h>
#include <stdio.h>

void displayTable(char (*gameWindow)[8]);
void toggle(int x, int y, char (*gameWindow)[8]);
int strcmp(const char *a, const char *b);
int numberOfOs(char (*gameWindow)[8]);
void calculateTiles(int x, int y, char (*gameWindow)[8]);
void pickFields(int *movesCounter, char (*gameWindow)[8],int *movesLimit);
void play(int *movesCounter, char (*gameWindow)[8], int *movesLimit);
void displayCurrentStats(int *movesCounter, int *movesLimit);

int main(int argc, char *argv[]) {
    if(strcmp(argv[0], "./a.out")) {
        printf("Nazwa pliku wykonawczego zostala zmieniona\n");
        return 1;
    }

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

    play(&movesCounter, gameWindow, &movesLimit);
    return 0;
}

void displayTable(char (*gameWindow)[8]) {
    printf("|==========================================|\n");
    printf("| X | 1 || 2 || 3 || 4 || 5 || 6 || 7 || 8 |\n");
    printf("|---|======================================|\n");
    for(int i = 0; i < 8; i++) {
	printf("| %d ", i + 1);
        for(int j = 0; j < 8; j++) {
            printf("| %c |" , *(*(gameWindow + i) + j) );
        }
	printf("\n|---|--------------------------------------|");
        printf("\n");
    }
    printf("|==========================================|");
    printf("\n\n");
}

int numberOfOs(char (*gameWindow)[8]) {
    int counter = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(*(*(gameWindow + i) + j) == 'O')
                counter++;
        }
    }
    return counter;
}

void toggle(int x, int y, char (*gameWindow)[8]) {
    if(x < 0 || x > 8) return;
    if(y < 0 || y > 8) return;

    if(*(*(gameWindow + x) + y) == 'X') {
        *(*(gameWindow + x) + y) = 'O';
    } else if (*(*(gameWindow + x) + y) == 'O') {
        *(*(gameWindow + x) + y) = 'X';
    }
}

void calculateTiles(int xVal, int yVal, char (*gameWindow)[8]) {
    toggle(xVal, yVal, gameWindow);
    toggle(xVal - 1, yVal, gameWindow);
    toggle(xVal + 1, yVal, gameWindow);
    toggle(xVal, yVal - 1, gameWindow);
    toggle(xVal, yVal + 1, gameWindow);
}

void pickFields(int *movesCounter, char (*gameWindow)[8], int *movesLimit) {
    int xVal = 0, yVal = 0;

    printf("Podaj numer wiersza: ");
    scanf("%d", &xVal);
    printf("Podaj numer kolumny: ");
    scanf("%d", &yVal);

    *movesCounter = *movesCounter + 1;
    *movesLimit = *movesLimit - 1;
    calculateTiles(yVal - 1, xVal - 1, gameWindow);
}

void displayCurrentStats(int *movesCounter, int *movesLimit) {
    printf("Aktualna liczba ruchow: %d\n", *movesCounter);
    printf("Pozostalo: %d ruchow\n", *movesLimit);
}

void play(int *movesCounter, char (*gameWindow)[8],int *movesLimit) {
    printf("Witam w grze kolko i krzyzyk!!\n\n");
    while(numberOfOs(gameWindow) != 0) {
        displayTable(gameWindow);
        displayCurrentStats(movesCounter, movesLimit);

        if(*movesLimit == 0) {
            printf("Przekroczona dozwolona ilosc ruchow!!\n");
            return;
        }

        pickFields(movesCounter, gameWindow, movesLimit);

    }
    printf("Gratulacje! Wygrales gre.");
}
