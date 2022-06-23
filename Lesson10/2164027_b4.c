#include <stdio.h>
#include <stdlib.h>

int f1(int n, int *count);

int f2(int n, int v1, int v2, int *count);

int f3(int n, int *count);


int main() {
    printf("整数　n　を入力してください\n");
    printf("n = ");
    int n;
    scanf("%d", &n);

    if (n < 0) {
        printf("エラー、nは正数ではありませぬ。\n");
        exit(1);
    }

    //f1の実行
    int count = 0;
    int r1 = f1(n, &count);
    printf("二重再帰 : 計算結果: %d, 呼び出し回数: %d\n", r1, count);

    //f2の実行
    count = 0;
    int r2 = f2(n, 1, 0, &count);
    printf("末尾再帰 : 計算結果: %d, 呼び出し回数: %d\n", r2, count);
    count = 0;

    //f3の実行
    int r3 = f3(n, &count);
    printf("ループ　 : 計算結果: %d, 呼び出し回数: %d\n", r3, count);
}

int f1(int n, int *count) {
    //回数をカウント
    (*count)++;
    if (n == 0)return 0;
    if (n == 1)return 1;
    return f1(n - 1, count) + f1(n - 2, count);
}

int f2(int n, int v1, int v2, int *count) {
    //回数をカウント
    (*count)++;
    if (n == 1) return v1;
    return f2(n - 1, v1 + v2, v1, count);
}

int f3(int n, int *count) {
    int v1 = 1, v2 = 0;
    do {
        //回数をカウント
        (*count)++;
        //v1をメモ。
        int tmp = v1;
        v1 += v2;
        //v1にv2を足す。
        v2 = tmp;
    } while (--n > 1);
    return v1;
}

