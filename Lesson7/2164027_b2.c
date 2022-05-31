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
    fp = fopen(argv[1], "r");
    fp1 = fopen(argv[2], "r");
    char c1, c2;
    int result = 1;
    do {
        c1 = fgetc(fp);
        c2 = fgetc(fp1);
        if (c1 != c2) {
            result = 0;
            break;
        }
    } while (c1 != EOF);
    if (result) {
        printf("2つのファイルは同一です。");
    } else {
        printf("2つのファイルは同一ではありません。");
    }
}