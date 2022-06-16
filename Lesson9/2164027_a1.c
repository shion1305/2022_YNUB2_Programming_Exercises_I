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

//プロトタイプ宣言。
void print(FILE *fp, student data[3000], int size);

void sort(student data[3000], int size, int *count_compare, int *count_swap,int *count_swap_min);

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
    int count_compare = 0, count_swap = 0, count_swap_min = 0;
    sort(data, size, &count_compare, &count_swap,&count_swap_min);
    print(out, data, size);
    printf("比較回数: %5d,入れ替え回数: %5d(%5d)",count_compare,count_swap,count_swap_min);
    fclose(out);
    fclose(fp);
    return 0;
}

/* 印刷する用の関数
 * "構造体配列とデータ数を引数として関数内で出力を行なうこと"とある。
 */

void print(FILE *fp, student data[3000], int size) {
    for (int i = 0; i < size; ++i) {
        fprintf(fp, "%4d %-20s %3d\n", data[i].num, data[i].name, data[i].score);
    }
}

void sort(student data[3000], int size, int *count_compare, int *count_swap, int *count_swap_min) {
    int level = 1;
    do {
        int position = 0;
        student sorted[3000];
        while (position + level < size) {
            int p1 = 0, p2 = 0, index = position;
            int p2Max = size - position - level;
            if (p2Max > level) p2Max = level;
            do {
                (*count_compare)++;
                if (data[position + p1].score < data[position + p2 + level].score)
                    sorted[index++] = data[position + p1++];
                else sorted[index++] = data[position + p2++ + level];
            } while (p1 < level && p2 < p2Max);
            while (p1 < level) sorted[index++] = data[position + p1++];
            while (p2 < p2Max) sorted[index++] = data[position + p2++ + level];
            position += level;
            position += p2Max;
        }
        (*count_swap) += position;
        for (int i = 0; i < position; ++i) {
            if (data[i].num != sorted[i].num) {
                (*count_swap_min)++;
                data[i] = sorted[i];
            }
        }
        level *= 2;
    } while (size >= level);
}