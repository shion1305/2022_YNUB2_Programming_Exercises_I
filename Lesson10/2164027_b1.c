#include <stdio.h>
#include <stdlib.h>

int f(int n, int k);

int main() {
    printf("n, k を入力してください ( ただし、0 < k < n )\n");
    int n, k;
    //それぞれの入力を求める
    printf("n = ");
    scanf("%d", &n);
    printf("k = ");
    scanf("%d", &k);
    if (n <= k && k <= 0) {
        printf("ERROR");
        exit(1);
    }
    int r = f(n, k);
    printf("%d", r);
}

int f(int n, int k) {
    //題意の条件の関数
    if (k == 0 || k == n) return 1;
    if (0 < k && k < n)return f(n - 1, k - 1) + f(n - 1, k);
    printf("0 < k < n ではありません");
    exit(1);
}