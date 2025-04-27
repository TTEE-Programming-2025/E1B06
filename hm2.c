#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <conio.h> // 使用 getch() 不需按 Enter

// 函式宣告
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

    // 登入系統，三次機會
    success = loginSystem();
    if (!success) {
        printf("\n密碼錯誤超過三次，程式結束！\n");
        exit(1);
    }

    while (1) {
        clearScreen();
        printf("\n=================\n");
        printf("a. 查詢直角三角形\n");
        printf("b. 顯示乘法表\n");
        printf("c. 計算平方和\n");
        printf("x. 結束\n");
        printf("=================\n");
        printf("請選擇功能 (直接按鍵): ");

        choice = getch(); // 即時按鍵
        printf("%c\n", choice);

        clearScreen();

        switch (tolower(choice)) {
            case 'a':
                printf("\n輸入直角三角形的邊長 (1-50): ");
                if (scanf("%d", &n) != 1) {
                    printf("輸入錯誤！請輸入數字。\n");
                    while (getchar() != '\n');
                } else if (n < 1 || n > 50) {
                    printf("範圍錯誤！請輸入1到50之間的數字。\n");
                } else {
                    printRightTriangle(n);
                }
                break;

            case 'b':
                displayMultiplicationTable();
                break;

            case 'c':
                printf("\n輸入一個整數 n (1-20): ");
                if (scanf("%d", &n) != 1) {
                    printf("輸入錯誤！請輸入數字。\n");
                    while (getchar() != '\n');
                } else if (n < 1 || n > 20) {
                    printf("範圍錯誤！請輸入1到20之間的數字。\n");
                } else {
                    calculateSumOfSquares(n);
                }
                break;

            case 'x':
                printf("\n程式結束，謝謝使用！\n");
                exit(0);

            default:
                printf("\n無效的選項，請重新輸入！\n");
                break;
        }

        pauseAndContinue();
    }

    return 0;
}

// 登入系統
int loginSystem(void) {
    int password;
    int attempt = 0;
    const int correctPassword = 2025;

    printf("歡迎使用本系統，請先登入。\n");

    while (attempt < 3) {
        printf("請輸入四位數密碼：");
        if (scanf("%d", &password) != 1) {
            printf("輸入錯誤！請輸入數字。\n");
            while (getchar() != '\n');
            continue;
        }

        if (password == correctPassword) {
            printf("\n登入成功！\n");
            return 1;
        } else {
            printf("密碼錯誤！剩下 %d 次機會。\n", 2 - attempt);
            attempt++;
        }
    }
    return 0;
}

// 印出直角三角形
void printRightTriangle(int n) {
    int i, j;
    printf("\n直角三角形：\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// 顯示九九乘法表
void displayMultiplicationTable(void) {
    int i, j;
    printf("\n九九乘法表：\n");
    for (i = 1; i <= 9; i++) {
        for (j = 1; j <= 9; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }
}

// 計算平方和
void calculateSumOfSquares(int n) {
    long long sum = 0;
    int i;
    for (i = 1; i <= n * n; i++) {
        sum += (long long)i * i;
    }
    printf("\n從 1 到 %d^2 的平方和是: %lld\n", n, sum);
}

// 暫停詢問是否繼續
void pauseAndContinue(void) {
    char response;
    printf("\n是否繼續？(y/n): ");
    response = getch();
    printf("%c\n", response);

    if (tolower(response) == 'n') {
        printf("\n程式結束，謝謝使用！\n");
        exit(0);
    }
}

// 清除畫面
void clearScreen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
//這次的程式設計作業，讓我深刻體會到「規劃流程」以及「細心」在撰寫程式中扮演的重要角色。
//在一開始設計選單系統時，我花了不少時間思考使用者操作的順暢度，例如每個選項之間的跳轉、輸入錯誤的處理，以及是否要提供退出確認，這些都是以前寫簡單小程式時比較少注意到的細節。
