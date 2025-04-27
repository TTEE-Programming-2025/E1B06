#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h> // For tolower function

// Function prototypes
void printRightTriangle(int n);
void displayMultiplicationTable();
void calculateSumOfSquares(int n);
void pauseAndContinue();
void clearScreen();

int main() {
    char choice;
    int n;

    while (1) {
        clearScreen();
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

        clearScreen();

        switch (tolower(choice)) { // Handle uppercase and lowercase inputs
            case 'a':
                printf("\nEnter the size of the triangle (1-50): ");
                if (scanf("%d", &n) != 1 || getchar() != '\n') { // Validate integer input
                    printf("Invalid input! Please enter a valid number.\n");
                    while (getchar() != '\n'); // Clear input buffer
                } else if (n < 1 || n > 50) {
                    printf("Invalid size! Please enter a number between 1 and 50.\n");
                } else {
                    printRightTriangle(n);
                }
                break;
            case 'b':
                displayMultiplicationTable();
                break;
            case 'c':
                printf("\nEnter an integer n (1-20): ");
                if (scanf("%d", &n) != 1 || getchar() != '\n') { // Validate integer input
                    printf("Invalid input! Please enter a valid number.\n");
                    while (getchar() != '\n'); // Clear input buffer
                } else if (n < 1 || n > 20) {
                    printf("Invalid input! Please enter a number between 1 and 20.\n");
                } else {
                    calculateSumOfSquares(n);
                }
                break;
            case 'x':
                printf("\nExiting program. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }

        // Pause and ask if the user wants to continue
        pauseAndContinue();
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
    long long sum = 0; // Use long long for larger sums
    for (int i = 1; i <= n * n; i++) {
        sum += (long long)i * i;
    }
    printf("\nThe sum of squares from 1 to %d^2 is: %lld\n", n, sum);
}

// Function to pause and ask the user if they want to continue
void pauseAndContinue() {
    char response;
    printf("\nDo you want to continue? (y/n): ");
    response = getchar();
    getchar(); // Consume the newline character

    if (tolower(response) == 'n') {
        printf("\nExiting program. Goodbye!\n");
        exit(0);
    } else if (tolower(response) != 'y') {
        printf("\nInvalid response! Assuming you want to continue.\n");
    }
}

// Function to clear the screen
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
