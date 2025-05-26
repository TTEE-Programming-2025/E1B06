#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 10  // 最大學生數量
#define SUBJECTS 6       // 科目數量
#define PASSWORD 2025    // 登入密碼

// 科目名稱陣列
const char *subjects[SUBJECTS] = {"Chinese", "English", "Math", "Science", "Social", "PE"};

// 學生資料結構
typedef struct {
    char name[50];               // 學生姓名
    int grades[SUBJECTS];        // 各科成績
    float average;               // 平均成績
} Student;

Student students[MAX_STUDENTS]; // 存放學生資料的陣列
int student_count = 0;          // 目前的學生數量

// 計算某位學生的平均成績
void calculate_average(s)
Student *s;
{
    int i;
    int sum = 0;
    for (i = 0; i < SUBJECTS; i++) {
        sum += s->grades[i];
    }
    s->average = (float)sum / SUBJECTS;
}

// 輸入學生成績資料
void enter_student_grades()
{
    int i;
    int j;
    int n;
    printf("Enter number of students (5~10): ");
    scanf("%d", &n);
    if (n < 5 || n > 10) {
        printf("Invalid number of students!\n");
        return;
    }
    student_count = n;
    for (i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        for (j = 0; j < SUBJECTS; j++) {
            printf("Enter %s grade: ", subjects[j]);
            scanf("%d", &students[i].grades[j]);
        }
        calculate_average(&students[i]);
    }
    printf("Data entry completed!\n");
}

// 顯示所有學生成績資料
void display_student_grades()
{
    int i;
    int j;
    if (student_count == 0) {
        printf("No student data available!\n");
        return;
    }
    for (i = 0; i < student_count; i++) {
        printf("%s: ", students[i].name);
        for (j = 0; j < SUBJECTS; j++) {
            printf("%s:%d ", subjects[j], students[i].grades[j]);
        }
        printf("Average: %.2f\n", students[i].average);
    }
}

// 搜尋單一學生成績
void search_student_grades()
{
    char name[50];
    int i;
    int j;
    printf("Enter student name to search: ");
    scanf("%s", name);
    for (i = 0; i < student_count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("%s: ", students[i].name);
            for (j = 0; j < SUBJECTS; j++) {
                printf("%s:%d ", subjects[j], students[i].grades[j]);
            }
            printf("Average: %.2f\n", students[i].average);
            return;
        }
    }
    printf("Student not found!\n");
}

// 依平均成績排序並顯示
void grade_ranking()
{
    int i;
    int j;
    Student temp;
    if (student_count == 0) {
        printf("No student data available!\n");
        return;
    }
    // 氣泡排序法由高到低排序
    for (i = 0; i < student_count - 1; i++) {
        for (j = i + 1; j < student_count; j++) {
            if (students[i].average < students[j].average) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    for (i = 0; i < student_count; i++) {
        printf("%d. %s - Average: %.2f\n", i + 1, students[i].name, students[i].average);
    }
}

// 顯示主選單
void show_menu()
{
    printf("\n----------- [Grade System] -----------\n");
    printf("a. Enter student grades\n");
    printf("b. Display student grades\n");
    printf("c. Search for student grades\n");
    printf("d. Grade ranking\n");
    printf("e. Exit system\n");
    printf("Choose option: ");
}

// 主程式進入點
int main()
{
    int password;
    char option;
    char confirm;

    printf("================== Welcome ==================\n");
    printf("Enter 4-digit password to login: ");
    scanf("%d", &password);

    if (password != PASSWORD) {
        printf("Wrong password. Access denied.\n");
        return 0;
    }

    while (1) {
        show_menu();
        scanf(" %c", &option);

        switch (option) {
            case 'a':
                enter_student_grades(); // 輸入成績
                break;
            case 'b':
                display_student_grades(); // 顯示成績
                break;
            case 'c':
                search_student_grades(); // 搜尋學生
                break;
            case 'd':
                grade_ranking(); // 成績排名
                break;
            case 'e':
                printf("Are you sure you want to exit? (y/n): ");
                scanf(" %c", &confirm);
                if (confirm == 'y' || confirm == 'Y') {
                    printf("System exited.\n");
                    return 0; // 結束程式
                }
                break;
            default:
                printf("Invalid option.\n"); // 錯誤選項
        }
    }

    return 0;
}

/*
相關說明、討論與心得：

本程式是一個簡易的學生成績管理系統，具備輸入成績、顯示所有資料、搜尋單一學生以及依平均成績排序的功能。

設計上採用結構（struct）儲存學生資料，利用陣列與迴圈處理多位學生與多科成績，並且使用傳統 C 語法（如 K&R 函式宣告形式）以確保能在 Dev-C++ 等不支援 C99 的編譯器下正確編譯。

透過此專案，我學會了：
1. 如何使用結構體管理複雜資料。
2. 基本的輸入輸出與條件控制流程。
3. 利用氣泡排序法完成成績由高至低排序。
4. 為保相容性遵守傳統 C 規範的重要性。

未來若擴充，可增加以下功能：
- 成績資料儲存至檔案與讀取功能。
- 成績合法性檢查（如 0~100 分限制）。
- 更友善的選單介面與錯誤處理。
*/
