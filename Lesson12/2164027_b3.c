#include <stdio.h>

#define PLACES 5
#define GOAL 4
//経路情報を、それぞれどことつながっているかを記すことで与える。子配列のインデックス番号はポイントを、子配列の[0]は接続数を、[1~接続する]は接続しているポイントを記している。
int data[][PLACES] = {{2, 1, 2},
                      {4, 0, 2, 3, 4},
                      {3, 0, 1, 3},
                      {3, 1, 2, 4},
                      {2, 1, 3}};

//resultは場所ごとにstep数が入った配列なので、forループでそれぞれのステップで入れる所を探し出し順番にプリントする。
void printR(int result[PLACES], int step) {
    for (int i = 1; i <= step; ++i) {
        for (int j = 0; j < PLACES; ++j) {
            if (result[j] == i) {
                printf("%d ", j);
                break;
            }
        }
    }
    printf("\n");
}

//再帰的に確認するための関数。ナップサック問題のアルゴリズムを用いて効率的に検証する。
void check(int point, int result[PLACES], int step) {
    result[point] = step;
    if (point == GOAL) {
        printR(result, step);
    } else {
        for (int i = 1; i <= data[point][0]; ++i) {
            if (result[data[point][i]] == 0)check(data[point][i], result, step + 1);
        }
    }
    result[point] = 0;
}

//checkを0,0,0と空配列を渡すことでスタートさせる。
int main() {
    int result[PLACES] = {0,};
    check(0, result, 1);
}