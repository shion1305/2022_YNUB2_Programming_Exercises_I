/*
 * Copyright (c) 2022 Shion Ichikawa.
 * <==============================FOR VIEWERS==============================>
 *      If you find software that doesn’t have a license, that generally means
 * you have no permission from the creators of the software to use, modify, or
 * share the software. Although a code host such as GitHub may allow you to
 * view and fork the code, this does not imply that you are permitted to use,
 * modify, or share the software for any purpose.
 * <=======================================================================>
 */
#include <stdio.h>


int main() {
    char tmp[512];
    /**2変数を状態管理で用いる
     * isComment 現在位置がコメントであれば1
     * isString 現在位置がStringであれば1
     */
    int isComment = 0;
    int isString = 0;
    while (fgets(tmp, 512, stdin) != NULL) {
        for (int i = 0; i < 512; ++i) {
            if (tmp[i] == '\0') break;
            // 終わりに来た時はbreakで抜ける
            if (!isComment && tmp[i] == '"') {
                //`\"`でないことを確認する
                //もしStringの開始/終了であるならばisStringを切り替える
                if ((i < 1 || tmp[i - 1] != '\\') && (isString)) {
                    isString = 0;
                } else {
                    isString = 1;
                }
            } else if (isString) {}
                //現在位置がソースコード内
            else if (tmp[i] == '/' && tmp[i + 1] == '/') {
                //コメントラインである場合、改行してbreakで無視
                printf("\n");
                break;
            } else if (tmp[i] == '/' && tmp[i + 1] == '*') {
                //複数行コメントのはじめである場合
                isComment = 1;
                //カーソルを/*の後に進める
                i++;
                continue;
            } else if (tmp[i] == '*' && tmp[i + 1] == '/') {
                //複数行コメントの終わりである時
                isComment = 0;
                //カーソルを*/の後に進める
                i++;
                continue;
            }
            //プリント
            if (!isComment) printf("%c", tmp[i]);
        }
    }
}