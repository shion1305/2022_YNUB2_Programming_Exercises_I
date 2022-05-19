#include <stdio.h>

//内積を計算する関数のプロトタイプ宣言
int innerProduct(int *v1, int *v2);

//入力を受け取る関数のプロトタイプ宣言
void ask_for_input(int *vector);

int main() {
    int vector1[3];
    int vector2[3];
    //入力を格納するベクトルの用意
    //それぞれのベクトルの入力受付
    printf("ベクトル1を入力してください。\n");
    ask_for_input(vector1);
    printf("ベクトル2を入力してください。\n");
    ask_for_input(vector2);
    //内積の計算
    printf("内積: %d", innerProduct(vector1, vector2));
}

void ask_for_input(int *vector) {
    for (int i = 0; i < 3; ++i) {
        //それぞれ受け取り、ポインタによって格納
        scanf("%d", vector + i);
    }
}

int innerProduct(int v1[], int v2[]) {
    //問題の指定によりポインタを使わずに計算する
    return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}
