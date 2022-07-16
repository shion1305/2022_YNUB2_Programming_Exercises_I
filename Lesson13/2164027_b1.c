#include <stdio.h>
#include <stdlib.h>

typedef struct PlayerB {
    int number;
    char name[20];
    char metaData[60];
    struct PlayerB *next;
} Player;

/*
 * ファイルからデータを読み込みながら線形リストを生成すること
 * （ 新しいデータがリストの手前となる様にする）
 * リストの内容を手前から表示すること
 * リストを生成する関数を作成すること
 * なお、
 * ファイルのオープンは main 関数で行う
 * main 関数はファイルポインタを引数としてこの関数を呼び出す
 * 戻り値はリストの先頭アドレス
 * リストを表示する関数を作成すること
 */

//ファイルポインタを引数として線形リストを生成する関数
Player *genList(FILE *in) {
    Player *data;
    data = NULL;
    //全ての読み込みが終わるまで繰り返す
    while (1) {
        //prepare tmpP and allocate memory for it
        Player *tmpP;
        tmpP = (Player *) malloc(sizeof(Player));
        //fscanfで読み込みを行う。EOFが発生したら読み込みを終了する
        if (fscanf(in, "%d %s %s", &tmpP->number, tmpP->name, tmpP->metaData) == EOF) break;
        //tmpPをリストの先頭に追加する
        tmpP->next = data;
        data = tmpP;
    }
    return data;
}

//線形リストをプリントする関数
void printList(Player *data) {
    Player *print = data;
    while (print != NULL) {
        printf("%2d %-14s %s\n", print->number, print->name, print->metaData);
        //次のデータを参照するために次のポインタに参照を置き換える
        print = print->next;
    }
}

int main(int argc, char *argv[]) {
    //コマンド引数で指定されたファイルを開く
    FILE *in = fopen(argv[1], "r");
    //線形リストを生成
    Player *data = genList(in);
    //リストをプリント
    printList(data);
}