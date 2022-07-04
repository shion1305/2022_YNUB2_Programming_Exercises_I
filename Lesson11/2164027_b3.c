#include <stdio.h>

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

//結果を出力する関数。
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

//上下左右を確認し、もし道が見つかれば次へ進む。
void search(int x, int y, int d[N][N], int step) {
    //道があれば(0,1)その道をマーク。なければ関数を探索を終了する。
    switch (d[x][y]) {
        case 0:
            data[x][y] = 2;
        case 1:
            break;
        case 9:
            printR(d, step);
        default:
            return;
    }
    step++;
    //上下左右に再帰的に探索。
    if (x > 0) search(x - 1, y, d, step);
    if (y > 0) search(x, y - 1, d, step);
    if (x < N - 1) search(x + 1, y, d, step);
    if (y < N - 1) search(x, y + 1, d, step);
    if (d[x][y] == 2) d[x][y] = 0;
}

//開始地点を見つけスタートさせる。
void start(int d[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (d[i][j] == 1) {
                d[i][j] = 0;
                search(i, j, d, 0);
                return;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    //処理の開始
    start(data);
}
