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

student data[3000];
int size = 0;
int swap_count = 0, comparison_count = 0;

void sort();

//dataを交換する関数
void swap(int i1, int i2);

void read(FILE *fp);

//プロトタイプ宣言。
void print(student data[3000], int size);

void printError();

void exportCSV(FILE *fp);

//コマンド引数を指定できるようにしてmain関数のフォーマットに指定
int main(int argc, char *argv[]) {
    //コマンド引数が指定されていない場合の対策
    if (argc < 1) {
        printError();
        return 1;
    }

    {
        //import data from specified source
        FILE *fp;
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            printError();
            return 1;
        }
        read(fp);
        fclose(fp);
    }
    sort();
    print(data, size);
    printf("交換回数: %d, 比較回数: %d", swap_count, comparison_count);
    {
        FILE *fp;
        fp = fopen(argv[2], "w");
        if (fp == NULL) {
            //アクセス許可が下りなかったときにはメッセージを表示。
            printf("Export process skipped.\n");
            return 0;
        }
        exportCSV(fp);
        fclose(fp);
    }
    return 0;
}

void printError() {
    printf("File is not specified correctly...\nEXIT.");
}


/* 印刷する用の関数
 * "構造体配列とデータ数を引数として関数内で出力を行なうこと"とある。
 */

//データ読み込み用の関数
void read(FILE *fp) {
    while (fscanf(fp, "%d %s %d", &data[size].num, data[size].name, &data[size].score) != EOF) {
        size++;
    }
}

void print(student data[3000], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%4d %-20s %3d\n", data[i].num, data[i].name, data[i].score);
    }
}

void sort() {
    //loop i from 0 to (size - 1).
    //no need to loop to (size),
    //which means comparing one to one.
    for (int i = 0; i < size - 1; ++i) {
        int index = i;
        int max = data[i].score;
        int maxI = i;
        while (++index < size) {
            comparison_count++;
            if (max < data[index].score) {
                maxI = index;
                max = data[index].score;
            }
        }
        if (maxI == i)continue;
        swap(maxI, i);
    }
}

//dataの指定のindex番号同士を交換するための関数
void swap(int i1, int i2) {
    student d = data[i1];
    data[i1] = data[i2];
    data[i2] = d;
    swap_count++;
}

//CSV出力用の関数
void exportCSV(FILE *fp) {
    for (int i = 0; i < size; ++i) {
        fprintf(fp, "%d,%s,%d\n", data[i].num, data[i].name, data[i].score);
    }
}