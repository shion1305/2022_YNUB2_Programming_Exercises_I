#include <stdio.h>

void print(unsigned int n);

unsigned int ask_for_input();

int main() {
    unsigned int a = ask_for_input();
    print(a);
}

void print(unsigned int n) {
    unsigned int r[10];
    int size = 0;
    while (n > 999) {
        r[size++] = n % 1000;
        n /= 1000;
    }
    printf("%d", n);
    for (int i = size - 1; i >= 0; --i) {
        printf(",%03d", r[i]);
    }
}

unsigned int ask_for_input() {
    unsigned int v;
    printf("TYPE VALUE: ");
    scanf("%u", &v);
    return v;
}
