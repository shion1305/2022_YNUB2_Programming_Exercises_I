#include <stdio.h>

#define SIZE 9

int data[SIZE][SIZE] = {
        {1, 0, 6, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 8, 0, 0, 3, 0},
        {0, 0, 0, 0, 0, 7, 0, 0, 0},
        {0, 3, 8, 6, 0, 0, 0, 5, 0},
        {0, 0, 0, 0, 0, 0, 9, 4, 0},
        {4, 0, 2, 9, 5, 3, 6, 8, 1},
        {0, 8, 7, 5, 0, 9, 0, 2, 4},
        {0, 1, 0, 8, 0, 6, 3, 9, 0},
        {3, 4, 9, 1, 7, 2, 0, 6, 5}};

int check(int v, int x, int y, int in[SIZE][SIZE]);

//それぞれについて、1~9が入るか検証し、入ることが可能であったら代入することによって解く関数。解が無ければ0を返す。
int exec(int in[SIZE][SIZE], int index) {
    if (index == 81) return 1;
    if (in[index % SIZE][index / SIZE] > 0) return exec(in, index + 1);
    for (int i = 1; i <= SIZE; ++i) {
        if (check(i, index % SIZE, index / SIZE, in)) {
            in[index % SIZE][index / SIZE] = i;
            if (exec(in, index + 1)) return 1;
            in[index % SIZE][index / SIZE] = 0;
        }
    }
    return 0;
}

//vを指定したポイントに入れたとして成立するか確認する関数。
int check(int v, int x, int y, int in[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        if (in[x][i] == v) return 0;
        if (in[i][y] == v) return 0;
        if (in[x / 3 * 3 + i / 3][y / 3 * 3 + i % 3] == v) return 0;
    }
    return 1;
}

//結果を出力する用の関数
void print(int in[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf("%d ", in[i][j]);
        }
        printf("\n");
    }
}

int main() {
    //解く
    if (exec(data, 0)) {
        print(data);
    } else {
        print(data);
        printf("解は存在しません。");
    }
}