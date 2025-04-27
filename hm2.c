#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <conio.h> // �ϥ� getch()

// Function prototypes
void printRightTriangle(int n);
void displayMultiplicationTable();
void calculateSumOfSquares(int n);
void pauseAndContinue();
void clearScreen();
int loginSystem(); // �s�W�G�n�J�t��

int main() {
    char choice;
    int n;

    clearScreen();

    // �n�J�t�ΡA���ѤT���h����
    if (!loginSystem()) {
        printf("\n�K�X���~�W�L�T���A�{�������I\n");
        exit(1);
    }

    while (1) {
        clearScreen();
        // ��ܿ��
        printf("\n=================\n");
        printf("a. �d�ߪ����T����\n");
        printf("b. ��ܭ��k��\n");
        printf("c. �p�⥭��M\n");
        printf("x. ����\n");
        printf("=================\n");
        printf("�п�ܥ\�� (��������): ");
        
        choice = getch(); // ���ݭn�� Enter
        printf("%c\n", choice); // ��ܫ��U������

        clearScreen();

        switch (tolower(choice)) { // �B�z�j�p�g
            case 'a':
                printf("\n��J�����T���Ϊ���� (1-50): ");
                if (scanf("%d", &n) != 1 || getchar() != '\n') {
                    printf("��J���~�I�п�J���T���Ʀr�C\n");
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
                if (scanf("%d", &n) != 1 || getchar() != '\n') {
                    printf("��J���~�I�п�J���T���Ʀr�C\n");
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
                printf("\n�L�Ī��ﶵ�A�Э��s��ܡC\n");
                break;
        }

        // �C���ާ@������߰ݬO�_�~��
        pauseAndContinue();
    }
    return 0;
}

// �n�J�t�ΡG�̦h���\�T�����|
int loginSystem() {
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
            printf("\n�n�J���\�I�w��ϥΡC\n");
            return 1;
        } else {
            printf("�K�X���~�I�٦� %d �����|�C\n", 2 - attempt);
            attempt++;
        }
    }
    return 0; // �n�J����
}

// �L�X�����T����
void printRightTriangle(int n) {
    printf("\n�����T���ΡG\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// ��ܤE�E���k��
void displayMultiplicationTable() {
    printf("\n�E�E���k��G\n");
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }
}

// �p��1��n*n������M
void calculateSumOfSquares(int n) {
    long long sum = 0;
    for (int i = 1; i <= n * n; i++) {
        sum += (long long)i * i;
    }
    printf("\n�q1��%d^2������M�O: %lld\n", n, sum);
}

// �Ȱ��ø߰ݬO�_�~��
void pauseAndContinue() {
    char response;
    printf("\n�O�_�~��H (y/n): ");
    response = getch();
    printf("%c\n", response);

    if (tolower(response) == 'n') {
        printf("\n�{�������A���¨ϥΡI\n");
        exit(0);
    } else if (tolower(response) != 'y') {
        printf("\n��J���~�A�۰ʦ^��D���C\n");
    }
}

// �M���e��
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
