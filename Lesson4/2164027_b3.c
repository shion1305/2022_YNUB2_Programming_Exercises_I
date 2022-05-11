#include <stdio.h>

//Euclidean Algorithm

void print(int n);

//Recursive Process goes here.
int ask_for_input();

int main() {
    int a = ask_for_input();
    print(a);
}

//assert a>=b
void print(int n) {
    if (n > 999) {
        print(n / 1000);
        printf(",%d", n%1000);
    } else {
        printf("%d",n);
    }
}

int ask_for_input() {
    int v;
    printf("TYPE VALUE: ");
    scanf("%d", &v);
    return v;
}
