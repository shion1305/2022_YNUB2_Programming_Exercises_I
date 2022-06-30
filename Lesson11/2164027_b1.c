#include <stdio.h>
#include <stdlib.h>

void printAsN(int target, int n);


int main() {
    //処理はずっと繰り返すのでwhile(1)ループで処理を継続
    while (1) {
        //変換する値targetとn進数の値の入力を受け付ける。
        int target, n;
        printf("10進数の正数を入力してください( 0 以下で終了 ) :");
        scanf("%d", &target);
        if (target < 1) {
            printf("0以下が入力されました。終了します。\n");
            exit(0);
        }
        while (1) {
            printf("n 進数に変換しますか? ( 2 ≦ n ≦ 16 ):");
            scanf("%d", &n);
            if (n < 2 || n > 16) {
                printf("2 ≦ n ≦ 16 ではありません\n");
                continue;
            }
            break;
        }
        //受け付けた入力をもとに出力を行わせる。
        printAsN(target, n);
    }
}


//プリントする関数。
void printAsN(int target, int n) {
    int size = 0;
    char holder[30] = {0,};
    int div;
    //targetを割ったものが1以上(nより大きいならば...)
    while ((div = target / n) > 0) {
        //そのあまりを記録し、
        holder[size++] = target % n;
        //その商をtargetに上書きする
        target = div;
    }
    //whileループを抜けるのはtargetが最上桁になった時。
    //一番大きい桁を出力(この場合targetに格納されている)
    printf("%x", target);
    while (size-- > 0) {
        //最上位以外の桁をそれぞれ出力する。
        printf("%x", holder[size]);
    }
    printf("\n\n");
}
