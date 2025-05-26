#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 10
#define SUBJECTS 6
#define PASSWORD 2025

// 學科名稱
const char *subjects[SUBJECTS] = {"Chinese", "English", "Math", "Science", "Social", "PE"};

// 學生結構
struct Student {
    char name[50];
    int grades[SUBJECTS];
    float average;
};

struct Student students[MAX_STUDENTS];
int student_count = 0;

void enter_student_grades() {
    int n, i, j;
    printf("Enter number of students (5~10): ");
    scanf("%d", &n);
    if(n < 5 || n > 10) {
        printf("Invalid number of students!\n");
        return;
    }
    student_count = n;
    for(i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i+1);
        scanf("%s", students[i].name);
        students[i].average = 0;
        for(j = 0; j < SUBJECTS; j++) {
            printf("Enter %s grade: ", subjects[j]);
            scanf("%d", &students[i].grades[j]);
            students[i].average += students[i].grades[j];
        }
        students[i].average /= SUBJECTS;
    }
    printf("Data entry completed!\n");
}

void display_student_grades() {
    int i, j;
    if(student_count == 0) {
        printf("No student data available!\n");
        return;
    }
    for(i = 0; i < student_count; i++) {
        printf("%s: ", students[i].name);
        for(j = 0; j < SUBJECTS; j++) {
            printf("%s:%d ", subjects[j], students[i].grades[j]);
        }
        printf("Average: %.2f\n", students[i].average);
    }
}

void search_student_grades() {
    char name[50];
    int i, j, found = 0;
    printf("Enter student name to search: ");
    scanf("%s", name);
    for(i = 0; i < student_count; i++) {
        if(strcmp(students[i].name, name) == 0) {
            printf("%s: ", students[i].name);
            for(j = 0; j < SUBJECTS; j++) {
                printf("%s:%d ", subjects[j], students[i].grades[j]);
            }
            printf("Average: %.2f\n", students[i].average);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Student not found!\n");
    }
}

void grade_ranking() {
    int i, j;
    struct Student temp;
    if(student_count == 0) {
        printf("No student data available!\n");
        return;
    }
    for(i = 0; i < student_count - 1; i++) {
        for(j = i + 1; j < student_count; j++) {
            if(students[i].average < students[j].average) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    for(i = 0; i < student_count; i++) {
        printf("%d. %s - Average: %.2f\n", i+1, students[i].name, students[i].average);
    }
}

int main() {
    int password, i;
    char option;

    printf("================== Welcome ==================\n");
    printf("Enter 4-digit password to login: ");
    scanf("%d", &password);

    if(password != PASSWORD) {
        printf("Wrong password. Access denied.\n");
        return 0;
    }

    while(1) {
        printf("\n----------- [Grade System] -----------\n");
        printf("a. Enter student grades\n");
        printf("b. Display student grades\n");
        printf("c. Search for student grades\n");
        printf("d. Grade ranking\n");
        printf("e. Exit system\n");
        printf("Choose option: ");
        scanf(" %c", &option);

        switch(option) {
            case 'a':
                enter_student_grades();
                break;
            case 'b':
                display_student_grades();
                break;
            case 'c':
                search_student_grades();
                break;
            case 'd':
                grade_ranking();
                break;
            case 'e': {
                char confirm;
                printf("Are you sure you want to exit? (y/n): ");
                scanf(" %c", &confirm);
                if(confirm == 'y' || confirm == 'Y') {
                    printf("System exited.\n");
                    return 0;
                }
                break;
            }
            default:
                printf("Invalid option.\n");
        }
    }
}
