#include <stdio.h>

int str_copy(char *a, char *b);

int main() {
    char test[] = "   2164027 Shion Ichikawa";
    char result[3000];
    printf(" INPUT: %s\n", test);
    int len = str_copy(test, result);
    printf("OUTPUT: %s, length=%d", result, len);
}


/*
 * # 入力引数について
 * *a がコピーする文字列の先頭のポインタ
 * *b がコピー先の文字列先頭のポインター
 */

int str_copy(char *a, char *b) {
    int length = 0;
    do {
        /*
         * 文字数にカウントしない文字として改行コードが挙げられているが、
         * 一般的に文字(character)としてカウントできるもの、は、制御文字以外であるであろう。
         * 制御文字以外の文字は32~126であり、この範囲である場合のみにlengthの値を増やす処理を行うこととする。
         */
        if (*a > 31 && *a < 127)length++;
        *(b++) = *(a++);
    } while (*(a) != '\0');
    //最後に\0を入れることを忘れずに
    *b = '\0';
    return length;
}
