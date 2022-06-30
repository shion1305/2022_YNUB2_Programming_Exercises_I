#include <stdio.h>
#include <stdlib.h>

void print(int *prefix, int prefix_size, int recursive, int m, FILE *out);

void exportStack(int n, FILE *out);

void printStack(int result[], int n, FILE *out);

void print(int *prefix, int prefix_size, int recursive, int m, FILE *out);

int outStack[10][100];
int size = 0;

int main(int argc, char *argv[]) {
//    コマンド引数に関する例外処理を実施する
    if (argc < 1) {
        printf("コマンド引数が指定されていません\n");
        exit(1);
    }
    //ファイルの出力先を用意する。
    FILE *out = fopen(argv[1], "w");
    if (out == NULL) {
        printf("コマンド引数によるファイルの指定が不正です。\n");
        exit(1);
    }
    //mとnの入力を受け付ける
    int m, n;
    while (1) {
        printf("1桁の正数Mを入力してください\nM:");
        scanf("%d", &m);
        if (m > 0 && m < 10) break;
        printf("Mが間違っています\n");
    }
    while (1) {
        printf("1桁の正数Nを入力してください\nN:");
        scanf("%d", &n);
        if (n > 0 && n < 10) break;
        printf("Nが間違っています\n");
    }
    int prefix[10] = {0,};
    print(prefix, 0, n, m, out);
    //outStackに最後に残っているものを出力する必要がある。
    exportStack(n, out);
    printf("1 から %d までの数字を %d 個並べた処理結果をファイル %s に出力します", m, n, argv[1]);
}

/**
 * この関数では再帰的に出力を行っている。
 * @param prefix 先頭から再帰的に繰り返させることで処理を行っているが、親の再帰処置に当たる部分
 * @param prefix_size 親で再帰処理されて生成されたprefix部の長さ
 * @param recursive 再帰処理を行う残りの深さ
 * @param m 与えられたM
 * @param out ファイルの出力場所
 */
void print(int *prefix, int prefix_size, int recursive, int m, FILE *out) {
    if (recursive == 0) {
        printStack(prefix, prefix_size, out);
    } else if (recursive-- > 0) {
        for (int i = 1; i <= m; ++i) {
            prefix[prefix_size] = i;
            //再帰的に出力。
            print(prefix, prefix_size + 1, recursive, m, out);
        }
    }
}

/**直接出力することではなく、結果を格納してまとめて出力することで
 * フォーマットし、加点項目を実現している。
 *
 * @param result 結果を格納した配列の位置
 * @param n 結果の長さ(与えられたn)
 * @param out 出力する場所
 */
void printStack(int *result, int n, FILE *out) {
    for (int i = 0; i < n; ++i) {
        outStack[i][size] = result[i];
    }
    //スタックした結果が最大に達したら出力を実行する
    if (++size == 100) {
        exportStack(n, out);
    }
}

/**
 * printStack関数によってoutStackにスタックされた結果を
 * フォーマットされた形で出力するもの
 * @param n 与えられたn
 * @param out ファイルの出力場所
 */
void exportStack(int n, FILE *out) {
    //20行5列で出力する
    for (int j = 0; j < 20; ++j) {
        fprintf(out, "\n");
        for (int k = 0; k < 5; ++k) {
            //5列それぞれを出力する。
            for (int l = 0; l < n; ++l) {
                /**
                 * 例えばsizeが25であった場合、
                 * 1~20
                 * 21~25
                 * だけである。
                 * 5列に分けて考える場合、
                 * 1,21,41,61,81
                 * 2,21,42,62,82
                 * と出力するが、
                 * 61,81,62,82は41,42が存在しないことを
                 * 確認しているため確認不要である。
                 * よって存在しない場合はbreakで飛ばす。
                 */
                if (j + k * 20 >= size)break;
                fprintf(out, "%2d", outStack[l][j + k * 20]);
            }
            fprintf(out, " ");
            //列の区切りの為の空白
        }
    }
    fprintf(out, "\n");
    size = 0;
    //全て出力したのでsize=0とすることでスタックを
    //空の状態にしたものとさせる。
}
