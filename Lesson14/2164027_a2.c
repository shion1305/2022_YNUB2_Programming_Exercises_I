#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define CAPACITY 500

struct Word {
  struct Word *left, *right;
  int count;
  char word[CAPACITY];
};
typedef struct Word Word;


Word *createWord(char *str) {

  Word *newWord;
  //新しいWordを確保する
  newWord = (Word *) malloc(sizeof(Word));
  strcpy(newWord->word, str);
  newWord->count = 1;
  newWord->right = newWord->left = NULL;
  return newWord;
}

//ポインタのポインタを引数とする
//探索木にWordを追加する
Word *addWord(Word **root, char *str) {
  Word **tmp = *root;
  //何も探索木がない場合は新しくWordを作成する
  if (*root == NULL) {
    *root = createWord(str);
    return *root;
  }

  while (*tmp != NULL) {
    //strcmpを使って比較する
    int result = strcmp(str, (*tmp)->word);
    if (result == 0) {
      //対象を見つけた場合はcountを1増やす
      ((*tmp)->count)++;
      return *tmp;
    }
    if (result > 0) {
      tmp = &(*tmp)->right;
    } else {
      tmp = &(*tmp)->left;
    }
  }
  //ここを抜けるのは適切な位置に対象が見つからなかった場合。
  //新しくWordを作成してtmpに指すポインタを更新する
  *tmp = createWord(str);
  return *tmp;
}

void printResult(Word *n) {
  if (n == NULL) return;
  printf("%s: %d\n", n->word, n->count);
  printResult(n->left);
  printResult(n->right);
}

int nextWord(char *word, FILE *fp) {
  int c;
  c = fscanf(fp, "%s", word);

  char *str1 = word;
  while (*str1!='\0') {
    if (*str1== ',') {
      *str1 = '\0';
    }
    str1++;
  }
  return c;
}

int main(int argc, char *argv[]) {
  Word *root = NULL;
  char str[CAPACITY];
  FILE *fp;
  fp = fopen(argv[1], "r");
  while (nextWord(str, fp) != EOF) {
    if (str[0] != '\0') addWord(&root, str);
  }
  printResult(root);
  return 0;
}