#include <stdio.h>
#include <stdlib.h>

#define N 10
int data[N][N] = {
        {8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
        {8, 1, 0, 0, 8, 8, 0, 0, 0, 8},
        {8, 0, 8, 0, 0, 0, 0, 8, 0, 8},
        {8, 0, 8, 8, 8, 0, 8, 8, 0, 8},
        {8, 0, 0, 8, 8, 0, 0, 8, 0, 8},
        {8, 8, 0, 0, 8, 0, 8, 8, 0, 8},
        {8, 0, 8, 0, 8, 0, 0, 8, 0, 8},
        {8, 0, 0, 0, 8, 8, 0, 0, 0, 8},
        {8, 8, 8, 0, 0, 0, 0, 8, 0, 8},
        {8, 8, 8, 8, 8, 8, 8, 8, 9, 8}};

void printR(int d[N][N], int step) {
    printf("%2dで到着\n", step);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            switch (d[i][j]) {
                case 0:
                    printf("□");
                    break;
                case 8:
                    printf("■");
                    break;
                default:
                    printf("〇");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void search(int x, int y, int d[N][N], int step) {
    switch (d[x][y]) {
        case 0:
            data[x][y] = 2;
            break;
        case 9:
            printR(d, step);
        default:
            return;
    }
    step++;
    if (x > 0) search(x - 1, y, d, step);
    if (y > 0) search(x, y - 1, d, step);
    if (x < N - 1) search(x + 1, y, d, step);
    if (y < N - 1) search(x, y + 1, d, step);
    if (d[x][y] == 2) d[x][y] = 0;
}

int main(int argc, char *argv[]) {
    data[1][1] = 0;
    search(1, 1, data, 0);
}
