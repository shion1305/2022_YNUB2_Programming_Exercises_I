#include <stdio.h>

void print(int counter, double i);

void analyze(double i);


void process() {
    double height, weight, sWeight, oRate;
    int gender;
    printf("身長[m] = ");
    scanf("%lf", &height);
    printf("体重[kg] = ");
    scanf("%lf", &weight);
    printf("男性:1 女性:2 男女共通:その他 = ");
    scanf("%d", &gender);
    double sBMI;
    switch (gender) {
        case 1:
            sBMI = 22.0;
            break;
        case 2:
            sBMI = 21.0;
            break;
        default:
            sBMI = 21.5;
    }
    sWeight = height * height * sBMI;
    oRate = 100 * weight / sWeight - 100;
    printf("標準体重[kg] = %lf\n", sWeight);
    printf("肥満度[%] = %lf\n", oRate);
    analyze(oRate);
    printf("\n");
}

void analyze(double i) {
    if (i >= 10) {
        printf("太り過ぎ\n");
    } else if (i <= -10) {
        printf("痩せ過ぎ\n");
    } else {
        printf("標準\n");
    }
}

int main() {
    while (1) {
        process();
    }
}
