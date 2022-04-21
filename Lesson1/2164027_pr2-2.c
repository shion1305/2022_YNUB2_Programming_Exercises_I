#include <stdio.h>

void print(int a, int b);

int main() {
    int a = 3, b = 7;
    print(a, b);
    a += b;
    b = a - b;
    a -= b;
    //上の一行が間違えていたため修正。
    print(a, b);
    return 0;
}

void print(int a, int b) {
    printf("a=%d,b=%d\n", a, b);
}