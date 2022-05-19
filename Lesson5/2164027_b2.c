#include <stdio.h>

#define EOI -12345

void count(int *x, int *c);

int main() {
    printf("0～9 の任意の整数を入力してください ( 入力終了は EOF 制御文字 ) :\n");
    int input;
    int array[100];
    int position = 0;
    while (scanf("%d", &input) != EOF) {
        if (0 > input || input > 9) {
            printf("無効な範囲です。\n");
            continue;
        }
        array[position++] = input;
    }
    array[position] = EOI;
    int c[10] = {0};
    count(array, c);
    for (int i = 0; i < 10; ++i) {
        printf("%d: %d\n", i, c[i]);
    }
}

//assert all elements are 0~9
void count(int *x, int *c) {
    do {
        *(c + *x) += 1;
    } while (*(x++) != EOI);
}