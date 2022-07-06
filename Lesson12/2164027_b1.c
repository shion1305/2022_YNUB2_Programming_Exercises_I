#include <stdio.h>


int main() {
    //a,b,c,dをそれぞれ1~9までの範囲の中で動かす。
    //但し、a,b,c,dのいずれかが被った場合はスキップ。
    for (int a = 1; a < 10; ++a) {
        for (int b = 1; b < 10; ++b) {
            if (b == a)continue;
            for (int c = 1; c < 10; ++c) {
                if (c == b || c == a)continue;
                for (int d = 1; d < 10; ++d) {
                    if (d == c || d == b || d == a)continue;
                    int x = a * 10 + b;
                    int y = c * 10 + d;
                    //条件式をクリアしたら出力する。
                    if (x % y == 0 && x / y == 3) printf("%d, %d\n", x, y);
                }
            }
        }
    }
}