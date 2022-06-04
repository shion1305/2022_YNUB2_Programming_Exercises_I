#include <stdio.h>


int main() {
//    //データを一時保存するための変数。
//    char dataTmp[800];
//    //ヒット回数をカウントするための関数。
//    int counter = 1;
//
//    //今回は標準入力、またはリダイレクトによって入力を受け取るが、
//    //どちらの場合もプログラム側からみると標準入力での入力なので
//    //gets関数でファイルの中身を正常に受け取ることができる。
//    //gets関数は1行を読み込む関数だ(次に\nが出るまで)
//    //今回は行数をカウントして行番号を付けるプログラムであるので、
//    //gets関数の利用は適正であるだろう。
//    while (gets(dataTmp) != NULL) {
//        printf("%3d %s\n", counter++, dataTmp);
//    }

/* としたいところではあったが、このコードは安全ではない。
 * なぜなら、getsは改行コードが存在するまで読み込む。
 * つまり、このコードだと800文字以上を上回るとシステムから割り振られた
 * メモリアドレスの範囲を超えて実行されてしまうことになる。
 * 一番安全なのは、getcで1文字ごとに受け取って着実に判定していく方法である。
 * この場合だと、char dataTmp[]からあふれてしまう危険性がなくなり、
 * プログラムの信頼性が高まる。
 */
    char tmp;
    int counter = 1;
    int flag = 0;
    printf("%2d: ", counter);
    while ((tmp = getchar()) != EOF) {
        if (flag) {
            counter++;
            printf("%2d: ", counter);
            flag = 0;
        }
        putchar(tmp);
        if (tmp == '\n') {
            flag = 1;
        }
    }
}