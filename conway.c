#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 10

typedef struct {
    char state; 
} Cell;

void initializeWorld(Cell world[ROWS][COLUMNS], double probability) {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            world[i][j].state = (rand() / (double)RAND_MAX < probability) ? '+' : '-';
        }
    }
}

void displayWorld(Cell world[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%c ", world[i][j].state);
        }
        printf("\n");
    }
    printf("\n");
}

int countAliveNeighbors(Cell world[ROWS][COLUMNS], int x, int y) {
    int count = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue; 
            int neighborX = x + dx;
            int neighborY = y + dy;
            if (neighborX >= 0 && neighborX < ROWS && neighborY >= 0 && neighborY < COLUMNS) {
                if (world[neighborX][neighborY].state == '+' || world[neighborX][neighborY].state == '0') {
                    count++;
                }
            }
        }
    }
    return count;
}

int nextGeneration(Cell world[ROWS][COLUMNS]) {
    Cell newWorld[ROWS][COLUMNS];
    int changes = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            int aliveNeighbors = countAliveNeighbors(world, i, j);

            if (world[i][j].state == '+') {
                if (aliveNeighbors < 2 || aliveNeighbors > 3) {
                    newWorld[i][j].state = '-';
                    changes++;
                } else {
                    newWorld[i][j].state = '+';
                }
            } else if (world[i][j].state == '-') {
                if (aliveNeighbors == 3) {
                    newWorld[i][j].state = '0';
                    changes++;
                } else {
                    newWorld[i][j].state = '-';
                }
            } else if (world[i][j].state == '0') {
                newWorld[i][j].state = '+';
            }
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            world[i][j] = newWorld[i][j];
        }
    }

    return changes;
}

int main() {
    Cell world[ROWS][COLUMNS];
    double initialProbability = 0.3; 

    initializeWorld(world, initialProbability);

    printf("Initial world:\n");
    displayWorld(world);

    while (1) {
        int changes = nextGeneration(world);
        displayWorld(world);

        if (changes == 0) {
            printf("The game is over, no further evolution is possible.\n");
            break;
        }
    }

    return 0;
}
