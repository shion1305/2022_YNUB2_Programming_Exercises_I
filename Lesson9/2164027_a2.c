// Copyright (c) 2022 Shion Ichikawa.
// <==============================FOR VIEWERS==============================>
//       If you find software that doesn’t have a license, that generally means
//  you have no permission from the creators of the software to use, modify, or
// share the software. Although a code host such as GitHub may allow you to
// view and fork the code, this does not imply that you are permitted to use,
// modify, or share the software for any purpose.
// <=======================================================================>

#include <stdio.h>

//プロトタイプ宣言。
void print(int *target, int size, int mark1, int mark2);

void sort(int *target, int start, int end);

void swap(int *target, int i1, int i2);


//テストケース検証用の関数
//testCase10は大問通りに提示されていた10要素のデータで実験するもの
void testCase10(int i1, int i2);
//testCase10は大問通りに提示されていた32要素のデータで実験するもの
void testCase32(int i1, int i2);

//コマンド引数を指定できるようにしてmain関数のフォーマットに指定
int main(int argc, char *argv[]) {
    testCase10(0, 9);
    testCase10(1, 5);
    testCase10(2, 7);
    testCase32(0, 31);
    testCase32(19, 28);
    testCase32(5, 10);
    return 0;
}

//問題に提示されていた要素10のテストケースでの実験。
void testCase10(int i1, int i2) {
    printf("Sorting sample10 from %2d (m) to %2d (n)\n", i1, i2);
    int data[10] = {9, 1, 3, 7, 0, 5, 4, 2, 8, 6};
    sort(data, i1, i2);
    print(data, 10, i1, i2);
}

//問題に提示されていた要素32のテストケースでの実験。
void testCase32(int i1, int i2) {
    printf("Sorting sample32 from %2d (m) to %2d (n)\n", i1, i2);
    int data[32] = {7, 25, 44, 47, 55, 66, 46, 12, 20, 1, 62, 45, 63, 8, 37, 42, 99, 11, 38, 72, 19, 64, 84, 29, 51,
                    52, 60, 61, 90, 63, 88, 23};
    sort(data, i1, i2);
    print(data, 32, i1, i2);
}

//標準出力に見やすい形で出力する。
/*
 * mark1, mark2はバブルソート開始ポイントと終了ポイントを分かりやすくするためのもの。
 */
void print(int *target, int size, int mark1, int mark2) {
    printf("RESULT:[");
    for (int i = 0; i < size; ++i) {
        printf("%3d,", target[i]);
    }
    printf("]\n");
    printf("INDEX: ");
    for (int i = 0; i < size; ++i) {
        if (i == mark1 || i == mark2) printf(" *%2d", i);
        else printf("%4d", i);
    }
    printf("\n");
}

//startインデックス から endインデックスまでバブルソートを行う。
void sort(int *target, int start, int end) {
    for (int i = start; i <= end; ++i) {
        int minI = end;
        for (int j = i; j < end; ++j) {
            if (target[minI] > target[j]) {
                minI = j;
            }
        }
        //交換。
        swap(target, minI, i);
    }
}

//配列内で交換を行う。
void swap(int *target, int i1, int i2) {
    int tmp = target[i1];
    target[i1] = target[i2];
    target[i2] = tmp;
}