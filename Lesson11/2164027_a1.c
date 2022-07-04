#include <stdio.h>


/*
 * このプログラムではそれぞれの演算子に対し以下のようにあらわして考えた。
 * 0  '+'
 * 1  ' '
 * 2  '-'
 */
int exec(int in[]) {
    int r = 0;
    //最初だけ個別に処理。
    int operator = in[0];
    int tmp = 1;
    for (int i = 1; i < 9; ++i) {
        switch (in[i]) {
            //もし' 'ならば...
            case 1:
                //現在の一時値を10倍、次の桁を足してtmpを更新する。
                tmp *= 10;
                tmp += i + 1;
                break;
            default:
                //演算子がある場合
                switch (operator) {
                    case 0:
                    case 1:
                        //tmpの値を修飾している演算子が+の場合(最初が何もない場合も含む)
                        r += tmp;
                        break;
                    case 2:
                        //tmpの値を修飾している演算子が-の場合
                        r -= tmp;
                        break;
                }
                //次の桁をセット。
                tmp = i + 1;
                operator = in[i];
        }
    }
    //最後は個別に処理。
    switch (operator) {
        case 0:
        case 1:
            r += tmp;
            break;
        case 2:
            r -= tmp;
            break;
    }
    return r;
}

//個別の結果を出力する用の関数
int print(int operator[], int result) {
    for (int i = 0; i < 9; ++i) {
        switch (operator[i]) {
            case 0:
                printf("+");
                break;
            case 2:
                printf("-");
                break;
        }
        printf("%d", i + 1);
    }
    printf("=%d\n", result);
}

//全てのパターンについて検証するための関数。(3^8)*2通りについて検証する。指定された深さ(9)だけ再帰的に実行する。
int run(int level, int stack[]) {
    if (level == 9) {
        int r = exec(stack);
        if (r == 100) print(stack, 100);
        return 0;
    }
    //最初のみ、+はこないので、' 'or'-',つまり1or2で試す。
    for (int i = (level > 0 ? 0 : 1); i < 3; ++i) {
        stack[level] = i;
        run(level + 1, stack);
    }
}

int main() {
    int operator[9];
    //run関数で実行する。
    run(0, operator);
}