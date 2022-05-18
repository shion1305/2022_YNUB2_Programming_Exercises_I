#include <stdio.h>
#include <stdlib.h>

#define EOD -1

int getMax(int array[]);

int main() {
    /*
     * 10のテストケースで確かめよう。
     */
    for (int i = 0; i < 10; ++i) {
        //乱数を初期化
        srand(i);
        /*
         * 大きさが100~109のテストケースを乱数によって生成する。
         */
        int size = 100 + rand() % 10;
        //テストケース用の配列を用意する。
        int test[size];
        printf("=================TEST CASE=================\n");
        for (int i = 0; i < size - 1; ++i) {
            //乱数を代入する。
            test[i] = rand();
            //出力する。
            printf("%d, ", test[i]);
        }
        test[size - 1] = -1;
        printf("\n");
        printf("===========================================\n");
        //テストケースに対してgetMax関数を実行する
        printf("MAX VALUE IS %d\n", getMax(test));
    }
}

int getMax(int array[]) {
    int max = array[0];
    //EODが最初に来るのはあり得ないが一応例外処理。
    if (max == EOD) {
        printf("ILLEGAL INPUT\n");
        return EOD;
    }
    int position = 0;
    //終わりまで繰り替えす。
    while (array[++position] != EOD) {
        //仮の最大値より対象が大きければ、仮の最大値を更新する
        if (array[position] > max) {
            max = array[position];
        }
    }
    return max;
}