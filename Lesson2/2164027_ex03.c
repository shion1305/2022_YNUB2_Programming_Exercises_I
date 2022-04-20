#include <stdio.h>
#include <math.h>

void print(int counter, double i);

void printAns(double i);

int main() {
    double x, ans = 1, tmp = 1.0;
    int counter = 1, isPositive;
    printf("INPUT VALUE:");
    scanf("%lf", &x);
    isPositive = x >= 0;
    x = fabs(x);
    print(counter, ans);
    do {
        tmp *= x;
        tmp /= counter++;
        ans += tmp;
        print(counter, ans);
    } while (tmp > 0.0000001);
    printAns(isPositive ? ans : 1 / ans);
}

void print(int counter, double i) {
    printf("%d: %.8le\n", counter, i);
}

void printAns(double i) {
    printf("Answer: %.8le\n", i);
}