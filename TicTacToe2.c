#include <stdlib.h>
#include <stdio.h>

void displayTable();
void toggle(int x, int y);
int numberOfOs();
void calculateTiles(int x, int y);
void pickFields(int *movesCounter);
void play(int *movesCounter);
void displayCurrentStats(int *movesCounter);

int main(int argc, char *argv[]) {
    if(strcmp(argv[0], "./a.out")) {
        printf("%s\n %d\n" , argv[0], argc);
        printf("Nazwa pliku wykonawczego została zmieniona\n");
        return 1;
    }

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
    int movesCounter = 0;

    //play(&movesCounter, &gameWindow);
    displayTable(gameWindow);
    return 0;
}

// void initGameWindow(char *gameWindow[8][8]) {
//     for (int i = 0; i < 8; i++) {
//         for (int j = 0; j < 8; j++) {
//             *( *(gameWindow + i) + j) = 'O'; 
//         }
//     }
// }

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

// int numberOfOs() {
//     int counter = 0;
//     for(int i = 0; i < 8; i++) {
//         for(int j = 0; j < 8; j++) {
//             if(gameWindow[i][j] == 'O')
//                 counter++;
//         }
//     }
//     return counter;
// }

// void toggle(int x, int y) {
//     if(x < 0 || x > 8) return;
//     if(y < 0 || y > 8) return;

//     if(gameWindow[x][y] == 'X') {
//         gameWindow[x][y] = 'O';
//     } else if (gameWindow[x][y] == 'O') {
//         gameWindow[x][y] = 'X';
//     }
// }

// void calculateTiles(int xVal, int yVal) {
//     toggle(xVal, yVal);
//     toggle(xVal - 1, yVal);
//     toggle(xVal + 1, yVal);
//     toggle(xVal, yVal - 1);
//     toggle(xVal, yVal + 1);
// }

//wybieranie pól do zmiany
// void pickFields(int *movesCounter) {
//     int xVal = 0;
//     int yVal = 0;

//     printf("Podaj numer wiersza: ");
//     scanf("%d", &xVal);
//     printf("Podaj numer kolumny: ");
//     scanf("%d", &yVal);

//     *movesCounter = *movesCounter + 1;//inkrementacja licznika ruchów gracza
//     calculateTiles(yVal - 1, xVal - 1);
// }

// void displayCurrentStats(int *movesCounter) {
//     printf("Aktualna liczba ruchów: %d\n", movesCounter);
// }

// void play(int *movesCounter, char *gameWindow) {
//     printf("Witam w grze kolko i krzyzyk!!\n\n");
//     while(numberOfOs() != 0) {
// 	system("clear");//czyszczenie konsoli (dla przejrzystości gry)
//         displayTable();
//         displayCurrentStats(movesCounter);
//         pickFields(movesCounter);
//     }
//     printf("Gratulacje! Wygrales gre.");
// }
