#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <conio.h> // �ϥ� getch() ���ݫ� Enter

// �禡�ŧi
void printRightTriangle(int n);
void displayMultiplicationTable(void);
void calculateSumOfSquares(int n);
void pauseAndContinue(void);
void clearScreen(void);
int loginSystem(void);

int main() {
    char choice;
    int n;
    int success;

    clearScreen();

    // �n�J�t�ΡA�T�����|
    success = loginSystem();
    if (!success) {
        printf("\n�K�X���~�W�L�T���A�{�������I\n");
        exit(1);
    }

    while (1) {
        clearScreen();
        printf("\n=================\n");
        printf("a. �d�ߪ����T����\n");
        printf("b. ��ܭ��k��\n");
        printf("c. �p�⥭��M\n");
        printf("x. ����\n");
        printf("=================\n");
        printf("�п�ܥ\�� (��������): ");

        choice = getch(); // �Y�ɫ���
        printf("%c\n", choice);

        clearScreen();

        switch (tolower(choice)) {
            case 'a':
                printf("\n��J�����T���Ϊ���� (1-50): ");
                if (scanf("%d", &n) != 1) {
                    printf("��J���~�I�п�J�Ʀr�C\n");
                    while (getchar() != '\n');
                } else if (n < 1 || n > 50) {
                    printf("�d����~�I�п�J1��50�������Ʀr�C\n");
                } else {
                    printRightTriangle(n);
                }
                break;

            case 'b':
                displayMultiplicationTable();
                break;

            case 'c':
                printf("\n��J�@�Ӿ�� n (1-20): ");
                if (scanf("%d", &n) != 1) {
                    printf("��J���~�I�п�J�Ʀr�C\n");
                    while (getchar() != '\n');
                } else if (n < 1 || n > 20) {
                    printf("�d����~�I�п�J1��20�������Ʀr�C\n");
                } else {
                    calculateSumOfSquares(n);
                }
                break;

            case 'x':
                printf("\n�{�������A���¨ϥΡI\n");
                exit(0);

            default:
                printf("\n�L�Ī��ﶵ�A�Э��s��J�I\n");
                break;
        }

        pauseAndContinue();
    }

    return 0;
}

// �n�J�t��
int loginSystem(void) {
    int password;
    int attempt = 0;
    const int correctPassword = 2025;

    printf("�w��ϥΥ��t�ΡA�Х��n�J�C\n");

    while (attempt < 3) {
        printf("�п�J�|��ƱK�X�G");
        if (scanf("%d", &password) != 1) {
            printf("��J���~�I�п�J�Ʀr�C\n");
            while (getchar() != '\n');
            continue;
        }

        if (password == correctPassword) {
            printf("\n�n�J���\�I\n");
            return 1;
        } else {
            printf("�K�X���~�I�ѤU %d �����|�C\n", 2 - attempt);
            attempt++;
        }
    }
    return 0;
}

// �L�X�����T����
void printRightTriangle(int n) {
    int i, j;
    printf("\n�����T���ΡG\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// ��ܤE�E���k��
void displayMultiplicationTable(void) {
    int i, j;
    printf("\n�E�E���k��G\n");
    for (i = 1; i <= 9; i++) {
        for (j = 1; j <= 9; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }
}

// �p�⥭��M
void calculateSumOfSquares(int n) {
    long long sum = 0;
    int i;
    for (i = 1; i <= n * n; i++) {
        sum += (long long)i * i;
    }
    printf("\n�q 1 �� %d^2 ������M�O: %lld\n", n, sum);
}

// �Ȱ��߰ݬO�_�~��
void pauseAndContinue(void) {
    char response;
    printf("\n�O�_�~��H(y/n): ");
    response = getch();
    printf("%c\n", response);

    if (tolower(response) == 'n') {
        printf("\n�{�������A���¨ϥΡI\n");
        exit(0);
    }
}

// �M���e��
void clearScreen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
//�o�����{���]�p�@�~�A���ڲ`����|��u�W���y�{�v�H�Ρu�Ӥߡv�b���g�{������t�����n����C
//�b�@�}�l�]�p���t�ήɡA�ڪ�F���֮ɶ���ҨϥΪ̾ާ@�����Z�סA�Ҧp�C�ӿﶵ����������B��J���~���B�z�A�H�άO�_�n���Ѱh�X�T�{�A�o�ǳ��O�H�e�g²��p�{���ɤ���֪`�N�쪺�Ӹ`�C
