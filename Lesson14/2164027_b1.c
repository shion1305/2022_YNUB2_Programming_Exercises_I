#include<stdio.h>
#include<stdlib.h>


typedef struct PlayerB {
    int number;
    char name[20];
    char metaData[60];
    struct PlayerB *right;
    struct PlayerB *left;
} Player;

//numberの探索木を作成する関数
Player *createTree(Player *target, Player *root) {
    if (root == NULL) {
        root = target;
    } else if (target->number < root->number) {
        //targetがrootより小さい場合は左に追加できる場所を探す
        root->left = createTree(target, root->left);
    } else if (target->number > root->number) {
        //targetがrootより大きい場合は右に追加できる場所を探す
        root->right = createTree(target, root->right);
    }
    return root;
}


void printIndented(Player *target, int level) {
    if (target == NULL) return;
    //インデントを表示する
    for (int i = 0; i < level; ++i) {
        printf("  ");
    }
    //プリントする
    printf("%2d %-14s %s\n", target->number, target->name, target->metaData);
}

//numberの探索木を表示する関数
void printTree(Player *root, int level) {
    if (root->right != NULL) {
        printTree(root->right, level + 1);
    }
    print(root, level);
    if (root->left != NULL) {
        printTree(root->left, level + 1);
    }
}


int main(int argc, char *argv[]) {
    //コマンド引数で指定されたファイルを開く
    FILE *in = fopen(argv[1], "r");
    //numberの探索木を生成
    Player *root = NULL;
    while (1) {
        Player *tmpP;
        tmpP = (Player *) malloc(sizeof(Player));
        //fscanfで読み込みを行う。EOFが発生したら読み込みを終了する
        if (fscanf(in, "%d %s %s", &tmpP->number, tmpP->name, tmpP->metaData) == EOF) break;
        //tmpPをnumberの探索木に追加する
        root = createTree(tmpP, root);
    }
    //numberの探索木を表示
    printTree(root, 0);
}