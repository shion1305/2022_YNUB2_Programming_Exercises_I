#include <stdio.h>

int main() {
    int target;
    //intの最大値は2^16-1である。よって2進数に直して高々16桁、というわけである
    int r[16];
    int length = 0;
    printf("type target number:");
    scanf("%d", &target);
    while (target > 1) {
        r[length++] = target % 2;
        target /= 2;
    }
    printf("1");
    while (length-- > 0){
        printf("%d",r[length]);
    }
}