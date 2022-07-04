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
        {8, 8, 8, 0, 0, 0, 0, 8, 8, 8},
        {8, 8, 8, 8, 8, 8, 8, 8, 9, 8}};

//結果を出力する関数。
void printR(int d[N][N], int step, FILE *out) {
    fprintf(out, "%2dで到着\n", step);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            switch (d[i][j]) {
                case 0:
                    fprintf(out, "□");
                    break;
                case 8:
                    fprintf(out, "■");
                    break;
                default:
                    fprintf(out, "〇");
            }
        }
        fprintf(out, "\n");
    }
    fprintf(out, "\n");
}

//上下左右を確認し、もし道が見つかれば次へ進む。解の数を返す。
int search(int x, int y, int d[N][N], int step, FILE *out, int sum) {
    int sum_r = sum;
    //道があれば(0,1)その道をマーク。なければ関数を探索を終了する。
    switch (d[x][y]) {
        case 0:
            data[x][y] = 2;
        case 1:
            break;
        case 9:
            printR(d, step, out);
            return 1;
        default:
            return 0;
    }
    step++;
    //解の数を記録しながら上下左右に再帰的に探索。
    if (x > 0) sum_r += search(x - 1, y, d, step, out, sum);
    if (y > 0) sum_r += search(x, y - 1, d, step, out, sum);
    if (x < N - 1) sum_r += search(x + 1, y, d, step, out, sum);
    if (y < N - 1) sum_r += search(x, y + 1, d, step, out, sum);
    if (d[x][y] == 2) d[x][y] = 0;
    return sum_r;
}

//開始地点を見つけスタートさせる。解の数を返す。
int start(int d[N][N], FILE *out) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (d[i][j] == 1) {
                d[i][j] = 0;
                return search(i, j, d, 0, out, 0);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("ERROR, NO ARGUMENTS");
        exit(-1);
    }
    FILE *out = fopen(argv[1], "w");
    //処理の開始
    int result = start(data, out);
    if (result == 0) {
        printf("解がありません。\n");
        return 0;
    }
    printf("%d results found, Completed. Output: %s.", result, argv[1]);
}
