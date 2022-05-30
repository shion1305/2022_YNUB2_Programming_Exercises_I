#include <stdio.h>

/* この最長共通部分列問題は動的計画法を用いた。
 * 2次元配列にそれぞれの区間ごとの情報を集約することで
 * この問題を解くことができる
 */
void ask_for_input(char *target);

int process(char text1[], char text2[], int enableLog);

//マイルストーン保存用の構造体coord
typedef struct {
    int x;
    int y;
} coord;

//再帰処理を行う関数、詳細は後述参照。
void
go(char text1[], char text2[], coord milestones[100][100], int stage, int index, int milestoneSizes[], char text[]);

int main() {
    char text1[100];
    char text2[100];
    char log;
    printf("1つ目の文字列を入力してください。\n");
    ask_for_input(text1);
    printf("2つ目の文字列を入力してください。\n");
    ask_for_input(text2);
    do {
        printf("検証用の2次元配列を表示できます。表示しますか?(Y/n)");
        log = getchar();
    } while (log != 'Y' && log != 'n');
    int result = process(text1, text2, log == 'Y');
    printf("共通部分列の長さの最大値は %d です。", result);
}

//入力を受け付ける関数を分離することでDRYにしている。
void ask_for_input(char *target) {
    gets(target);
}

//階層的に最長共通部分を再帰処理によって探索する。
void
go(char text1[], char text2[], coord milestones[100][100], int stage, int index, int milestoneSizes[], char text[]) {
    coord target = milestones[stage][index];
    text[stage] = text1[milestones[stage][index].x];
    for (int i = 0; i < milestoneSizes[stage - 1]; ++i) {
        coord candidate = milestones[stage - 1][i];
        //組み合わせ対象のマイルストーンを限定する。
        if (candidate.x >= target.x || candidate.y >= target.y) continue;
        if (stage == 1) {
            text[0] = text1[candidate.x];
            printf("%s\n", text);
        } else {
            go(text1, text2, milestones, stage - 1, i, milestoneSizes, text);
        }
    }
}


int process(char text1[], char text2[], int enableLog) {
    //長さをそれぞれ測定する。
    int length1 = 0, length2 = 0;
    while (text1[length1] != '\0')length1++;
    while (text1[length2] != '\0')length2++;
    //それぞれの共通部分を採用した際にどれだけ部分列候補がヒットするかをまとめる2次元配列を用意する。
    //まずは初期化。
    int data[length1 + 1][length2 + 1];
    for (int i = 0; i <= length1; ++i) {
        for (int j = 0; j <= length2; ++j) {
            data[i][j] = 0;
        }
    }
    /*
     * 例えば、`ababca`と`babacc`が入力として与えられたことを仮定する。
     * 動的計画法を用いて2次元配列を生成すると以下のようになる。
     *     a  b  a  b  c  a
     *  b  0  0  0  0  0  0  0
     *  a  0  0  1  1  1  1  1
     *  b  0  1  1  2  2  2  2
     *  a  0  1  2  2  3  3  3
     *  c  0  1  2  3  3  3  4
     *  c  0  1  2  3  3  4  4
     *     0  1  2  3  3  4  4
     *  この表を生成したことにより、最大共通文字列部分の長さが4であることがわかった。
     *  ここから共通文字列部分の文字列本体を出力しなければならない。
     *  共通文字列部分を求めるには、上記の表で数字間に変化が生じている部分(以下、マイルストーンと呼称する)
     *  (下記のコードの(*)が実行されている部分)
     *  に注目して、異なる数字のマイルストーン同士の組み合わせを考えればよい。
     *  上記の例では(可読性の都合上、上記から文字列の対応を一つずらしている。)
     *  以下の| |で囲まれているもの同士を
     *  4→3→2→1の順で、かつ経路が常に右下から左上となるように
     *  結び付ければよい。
     *        a  b  a  b  c  a
     *     0  0  0  0  0  0  0
     *  b  0  0 |1| 1  1  1  1
     *  a  0 |1| 1 |2| 2  2  2
     *  b  0  1 |2| 2 |3| 3  3
     *  a  0  1  2 |3| 3  3 |4|
     *  c  0  1  2  3  3 |4| 4
     *  c  0  1  2  3  3  4  4
     *  最大共通文字列部分の長さを求めた後に一からまた「マイルストーン」を求めることは重複した操作となる。
     *  よって再度マイルストーンを探索するのではなく、マイルストーンを保存しておくことが望ましいと言えるだろう。
     *  本ソースコード中では、構造体coordを定義し、その2次元配列milestonesに保存することで実現している。
     *  milestonesが二次元配列となっているのは
     *  1番目のindexは上記のマイルストーンの数字(stage)を管理するため
     *  2番目のindexはマイルストーンを複数保存できるようにするため
     *  である。
    */
    coord milestones[100][100];
    int milestone_size[100] = {0};
    for (int i = 0; i < length1; ++i) {
        for (int j = 0; j < length2; ++j) {
            if (text1[i] == text2[j]) {
                //上記説明の(*)
                //最大共通文字列部分を求めるために再びこの座標が必要であるため、
                //milestoneとしてcoord配列milestonesに保存する。
                data[i + 1][j + 1] = data[i][j] + 1;
                coord s = {i, j};
                milestones[data[i][j]][milestone_size[data[i][j]]++] = s;
            } else {
                //動的計画法の処理。
                if (data[i][j + 1] > data[i + 1][j]) {
                    data[i + 1][j + 1] = data[i][j + 1];
                } else {
                    data[i + 1][j + 1] = data[i + 1][j];
                }
            }
        }
    }

    //動的計画法によって生成した2次元配列のビジュアライズ化
    if (enableLog) {
        for (int i = 0; i <= length2; ++i) {
            for (int j = 0; j <= length1; ++j) {
                printf("%2d ", data[j][i]);
            }
            printf("\n");
        }
    }
    //milestonesに保存したマイルストーンの情報を用いて再探索せず処理を行っていく。
    //階層的かつ再帰的な処理でそれぞれの組み合わせを探し出す処理はgo関数にて実装している。
    printf("最大共通部分列の候補は以下の通りです。(異なる組み合わせによる重複を含む。)\n");
    for (int i = 0; i < milestone_size[data[length1][length2] - 1]; ++i) {
        char text[data[length1][length2] + 1];
        text[data[length1][length2]] = '\0';
        go(text1, text2, milestones, data[length1][length2] - 1, i, milestone_size, text);
    }
    return data[length1][length2];
}
