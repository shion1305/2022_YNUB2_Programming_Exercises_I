#include <stdio.h>

void print(int a, int b);

int main() {
    int a = 3, b = 7, c;
    print(a, b);
    c = a;
    a = b;
    b = c;
    print(a, b);
    return 0;
}

void print(int a, int b) {
    printf("a=%d,b=%d\n", a, b);
}