// Copyright (c) 2022 Shion Ichikawa.
// <==============================FOR VIEWERS==============================>
//       If you find software that doesn’t have a license, that generally means
//  you have no permission from the creators of the software to use, modify, or
// share the software. Although a code host such as GitHub may allow you to
// view and fork the code, this does not imply that you are permitted to use,
// modify, or share the software for any purpose.
// <=======================================================================>

#include <stdio.h>

typedef struct {
    int num;        /* 学籍番号 */
    char name[20];  /* 氏名 */
    int score;      /* 得点 */
} student;

int sortInitial(student data[3000], int size);

//プロトタイプ宣言。
void print(student data[3000], int size);

void swap(int i1, int i2, student data[3000]);

int sort(int L, int R, student data[3000]);

int compare = 0;

//コマンド引数を指定できるようにしてmain関数のフォーマットに指定
int main(int argc, char *argv[]) {
    //コマンド引数が指定されていない場合の対策
    if (argc < 1) {
        printf("File is not specified correctly...\nEXIT.");
        return 1;
    }
    //ファイルポインターの用意。
    FILE *fp;
    fp = fopen(argv[1], "r");
    //データ格納用の変数の用意。
    int size = 0;
    student data[3000];
    while (fscanf(fp, "%d %s %d", &data[size].num, data[size].name, &data[size].score) != EOF) {
        size++;
    }
    fclose(fp);
    printf("BEFORE: \n");
    print(data, size);
    int count = sortInitial(data, size);
    printf("---------------\n");
    printf("AFTER: \n");
    print(data, size);
    printf("compare: %3d, swap: %3d", compare, count);
    return 0;
}

/* 印刷する用の関数
 * "構造体配列とデータ数を引数として関数内で出力を行なうこと"とある。
 */

void print(student data[3000], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%4d %-20s %3d\n", data[i].num, data[i].name, data[i].score);
    }
}

int sortInitial(student data[3000], int size) {
    return sort(0, size - 1, data);
}

int sort(int L, int R, student data[3000]) {
    int count = 0;
    int l = L, r = R, s = data[(L + R) / 2].score;
    while (l <= r) {
        compare += 2;
        while (data[l].score > s) {
            l++;
            compare++;
        }
        while (data[r].score < s) {
            r--;
            compare++;
        }
        if (l < r) {
            swap(l, r, data);
            count += 1;
        }
        if (l <= r) l++, r--;
    }
    if (r > L) count += sort(L, r, data);
    if (R > l) count += sort(l, R, data);
    return count;
}

//dataの指定のindex番号同士を交換するための関数
void swap(int i1, int i2, student data[3000]) {
    student d = data[i1];
    data[i1] = data[i2];
    data[i2] = d;
}
