#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
void printRightTriangle(int n);
void displayMultiplicationTable();
void calculateSumOfSquares(int n);

int main() {
    char choice;
    int n;

    while (1) {
        // Display menu
        printf("\n=================\n");
        printf("a. Print Right Triangle\n");
        printf("b. Display Multiplication Table\n");
        printf("c. Calculate Sum of Squares\n");
        printf("x. Exit\n");
        printf("=================\n");
        printf("Enter your choice: ");
        choice = getchar();
        getchar(); // Consume the newline character

        switch (choice) {
            case 'a':
                printf("\nEnter the size of the triangle: ");
                scanf("%d", &n);
                getchar(); // Consume the newline character
                printRightTriangle(n);
                break;
            case 'b':
                displayMultiplicationTable();
                break;
            case 'c':
                printf("\nEnter an integer n: ");
                scanf("%d", &n);
                getchar(); // Consume the newline character
                calculateSumOfSquares(n);
                break;
            case 'x':
                printf("\nExiting program. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}

// Function to print a right triangle
void printRightTriangle(int n) {
    printf("\nRight Triangle:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to display multiplication table
void displayMultiplicationTable() {
    printf("\nMultiplication Table:\n");
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }
}

// Function to calculate the sum of squares from 1 to n*n
void calculateSumOfSquares(int n) {
    int sum = 0;
    for (int i = 1; i <= n * n; i++) {
        sum += i * i;
    }
    printf("\nThe sum of squares from 1 to %d^2 is: %d\n", n, sum);
}
