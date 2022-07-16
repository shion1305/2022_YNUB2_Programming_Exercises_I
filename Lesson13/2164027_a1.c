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

//線形リストに対してバブルソート
void sort() {
    int count = 1;
    Player *cur = data, *next = data->next, *prev = NULL;
    while (1) {
        //全てのデータの一通り並び替えが完了し、その間に並び替えが発生しなかった場合は終了。
        if (next == NULL) {
            if (count == 0)break;
            //並び替えがあった場合は、再び先頭からソートを行う。
            cur = data;
            next = data->next;
            prev = NULL;
            count = 0;
        }
        if (cur->number > next->number) {
            if (prev == NULL) {
                data = next;
            } else {
                prev->next = next;
            }
            cur->next = next->next;
            next->next = cur;
            count++;
        }
        prev = cur;
        cur = next;
        next = next->next;
    }
}

int main(int argc, char *argv[]) {
    //コマンド引数で指定されたファイルを開く
    FILE *in = fopen(argv[1], "r");
    //線形リストを生成
    data = genList(in);
    //バブルソートを行う
    sort();
    //リストをプリント
    printList(data);
}