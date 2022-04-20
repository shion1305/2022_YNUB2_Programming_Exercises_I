#include <stdio.h>

void print(int in, long long int i);

void invalid(int i);

void warn(int i);

int main() {
    int in;
    while (1) {
        printf("TYPE YOUR INPUT:");
        scanf("%d", &in);
        if (in > 20) {
            warn(in);
            continue;
        }
        break;
    }
    if (in < 0) {
        invalid(in);
        return 0;
    }
    if (in == 0) {
        print(0, 1);
        return 0;
    }
    long long int r = 1;
    for (int i = 2; i <= in; i++) {
        r = r * i;
    }
    print(in, r);
    return 0;
}


void print(int in, long long int i) {
    printf("%d! is... %lld\n", in, i);
}

void warn(int i) {
    printf("ERROR, %d is too large. input integer lower than 21...\n", i);
}

void invalid(int i) {
    printf("ERROR, %d is invalid. Input must be 0 or positive value.\n", i);
}