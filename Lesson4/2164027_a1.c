#include <stdio.h>

int ask_for_input();


int main() {
    int input[200];
    int in;
    int size = 0;
    printf("INPUT Number... Type 0 to End\n");
    while ((in = ask_for_input()) != 0) {
        input[size] = in;
        size++;
    }

    int temp = input[0];
    int check = 0;
    int position = 0;
    do {
        //0~size-1の間でで繰り返させる
        if (++position == size)position = 0;

        //もし割り切れるなら...
        //check++でカウント、次の数字が割り切れるか確認する
        if (input[position] % temp == 0) {
            check++;
            continue;
        }
        //割り切れないなら..
        //checkをリセット
        check = 0;
        //input[position]がtempより大きいなら、
        if (input[position] > temp) {
            input[position] %= temp;
        }
        //input[position]とtempを交換する
        int i = temp;
        temp = input[position];
        input[position] = i;
    } while (check < size);
    printf("最大公約数は%6d です。", temp);
}

int ask_for_input() {
    int v;
    printf("TYPE VALUE: ");
    scanf("%d", &v);
    return v;
}