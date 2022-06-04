#include <stdio.h>


int main() {
    /*
     * 今回のプログラムでは、`//`を検知し、`//`の後を無視する、というコードを書けばよい。
     * strstrを使うことも可能だが、とりあえずstrstrを使わずにやってみる
     */
    char tmp[512];
    //今回は標準入力から読み込む
    while (fgets(tmp, 512, stdin) != NULL) {
        for (int i = 0; i < 512; ++i) {
            //終わりに来た時はbreakで抜ける
            if (tmp[i] == '\0') {
                break;
            } else if (tmp[i] == '/' && tmp[i + 1] == '/') {
                break;
            }
            printf("%c", tmp[i]);
        }
    }
}