#include <stdio.h>

//入力用引数に与えられた参照型配列に代入操作をする。
void input_mat(double target[2][2]);

//出力用。引数に与えられた変数をプリントする。
void print_mat(double target[2][2]);

//逆行列を求める関数
double inverse(double input[2][2], double output[2][2]);

int main() {
    double mat[2][2];
    //input_matで入力を求める
    input_mat(mat);
    //inverseで逆行列を求め、inversedに格納する。
    //また、行列式の値をdに格納し、d==0で逆行列は存在しないので、
    //存在しない旨の表示を出す。
    double inversed[2][2];
    double d = inverse(mat, inversed);
    printf("行列\n");
    print_mat(mat);
    if (d == 0.0) {
        printf("の逆行列は存在しない。");
        return 0;
    }
    printf("の逆行列は\n");
    print_mat(inversed);
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

void print_mat(double target[2][2]) {
    printf("%2.5lf  %2.5lf\n", target[0][0], target[0][1]);
    printf("%2.5lf  %2.5lf\n", target[1][0], target[1][1]);
}

double determinant(double target[2][2]) {
    //ポインタの性質を用いて計算(この問題では使っても大丈夫でしたよね..?)
    return *target[0] * *(target[1] + 1) - *(target[0] + 1) * *target[1];
}

double inverse(double input[2][2], double output[2][2]) {
    //2次正方行列の逆行列の式
    double d = determinant(input);
    //行列式が0ならばもちろん逆行列は存在しないので、要件に従って0を返す。
    if (d == 0) return 0;
    //行列式が存在するとき、2次正方行列の定義に従ってそれぞれの要素を計算する
    output[0][0] = *(input[1] + 1) / d;
    output[0][1] = -1 * *(input[0] + 1) / d;
    output[1][0] = -1 * *input[1] / d;
    output[1][1] = *input[0] / d;
    return d;
}
