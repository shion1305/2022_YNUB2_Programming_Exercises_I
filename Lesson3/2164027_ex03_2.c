#include <stdio.h>

int sum(int n);

int main() {
    int in;
    while (1) {
        scanf("%d", &in);
        printf("%d\n", sum(in));
    }
}


int sum(int n) {
    static int preN, preS;

    if (preN == n) {
        printf("Return cache data.\n");
        return preS;
    }
    preN = n;
    preS = 0;
    for (int i = 1; i <= n; ++i) {
        preS += i * i;
    }
    return preS;
}