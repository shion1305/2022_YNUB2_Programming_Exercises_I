#include <stdio.h>
#include <stdlib.h>

#define EOD -1

int getMax(int array[]);

int main() {
    /*
     * 10�̃e�X�g�P�[�X�Ŋm���߂悤�B
     */
    for (int i = 0; i < 10; ++i) {
        //������������
        srand(i);
        /*
         * �傫����100~109�̃e�X�g�P�[�X�𗐐��ɂ���Đ�������B
         */
        int size = 100 + rand() % 10;
        //�e�X�g�P�[�X�p�̔z���p�ӂ���B
        int test[size];
        printf("=================TEST CASE=================\n");
        for (int i = 0; i < size - 1; ++i) {
            //������������B
            test[i] = rand();
            //�o�͂���B
            printf("%d, ", test[i]);
        }
        test[size - 1] = -1;
        printf("\n");
        printf("===========================================\n");
        //�e�X�g�P�[�X�ɑ΂���getMax�֐������s����
        printf("MAX VALUE IS %d\n", getMax(test));
    }
}

int getMax(int array[]) {
    int max = array[0];
    //EOD���ŏ��ɗ���̂͂��蓾�Ȃ����ꉞ��O�����B
    if (max == EOD) {
        printf("ILLEGAL INPUT\n");
        return EOD;
    }
    int position = 0;
    //�I���܂ŌJ��ւ����B
    while (array[++position] != EOD) {
        //���̍ő�l���Ώۂ��傫����΁A���̍ő�l���X�V����
        if (array[position] > max) {
            max = array[position];
        }
    }
    return max;
}