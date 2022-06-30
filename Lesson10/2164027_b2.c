#include <stdio.h>

//プロトタイプ宣言
int f(int n);

int g(int n);

int main() {
    //テストケースの用意
    int target[4] = {0, 1, 4, -10};
    for (int i = 0; i < 4; ++i) {
        //それぞれのケースについて実行
        printf("n = %d\n", target[i]);
        printf("f(n): %d\n", f(target[i]));
        printf("g(n): %d\n" , g(target[i]));
    }
}

//問題文で指定された関数
int f(int n) {
    if (n <= 1) return 1;
    return n * g(n - 1);
}

//問題文で指定された関数
int g(int n) {
    if (n == 0)return 0;
    return n + f(n - 1);
}