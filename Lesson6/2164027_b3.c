#include <stdio.h>

int word_copy(char *a, char *b_in);

int main() {
    //テストケースの入力
    char target[] = "   2164027   SHION      Ichikawa";
    //結果を格納する配列の用意。
    char result[1000];
    int length = word_copy(result, target);
    while (length != 0) {
        printf("%s, length = %d\n", result, length);
        //2回目以降は第2引数にNULLを指定する
        length = word_copy(result, NULL);
    }
}

int word_copy(char *a, char *b_in) {
    static char *b;
    //NULL文字が指定されたときは以前のbを利用し、
    // 値が格納されている場合はstatic変数bを置き換える。
    if (b_in != NULL)b = b_in;
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
