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
void print(student data[1000], int size);

//コマンド引数を指定できるようにしてmain関数のフォーマットに指定
int main(int argc, char *argv[]) {
    //コマンド引数が指定されていない場合の対策
    if (argc < 1) {
        printf("File is not specified correctly...\nEXIT.");
    }
    //ファイルポインターの用意。
    FILE *fp;
    fp = fopen(argv[1], "r");
    //データ格納用の変数の用意。
    int size = 0;
    student data[1000];
    while (fscanf(fp, "%d %s %d", &data[size].num, data[size].name, &data[size].score) != EOF) {
        size++;
    }
    fclose(fp);
    print(data, size);
    return 0;
}

/* 印刷する用の関数
 * "構造体配列とデータ数を引数として関数内で出力を行なうこと"とある。
 */

void print(student data[1000], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%4d %-20s %3d\n", data[i].num, data[i].name, data[i].score);
    }
}