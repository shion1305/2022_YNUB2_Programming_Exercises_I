#include <stdio.h>

void print(int n);

int ask_for_input();

int main() {
    int a = ask_for_input();
    print(a);
}

void print(int n) {
    if (n > 999) {
        print(n / 1000);
        //再帰処理
        printf(",%03d", n%1000);
    } else {
        printf("%d",n);
    }
}

int ask_for_input() {
    int v;
    printf("TYPE VALUE: ");
    scanf("%d", &v);
    return v;
}
