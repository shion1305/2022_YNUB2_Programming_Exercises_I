#include <stdio.h>

#define SIZE 5
#define MAX 15
int data[SIZE] = {7, 4, 5, 6, 3};

//結果を出力する関数。
void printR(int step, int result[SIZE]) {
    for (int i = 0; i < step; ++i) {
        printf("(%c,%d),", result[i] + 65, data[result[i]]);
    }
    printf("\n");
}

//再帰的に確認するための関数。ナップサック問題のアルゴリズムを用いて効率的に検証する。
void check(int start, int sum, int step, int result[SIZE]) {
    for (int i = start; i < SIZE; ++i) {
        int s = sum + data[i];
        result[step] = i;
        if (s == MAX)printR(step + 1, result);
        if (s >= MAX) continue;
        check(i + 1, s, step + 1, result);
    }
}

//checkを0,0,0と空配列を渡すことでスタートさせる。
int main() {
    printf("最大搭載量 %dt の荷物の組み合わせは以下の通り。\n", MAX);
    int result[SIZE];
    check(0, 0, 0, result);
}