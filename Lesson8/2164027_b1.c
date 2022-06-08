#include <stdio.h>

typedef struct {
    int num;        /* 学籍番号 */
    char name[20];  /* 氏名 */
    int score;      /* 得点 */
} student;


//プロトタイプ宣言。
void print(student data[1000], int size);



int main() {

    //ファイルポインターの用意。
    FILE *fp;
    fp = fopen("../Lesson8/data_8.txt", "r");
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