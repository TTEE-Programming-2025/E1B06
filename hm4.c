#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 10
#define SUBJECTS 6
#define PASSWORD 2025

const char *subjects[SUBJECTS] = {"Chinese", "English", "Math", "Science", "Social", "PE"};

typedef struct {
    char name[50];
    int grades[SUBJECTS];
    float average;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

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

void grade_ranking()
{
    int i;
    int j;
    Student temp;
    if (student_count == 0) {
        printf("No student data available!\n");
        return;
    }
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
            case 'e':
                printf("Are you sure you want to exit? (y/n): ");
                scanf(" %c", &confirm);
                if (confirm == 'y' || confirm == 'Y') {
                    printf("System exited.\n");
                    return 0;
                }
                break;
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}
