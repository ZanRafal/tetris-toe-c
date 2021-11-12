void displayTable(char (*gameWindow)[8]);
void toggle(int x, int y, char (*gameWindow)[8]);
int strcmp(const char *a, const char *b);
int numberOfOs(char (*gameWindow)[8]);
void calculateTiles(int x, int y, char (*gameWindow)[8]);
void pickFields(int *movesCounter, char (*gameWindow)[8],int *movesLimit);
void play(int *movesCounter, char (*gameWindow)[8], int *movesLimit);
void displayCurrentStats(int *movesCounter, int *movesLimit);
