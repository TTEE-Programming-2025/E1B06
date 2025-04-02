#include <stdio.h>
#include <stdlib.h>
#define PASSWORD 2024

// ��ƫŧi
void showWelcomeScreen();
void clearScreen();
int checkPassword();
void showMenu();
void processInput();

int main() {
    showWelcomeScreen();
    clearScreen();
    
    if (!checkPassword()) {
        printf("\n�K�X���~�A�{�������C\n");
        return 0;
    }
    
    clearScreen();
    showMenu();
    processInput();
    
    printf("\n�����N�䵲���{��...\n");
    getch();
    return 0;
}

// ��ܭӤH����e��
void showWelcomeScreen() {
    printf("****************************************\n");
    printf("*                                      *\n");
    printf("*       �w��ϥΥ��{�� (C �y���m��)       *\n");
    printf("*                                      *\n");
    for (int i = 0; i < 16; i++) {
        printf("*       �o�O�A���ӤH����e�� %2d       *\n", i + 1);
    }
    printf("*                                      *\n");
    printf("****************************************\n");
    printf("\n�Ы����N���~��...\n");
    getch();
}

// �M���ù�
void clearScreen() {
    system("cls"); // �Y�b Linux �W����A�Чאּ system("clear");
}

// �K�X����
int checkPassword() {
    int inputPassword;
    printf("�п�J 4 ��Ʀr�K�X: ");
    scanf("%d", &inputPassword);
    return (inputPassword == PASSWORD);
}

// ��ܥD���
void showMenu() {
    printf("-------------------------------\n");
    printf("|  ��A��...��Z�� : Uppercase       |\n");
    printf("|  ��a��...��z�� : Lowercase       |\n");
    printf("|  ��0��...��9�� : Digit           |\n");
    printf("|  Otherwise : �A���m�W        |\n");
    printf("-------------------------------\n");
}

// �B�z�ϥΪ̿�J
void processInput() {
    char ch;
    printf("�п�J�@�Ӧr��: ");
    ch = getch(); // Ū����@�r��
    printf("%c\n", ch);
    
    if (ch >= 'A' && ch <= 'Z') {
        printf("Uppercase\n");
    } else if (ch >= 'a' && ch <= 'z') {
        printf("Lowercase\n");
    } else if (ch >= '0' && ch <= '9') {
        printf("Digit\n");
    } else {
        printf("�A���Z�Ůy���Ωm�W\n");
    }
}

/*
===========================================
�i�{�������j
���{���� C �y���m�ߡA�]�t�H�U�\��G
1. ��ܭӤH����e���C
2. �n�D�ϥΪ̿�J�K�X�i�����ҡC
3. ��ܿ��A�îھڨϥΪ̿�J���r�����O�i�������ܡC

�i�Q�סj
���{���i�ܤF�򥻪� C �y����J�P��X�B�z�A�óz�L����P�_�M�w��J�����O�C
���]�t getch() ��Ū����@�r���A�èϥ� system("cls") �ӲM���e���C
�o����Ǫ̦Ө��A�O�ӫܦn���m�߮רҡA���U�z�Ѱ򥻨禡�P����y�{�C

�i�߱o�j
���{�����c�M���A�A�X�@���ǲ� C �y�����J���d�ҡC
�z�L�K�X���Ҿ���A���{����㤬�ʩʡA�B�Q�α���P�_���ɤF�޿�B�z��O�C
���ӥi�H�i�@�B��i�A�p�W�[���~��J���B�z���X�R��h�\��C
===========================================
*/
