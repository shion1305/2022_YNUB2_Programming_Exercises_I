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
    int r = 0;
    for (int i = 1; i <= n; ++i) {
        r += i * i;
    }
    return r;
}