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
        //0~size-1�̊ԂłŌJ��Ԃ�����
        if (++position == size)position = 0;

        //��������؂��Ȃ�...
        //check++�ŃJ�E���g�A���̐���������؂�邩�m�F����
        if (input[position] % temp == 0) {
            check++;
            continue;
        }
        //����؂�Ȃ��Ȃ�..
        //check�����Z�b�g
        check = 0;
        //input[position]��temp���傫���Ȃ�A
        if (input[position] > temp) {
            input[position] %= temp;
        }
        //input[position]��temp����������
        int i = temp;
        temp = input[position];
        input[position] = i;
    } while (check < size);
    printf("�ő���񐔂�%6d �ł��B", temp);
}

int ask_for_input() {
    int v;
    printf("TYPE VALUE: ");
    scanf("%d", &v);
    return v;
}