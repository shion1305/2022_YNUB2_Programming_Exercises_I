#include <stdio.h>

int fRecursion(int n);

int fLoop(int n);

int main() {
    int n;
    printf("正数 n を入力してください ( ただし、n > 0 )\n");
    printf("n = ");
    scanf("%d", &n);
    printf("%d! = \n", n);
    printf("再帰:　 %d\n", fRecursion(n));
    printf("ループ: %d\n", fLoop(n));
}

int fRecursion(int n) {
    //1より大きい時は再帰的にまた計算させる
    if (n > 1) return n * fRecursion(n - 1);
    //1以下(0以下はならないはずだが)の時は1を返す
    return 1;
}

int fLoop(int n) {
    //while文でnが0になる手前までかけ続ける。
    int c = 1;
    do {
        c *= n;
    } while (--n > 0);
}