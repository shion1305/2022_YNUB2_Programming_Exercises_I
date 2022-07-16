#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PlayerB {
    int number;
    char name[20];
    char metaData[60];
    struct PlayerB *next;
} Player;
Player *data;

//ファイルポインタを引数として線形リストを生成する関数
Player *genList(FILE *in) {
    Player *d;
    d = NULL;
    //全ての読み込みが終わるまで繰り返す
    while (1) {
        //prepare tmpP and allocate memory for it
        Player *tmpP;
        tmpP = (Player *) malloc(sizeof(Player));
        //fscanfで読み込みを行う。EOFが発生したら読み込みを終了する
        if (fscanf(in, "%d %s %s", &tmpP->number, tmpP->name, tmpP->metaData) == EOF) break;
        //tmpPをリストの先頭に追加する
        tmpP->next = d;
        d = tmpP;
    }
    return d;
}

//線形リストをプリントする関数
void printList(Player *d) {
    Player *print = d;
    while (print != NULL) {
        printf("%2d %-14s %s\n", print->number, print->name, print->metaData);
        //次のデータを参照するために次のポインタに参照を置き換える
        print = print->next;
    }
}

int delete(int number) {
    //もしdataが存在しない場合
    if (data == NULL) return 0;

    Player *query = data->next, *prev = data;

    //もし線形リストの先頭が削除対象の場合
    if (data->number == number) {
        //先頭を次のデータに置き換える
        data = data->next;
        free(prev);
        return 1;
    }
    //指定された番号のデータを探す
    while (query != NULL) {
        if (query->number == number) {
            //指定された番号のデータが見つかったらそのデータを削除する
            prev->next = query->next;
            free(query);
            return 1;
        }
        prev = query;
        query = query->next;
    }
    //見つからなかったら0を返す
    return 0;
}

int main(int argc, char *argv[]) {
    //コマンド引数で指定されたファイルを開く
    FILE *in = fopen(argv[1], "r");
    //線形リストを生成
    data = genList(in);
    //リストをプリント
    printList(data);

    while (1) {
        //検索する番号を入力
        int number;
        printf("番号を入力してください: ");
        scanf("%d", &number);
        //0を入力されたら終了
        if (number == 0)break;
        //指定された番号のデータが見つかったら削除する
        if (delete(number)) {
            printf("---削除しました---\n");
        } else {
            printf("---該当者はいません---\n");
        }
        printList(data);
    }
}