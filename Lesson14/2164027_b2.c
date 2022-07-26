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
  } else if (target->number < root->number) {//targetがrootより小さい場合は左に追加できる場所を探す
    root->left = createTree(target, root->left);
  } else if (target->number > root->number) {//targetがrootより大きい場合は右に追加できる場所を探す
    root->right = createTree(target, root->right);
  }
  return root;
}

void printElement(Player *target) {
  if (target == NULL) {
    printf("        該当者はいません---\n");
    return;
  }
  printf("%2d %-14s %s\n", target->number, target->name, target->metaData);
}

void printIndented(Player *target, int level) {
  if (target == NULL) return;
  //インデントを表示する
  for (int i = 0; i < level; ++i) {
    printf("  ");
  }
  printElement(target);
}


//numberの探索木を表示する関数
void printTree(Player *root, int level) {
  if (root == NULL) {
    printf("データはありません\n");
    return;
  }
  if (root->right != NULL) {
    printTree(root->right, level + 1);
  }
  printIndented(root, level);
  if (root->left != NULL) {
    printTree(root->left, level + 1);
  }
}

//探索木から指定のnumberの要素を検索してポインタを返す関数
Player *search(int number, Player *root) {
  if (root == NULL)return NULL;
  if (number < root->number) {
    return search(number, root->left);
  } else if (number > root->number) {
    return search(number, root->right);
  } else {
    return root;
  }
}


//探索木の要素を削除する関数
int deleteNode(int number, Player **root) {
  Player *parent = NULL, *target = *root;
  //まず削除対象とその親の顔も見てみたい
  while (1) {
    if (target == NULL) {
      printf("見つかりませんでした\n");
      return 0;
    }
    //numberの値を探索するため、探索位置の値によって探索方向を変える
    if (number < target->number) {
      parent = target;
      target = target->left;
    } else if (number > target->number) {
      parent = target;
      target = target->right;
    } else break; //削除対象を発見したらループを抜ける
  }
  //削除対象とその親の顔が見えた!!(親がない場合はNULL) 削除に移行する
  if (target->left == NULL && target->right == NULL) {//targetが子供を持たない場合
    if (parent == NULL) {
      *root = NULL;//削除対象がrootの場合
    } else if (parent->left == target) {
      parent->left = NULL;//削除対象がparentの左の子供の場合
    } else {
      parent->right = NULL;//削除対象がparentの右の子供の場合
    }
  } else if (target->left == NULL) {//targetが右のみを持つ場合
    if (parent == NULL) {//targetがrootの場合
      *root = target->right;
    } else if (parent->left == target) {
      parent->left = target->right;
    } else {
      parent->right = target->right;
    }
  } else if (target->right == NULL) {//targetが左のみを持つ場合
    if (parent == NULL) {//targetがrootの場合
      *root = target->left;
    } else if (parent->left == target) {
      parent->left = target->left;
    } else {
      parent->right = target->left;
    }
  } else {//targetが両方を持つ場合
    Player *min = target->right, *minParent = target;
    while (min->left != NULL) {//target配下の右側の最小値を探す
      minParent = min;
      min = min->left;
    }
    //targetの位置にminを入れ直した上でtargetを削除する
    if (parent == NULL) {
      *root = min;
    } else {
      if (parent->left == target) {
        parent->left = min;
      } else {
        parent->right = min;
      }
    }
    if (minParent != target) {
      minParent->left = min->right;
      min->left = target->left;
      min->right = target->right;
    } else {
      min->left = target->left;
    }
  }
  free(target);
  return 1;
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

  while (1) {
    printf("1: 探索 2: 削除 3: 表示 4: 終了\n");
    int input;
    scanf("%d", &input);
    switch (input) {
      case 1:
        printf("探索するnumberを入力してください\n");
        scanf("%d", &input);
        printElement(search(input, root));
        break;
      case 2:
        printf("削除するnumberを入力してください\n");
        scanf("%d", &input);
        if (deleteNode(input, &root)) {
          printf("削除しました\n");
        } else {
          printf("---該当者が見つかりませんでした---\n");
        }
        break;
      case 3:
        //探索木を表示
        printTree(root, 0);
        break;
      case 4:
        //終了
        return 0;
    }
  }
}