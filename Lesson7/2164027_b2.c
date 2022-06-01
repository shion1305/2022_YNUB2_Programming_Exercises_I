#include <stdio.h>


int main(int argc, char *argv[]) {
    //コマンド引数に指定されたファイル名をそれぞれ出力。
    printf("入力ファイル1: %s\n",argv[1]);
    printf("入力ファイル2: %s\n",argv[2]);
    //ファイルポインタの用意
    FILE *fp, *fp1;
    if (argc < 3) {
        printf("Arguments are insufficient.\n");
        return 0;
    }
    //コマンド引数から読み込んでそれぞれのファイルを開く処理をする。
    fp = fopen(argv[1], "r");
    fp1 = fopen(argv[2], "r");
    //これから読み込んで検証する際に読み込んだcharを一時保存するための変数。
    char c1, c2;
    //比較した後に結果を保存するための変数。
    int result = 1;
    do {
        //それぞれ一時変数に1文字ずつcharを取り込んでいく。
        c1 = fgetc(fp);
        c2 = fgetc(fp1);
        if (c1 != c2) {
            result = 0;
            break;
        }
        //EOFになるまで続行する。
    } while (c1 != EOF);

    // while文を抜けてこのif文が実行されるのは
    // 結果が分かってresultで分かっているとき。
    //よって最後はresultの値で出力内容を条件分岐しよう。
    if (result) {
        printf("2つのファイルは同一です。");
    } else {
        printf("2つのファイルは同一ではありません。");
    }
}