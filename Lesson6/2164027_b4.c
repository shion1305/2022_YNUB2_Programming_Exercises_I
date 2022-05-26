#include <stdio.h>

int count_key(char a[], char b[]);

void ask_for_input(char target[]);

int main() {
    //検索される文章を格納する変数と、検索クエリを格納する変数をそれぞれ用意。
    char target[1000], query[1000];
    printf("Input Target String:");
    ask_for_input(target);
    printf("Input Query String: ");
    ask_for_input(query);

    //関数count_keyを使ってヒット数をカウントする
    int count = count_key(target, query);

    printf("FOUND %s %d times in String\n", query, count);
}

int count_key(char a[], char b[]) {
    //ヒット数を格納する変数
    int count = 0;

    //aとbの長さを格納する変数
    int lA = 0, lB = 0;

    //aとbの長さをそれぞれ計測してみる。
    while (a[lA] != '\0') lA++;
    while (b[lB] != '\0') lB++;
    printf("%d\n", lA);
    printf("%d\n", lB);
    //不要な操作がないよう適正な範囲でiを回して確認する
    //(例えばaの長さが6,bの長さが4の時、iを3以上で動かすのは無駄である。)
    for (int i = 0; i <= lA - lB; ++i) {
        //完全一致かを確認するためのbool的変数。
        int isSame = 1;
        //最初からチェックしていこう
        for (int j = 0; j < lB; ++j) {
            //もし違うものがあったら...
            if (a[i + j] != b[j]) {
                isSame = 0;
                break;
            }
        }
        //もし完全一致していたら...
        if (isSame) {
            //ヒットしたことを記録する
            count++;
            //重複カウントすることの内容にiの位置を適切な位置へ移す。
            //また、この後に+1されることを考慮する。
            i += (lB - 1);
        }
    }
    return count;
}


//ask_for_input関数を作ることでできるだけDRYなコードを書く。
void ask_for_input(char target[]) {
    gets(target);
}
