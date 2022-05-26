#include <stdio.h>

int word_copy(char *a, char *b);

int main() {
    //テストケースの入力
    char target[] = "   b2164027 SHION Ichikawa";
    printf("INPUT: \"%s\"\n\n", target);
    //結果を格納する配列の用意。
    char result[1000];
    int length = word_copy(result, target);
    printf("%s, length = %d\n", result, length);
}

int word_copy(char *a, char *b) {
    //アドレス位置の文字列が' 'であった時にスキップする。
    while (*b == ' ')b++;
    //結果の長さを計算するようのint変数
    int length = 0;
    //*bが空白でない、かつ終了文字でない時にポインタをインクリメントする。
    while (*b != ' ' && *b != '\0') {
        *(a++) = *(b++);
        length++;
    }
    //結果の末尾を終了文字にする。
    *a = '\0';
    //文字列の長さを返すこと、と要件として指定されているので、しっかりlengthを返す。
    return length;
}
