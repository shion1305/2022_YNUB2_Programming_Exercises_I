#include <stdio.h>

int main() {
    int number[10];

    for (int i = 0; i < 10; ++i) {
        scanf("%d", &number[i]);
    }

    int max = number[0], min = number[0];
    //インデックスが1~9の要素のみに対し確認すればよい。
    for (int i = 1; i < 10; ++i) {
        if (number[i] > max) {
            max=number[i];
        } else if (number[i] < min) {
            min=number[i];
        }
    }
    printf("MAX: %d",max);
    printf("MIN: %d",min);
}