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
    //gradeを別変数として設定することは、データの整合性を取るにおいて問題が発生する可能性が高い。
    //バグ予防としてgradeは設定しない。
} student;

student data[3000];
int size = 0;

void sort();

//dataを交換する関数
void swap(int i1, int i2);

void read(FILE *fp);

void printError();

void exportCSV(FILE *fp);

int classifyGrade(int s);

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
        printf("入力ファイル : %s\n", argv[1]);
        read(fp);
        fclose(fp);
    }
    sort();
    {
        FILE *fp;
        fp = fopen(argv[2], "w");
        if (fp == NULL) {
            //アクセス許可が下りなかったときにはメッセージを表示。
            printf("出力ファイルとして%sを指定できませんでした。\n", argv[2]);
            return 0;
        }
        printf("出力ファイル : %s\n", argv[2]);
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

void sort() {
    //loop i from 0 to (size - 1).
    //no need to loop to (size),
    //which means comparing one to one.
    for (int i = 0; i < size - 1; ++i) {
        int g = classifyGrade(data[i].score);
        int index = i;
        int max = g;
        int maxI = i;
        while (++index < size) {
            g = classifyGrade(data[index].score);
            if (max < g) {
                maxI = index;
                max = g;
            } else if (max == g) {
                if (data[index].num < data[maxI].num) {
                    maxI = index;
                }
            }
        }
        if (maxI == i)continue;
        swap(maxI, i);
    }
}

int classifyGrade(int s) {
    if (s < 60)return 1;
    if (s < 70)return 2;
    if (s < 80)return 3;
    if (s < 90)return 4;
    return 5;
}

char getGradeCharacter(int s) {
    if (s < 60)return 'D';
    if (s < 70)return 'C';
    if (s < 80)return 'B';
    if (s < 90)return 'A';
    return 'S';
}

//dataの指定のindex番号同士を交換するための関数
void swap(int i1, int i2) {
    student d = data[i1];
    data[i1] = data[i2];
    data[i2] = d;
}

//CSV出力用の関数
void exportCSV(FILE *fp) {
    for (int i = 0; i < size; ++i) {
        fprintf(fp, "%d,%s,%c\n", data[i].num, data[i].name, getGradeCharacter(data[i].score));
    }
}