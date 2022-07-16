#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PlayerB {
    int number;
    char name[20];
    char metaData[60];
    struct PlayerB *next;
} Player;

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

Player *query(int number, Player *data) {
    Player *query = data;
    //指定された番号のデータを探す
    while (query != NULL) {
        //指定された番号と一致するデータが見つかったらそのデータを返す
        if (query->number == number) return query;
        query = query->next;
    }
    //見つからなかったらNULLを返す
    return NULL;
}

int main(int argc, char *argv[]) {
    //コマンド引数で指定されたファイルを開く
    FILE *in = fopen(argv[1], "r");
    //線形リストを生成
    Player *data = genList(in);
    //リストをプリント
    printList(data);

    while (1) {
        //検索する番号を入力
        int number;
        printf("Enter number to search: ");
        scanf("%d", &number);
        if (number == 0)break;
        //検索する番号に該当するデータを検索
        Player *q = query(number, data);
        //検索結果をプリント
        if (q != NULL) {
            printf("%2d %-14s %s\n", q->number, q->name, q->metaData);
        } else {
            printf("---該当者はいません---\n");
        }
    }
}