#include <stdio.h>

//EOFとは別に自分で管理用のEnd Of Inputを定める
#define EOI -12345

void count(int *x, int *c);

int main() {
    printf("0～9 の任意の整数を入力してください ( 入力終了は EOF 制御文字 ) :\n");
    int input;
    int array[100];
    int position = 0;
    //まずarrayに格納する。
    while (scanf("%d", &input) != EOF) {
        //無効な値の検知
        if (0 > input || input > 9) {
            printf("無効な範囲です。\n");
            continue;
        }
        array[position++] = input;
    }
    array[position] = EOI;
    int c[10] = {0};

    //arrayをカウントさせる。
    count(array, c);
    //適切なフォーマット尾での出力
    for (int i = 0; i < 10; ++i) {
        printf("%d: %d\n", i, c[i]);
    }
}

//assert all elements are 0~9
void count(int *x, int *c) {
    //ポインタを活用してcの0~9番地に出力する
    do {
        *(c + *x) += 1;
    } while (*(x++) != EOI);
}