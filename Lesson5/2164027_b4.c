#include <stdio.h>

//内積を計算する関数のプロトタイプ宣言。任意の次元に対応することに注意。
int innerProduct(int *v1, int *v2, int size);

//入力を受け取る関数のプロトタイプ宣言。任意の次元に対応することに注意。
void ask_for_input(int *vector, int size);

int main() {
    //最初に次数を確認する。
    printf("次元を入力してください。");
    int n;
    //値として不適切な場合は弾く。
    while (1) {
        scanf("%d", &n);
        if (n > 0) break;
        printf("入力値は次元として無効です。");
    }
    //次元nに合わせて入力を格納するベクトルの用意
    int vector1[n];
    int vector2[n];

    //それぞれのベクトルの入力受付
    printf("ベクトル1を入力してください。\n");
    ask_for_input(vector1, n);
    printf("ベクトル2を入力してください。\n");
    ask_for_input(vector2, n);
    //内積の計算
    printf("内積: %d", innerProduct(vector1, vector2, n));
}

void ask_for_input(int *vector, int size) {
    for (int i = 0; i < size; ++i) {
        //それぞれ受け取り、任意の次元ベクトルをポインタによって格納
        scanf("%d", vector + i);
    }
}

int innerProduct(int v1[], int v2[], int size) {
    //問題の指定によりポインタを使わずに計算する
    //問題の指定により任意次数のベクトルの内積が計算できるようにする。
    int r = 0;
    for (int i = 0; i < size; ++i) {
        r += v1[i] * v2[i];
    }
    return r;
}
