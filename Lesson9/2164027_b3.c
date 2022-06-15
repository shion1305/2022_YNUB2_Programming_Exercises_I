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

void sortInitial(student data[3000], int size);

void sort(int L, int R, student data[3000]);


void exportCSV(FILE *fp, student data[3000], int size);

void swap(int i1, int i2, student data[3000]);

//コマンド引数を指定できるようにしてmain関数のフォーマットに指定
int main(int argc, char *argv[]) {
    //コマンド引数が指定されていない場合の対策
    if (argc < 3) {
        printf("Arguments are not specified correctly...\nEXIT.");
        return 1;
    }
    //ファイルポインターの用意。
    FILE *fp;
    printf("入力ファイル: %s\n", argv[1]);
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Input file is not specified correctly...\nEXIT.");
        return 1;
    }
    FILE *out;
    printf("出力ファイル: %s\n", argv[2]);
    out = fopen(argv[2], "w");
    if (out == NULL) {
        printf("Output file is not specified correctly...\nEXIT.");
        return 1;
    }
    //データ格納用の変数の用意。
    int size = 0;
    student data[3000];
    while (fscanf(fp, "%d %s %d", &data[size].num, data[size].name, &data[size].score) != EOF) {
        size++;
    }
    fclose(fp);
    sortInitial(data, size);
    exportCSV(out, data, size);
    fclose(out);
    fclose(fp);
    return 0;
}

/* 印刷する用の関数
 * "構造体配列とデータ数を引数として関数内で出力を行なうこと"とある。
 */

void sortInitial(student data[3000], int size) {
    return sort(0, size - 1, data);
}

void sort(int L, int R, student data[3000]) {
    int l = L, r = R;
    student s = data[(L + R) / 2];
    while (l <= r) {
        while (data[l].score > s.score || (data[l].score == s.score && data[l].num < s.num)) {
            l++;
        }
        while (data[r].score < s.score || (data[r].score == s.score && data[r].num > s.num)) {
            r--;
        }
        if (l < r) {
            swap(l, r, data);
        }
        if (l <= r) l++, r--;
    }
    if (r > L) sort(L, r, data);
    if (R > l) sort(l, R, data);
}

//dataの指定のindex番号同士を交換するための関数
void swap(int i1, int i2, student data[3000]) {
    student d = data[i1];
    data[i1] = data[i2];
    data[i2] = d;
}

//CSV出力用の関数
void exportCSV(FILE *fp, student data[3000], int size) {
    for (int i = 0; i < size; ++i) {
        fprintf(fp, "%d,%s,%d\n", data[i].num, data[i].name, data[i].score);
    }
}