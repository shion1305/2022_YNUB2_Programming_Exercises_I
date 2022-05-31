#include <stdio.h>


int main() {
    char dataTmp[300];
    int counter = 1;
    while (gets(dataTmp) != NULL) {
        printf("%3d %s\n", counter++, dataTmp);
    }
}