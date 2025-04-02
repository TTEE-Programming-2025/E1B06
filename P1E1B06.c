#include <stdio.h>
#include <stdlib.h>
#define PASSWORD 2024

// 函數宣告
void showWelcomeScreen();
void clearScreen();
int checkPassword();
void showMenu();
void processInput();

int main() {
    showWelcomeScreen();
    clearScreen();
    
    if (!checkPassword()) {
        printf("\n密碼錯誤，程式結束。\n");
        return 0;
    }
    
    clearScreen();
    showMenu();
    processInput();
    
    printf("\n按任意鍵結束程式...\n");
    getch();
    return 0;
}

// 顯示個人風格畫面
void showWelcomeScreen() {
    printf("****************************************\n");
    printf("*                                      *\n");
    printf("*       歡迎使用本程式 (C 語言練習)       *\n");
    printf("*                                      *\n");
    for (int i = 0; i < 16; i++) {
        printf("*       這是你的個人風格畫面 %2d       *\n", i + 1);
    }
    printf("*                                      *\n");
    printf("****************************************\n");
    printf("\n請按任意鍵繼續...\n");
    getch();
}

// 清除螢幕
void clearScreen() {
    system("cls"); // 若在 Linux 上執行，請改為 system("clear");
}

// 密碼驗證
int checkPassword() {
    int inputPassword;
    printf("請輸入 4 位數字密碼: ");
    scanf("%d", &inputPassword);
    return (inputPassword == PASSWORD);
}

// 顯示主選單
void showMenu() {
    printf("-------------------------------\n");
    printf("|  ‘A’...‘Z’ : Uppercase       |\n");
    printf("|  ‘a’...‘z’ : Lowercase       |\n");
    printf("|  ‘0’...‘9’ : Digit           |\n");
    printf("|  Otherwise : 你的姓名        |\n");
    printf("-------------------------------\n");
}

// 處理使用者輸入
void processInput() {
    char ch;
    printf("請輸入一個字元: ");
    ch = getch(); // 讀取單一字元
    printf("%c\n", ch);
    
    if (ch >= 'A' && ch <= 'Z') {
        printf("Uppercase\n");
    } else if (ch >= 'a' && ch <= 'z') {
        printf("Lowercase\n");
    } else if (ch >= '0' && ch <= '9') {
        printf("Digit\n");
    } else {
        printf("你的班級座號及姓名\n");
    }
}

/*
===========================================
【程式說明】
本程式為 C 語言練習，包含以下功能：
1. 顯示個人風格畫面。
2. 要求使用者輸入密碼進行驗證。
3. 顯示選單，並根據使用者輸入的字元類別進行分類顯示。

【討論】
此程式展示了基本的 C 語言輸入與輸出處理，並透過條件判斷決定輸入的類別。
它包含 getch() 來讀取單一字元，並使用 system("cls") 來清除畫面。
這對於初學者而言，是個很好的練習案例，幫助理解基本函式與控制流程。

【心得】
本程式結構清晰，適合作為學習 C 語言的入門範例。
透過密碼驗證機制，讓程式更具互動性，且利用條件判斷提升了邏輯處理能力。
未來可以進一步改進，如增加錯誤輸入的處理或擴充更多功能。
===========================================
*/
