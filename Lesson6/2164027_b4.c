#include <stdio.h>

int count_key(char a[], char b[]);

void ask_for_input(char target[]);

int main() {

    char target[1000];
    char query[1000];
    printf("Input Target String:");
    ask_for_input(target);
    printf("Input Query String: ");
    ask_for_input(query);
    int count = count_key(target, query);
    printf("FOUND %s %d times in String\n", query, count);
}

int count_key(char a[], char b[]) {
    int count = 0;
    int lA = 0, lB = 0;
    while (a[lA] != '\0') lA++;
    while (b[lB] != '\0') lB++;
    for (int i = 0; i <= lA - lB; ++i) {
        int isSame = 1;
        for (int j = 0; j < lB; ++j) {
            if (a[i + j] != b[j]) {
                isSame = 0;
                break;
            }
        }
        if (isSame) {
            count++;
            i += lB;
        }
    }
    return count;
}

void ask_for_input(char target[]) {
    gets(target);
}
