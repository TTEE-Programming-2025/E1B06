#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <conio.h> // 使用 getch()

// Function prototypes
void printRightTriangle(int n);
void displayMultiplicationTable();
void calculateSumOfSquares(int n);
void pauseAndContinue();
void clearScreen();
int loginSystem(); // 新增：登入系統

int main() {
    char choice;
    int n;

    clearScreen();

    // 登入系統，失敗三次則結束
    if (!loginSystem()) {
        printf("\n密碼錯誤超過三次，程式結束！\n");
        exit(1);
    }

    while (1) {
        clearScreen();
        // 顯示選單
        printf("\n=================\n");
        printf("a. 查詢直角三角形\n");
        printf("b. 顯示乘法表\n");
        printf("c. 計算平方和\n");
        printf("x. 結束\n");
        printf("=================\n");
        printf("請選擇功能 (直接按鍵): ");
        
        choice = getch(); // 不需要按 Enter
        printf("%c\n", choice); // 顯示按下的按鍵

        clearScreen();

        switch (tolower(choice)) { // 處理大小寫
            case 'a':
                printf("\n輸入直角三角形的邊長 (1-50): ");
                if (scanf("%d", &n) != 1 || getchar() != '\n') {
                    printf("輸入錯誤！請輸入正確的數字。\n");
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
                if (scanf("%d", &n) != 1 || getchar() != '\n') {
                    printf("輸入錯誤！請輸入正確的數字。\n");
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
                printf("\n無效的選項，請重新選擇。\n");
                break;
        }

        // 每次操作結束後詢問是否繼續
        pauseAndContinue();
    }
    return 0;
}

// 登入系統：最多允許三次機會
int loginSystem() {
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
            printf("\n登入成功！歡迎使用。\n");
            return 1;
        } else {
            printf("密碼錯誤！還有 %d 次機會。\n", 2 - attempt);
            attempt++;
        }
    }
    return 0; // 登入失敗
}

// 印出直角三角形
void printRightTriangle(int n) {
    printf("\n直角三角形：\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// 顯示九九乘法表
void displayMultiplicationTable() {
    printf("\n九九乘法表：\n");
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }
}

// 計算1到n*n的平方和
void calculateSumOfSquares(int n) {
    long long sum = 0;
    for (int i = 1; i <= n * n; i++) {
        sum += (long long)i * i;
    }
    printf("\n從1到%d^2的平方和是: %lld\n", n, sum);
}

// 暫停並詢問是否繼續
void pauseAndContinue() {
    char response;
    printf("\n是否繼續？ (y/n): ");
    response = getch();
    printf("%c\n", response);

    if (tolower(response) == 'n') {
        printf("\n程式結束，謝謝使用！\n");
        exit(0);
    } else if (tolower(response) != 'y') {
        printf("\n輸入錯誤，自動回到主選單。\n");
    }
}

// 清除畫面
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
