#include <stdio.h>

//Euclidean Algorithm

int process(int a, int b);

//Recursive Process goes here.
int start(int a, int b);

int ask_for_input();

int main() {
    printf("1st Number...\n");
    int a = ask_for_input();
    printf("2nd Number...\n");
    int b = ask_for_input();
    printf("GCD of these values are... %d", start(a, b));
}


int start(int a, int b) {
    if (a < b) {
        return process(b, a);
    }
    return process(a, b);
}

//assert a>=b
int process(int a, int b) {
    int v = a % b;
    if (!v) {
        return b;
    }
    return process(b, v);
}

int ask_for_input() {
    int v;
    printf("TYPE VALUE: ");
    scanf("%d", &v);
    return v;
}
