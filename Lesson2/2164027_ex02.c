#include <stdio.h>

void print(int i, int j);

int main() {
    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j < 10; ++j) {
            int r = i * j;
            if (r == 24) {
                print(i, j);
                break;
            } else if (r > 24) {
                break;
            }
        }
    }
}

void print(int i, int j) {
    printf("Answer: %d %d\n", i, j);
}