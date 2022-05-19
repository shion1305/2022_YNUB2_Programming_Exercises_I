#include <stdio.h>

//入力用
void input_mat(double target[2][2]);

//出力用
void print_mat(double target[2][2], double inverse);

//逆行列を求める用の、行列式の値を計算する関数
double inverse(double target[2][2]);

int main() {
    double mat[2][2];
    //入力を求める
    input_mat(mat);
    //inverseで計算した結果を出力用の関数に渡す
    print_mat(mat, inverse(mat));
}


void input_mat(double target[2][2]) {
    printf("2 x 2 の行列の要素の値を入力してください\n");
    //それぞれの要素に対して値を挿入していく。
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("a[%d][%d] =", i, j);
            scanf("%lf", &target[i][j]);
        }
    }
}

void print_mat(double target[2][2], double inverse) {
    printf("行列\n");
    for (int i = 0; i < 2; ++i) {
        //指定したフォーマットでの出力。
        printf("%2.5lf  %2.5lf\n", target[i][0], target[i][1]);
    }
    //逆行列が存在しない時(つまり inverse==0)
    if (inverse == 0.0) {
        printf("の逆行列は存在しない");
        return;
    }
    //この後は逆行列が存在する場合にのみ実行される。
    //逆行列の定義に従ってそれぞれ計算。
    printf("の逆行列は\n");
    printf("%2.5lf  %2.5lf\n", *(target[1] + 1) / inverse, -1 * *(target[0] + 1) / inverse);
    printf("%2.5lf  %2.5lf\n", -1 * *target[1] / inverse, *target[0] / inverse);
}

double inverse(double target[2][2]) {
    //ポインタの性質を用いて計算(この問題では使っても大丈夫でしたよね..?)
    return *target[0] * *(target[1] + 1) - *(target[0] + 1) * *target[1];
}
