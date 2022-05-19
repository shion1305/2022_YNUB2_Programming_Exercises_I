#include <stdio.h>

int innerProduct(int *v1, int *v2);

int main() {
    int vector1[3] = {1, 1, 1};
    int vector2[3] = {2, 2, 2};
    printf("%d", innerProduct(&vector1[0], &vector2[0]));
}

int innerProduct(int v1[], int v2[]) {
    return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}
