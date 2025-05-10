#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ROWS 9
#define COLUMNS 9

void displaySeats(char seats[ROWS][COLUMNS]) {
    printf("\n   \123456789\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%2d ", ROWS - i);
        for (int j = 0; j < COLUMNS; j++) {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
}

bool isValidSeat(int row, int col, char seats[ROWS][COLUMNS]) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLUMNS && seats[row][col] == '-';
}

void bookSeatAutomatically(char seats[ROWS][COLUMNS], int count) {
    int booked = 0;
    for (int i = 0; i < ROWS && booked < count; i++) {
        for (int j = 0; j < COLUMNS && booked < count; j++) {
            if (seats[i][j] == '-') {
                seats[i][j] = '*';
                booked++;
            }
        }
    }
    if (booked == count) {
        printf("\nSeats successfully booked.\n");
    } else {
        printf("\nNot enough seats available.\n");
    }
}

void bookSeatManually(char seats[ROWS][COLUMNS], int count) {
    int booked = 0;
    while (booked < count) {
        int row, col;
        printf("\nEnter the row and column (e.g., 1 2): ");
        scanf("%d %d", &row, &col);
        row = ROWS - row;
        col--;
        if (isValidSeat(row, col, seats)) {
            seats[row][col] = '@';
            booked++;
        } else {
            printf("\nInvalid seat selection. Try again.\n");
        }
    }
    printf("\nSeats successfully booked.\n");
}

void menu() {
    printf("\n------[Booking System]------\n");
    printf("a. Available seats\n");
    printf("b. Arrange for you\n");
    printf("c. Choose by yourself\n");
    printf("d. Exit\n");
    printf("----------------------------\n");
}

int main() {
    char seats[ROWS][COLUMNS];
    memset(seats, '-', sizeof(seats));
    char choice;
    while (true) {
        menu();
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);

        if (choice == 'a') {
            displaySeats(seats);
        } else if (choice == 'b') {
            int num;
            printf("\nEnter the number of seats to book (1-4): ");
            scanf("%d", &num);
            if (num >= 1 && num <= 4) {
                bookSeatAutomatically(seats, num);
                displaySeats(seats);
            } else {
                printf("\nInvalid number of seats.\n");
            }
        } else if (choice == 'c') {
            int num;
            printf("\nEnter the number of seats to book (1-4): ");
            scanf("%d", &num);
            if (num >= 1 && num <= 4) {
                bookSeatManually(seats, num);
                displaySeats(seats);
            } else {
                printf("\nInvalid number of seats.\n");
            }
        } else if (choice == 'd') {
            char confirm;
            printf("\nContinue? (y/n): ");
            scanf(" %c", &confirm);
            if (confirm == 'n') {
                printf("\nExiting the system. Goodbye!\n");
                break;
            }
        } else {
            printf("\nInvalid choice. Try again.\n");
        }
    }

    return 0;
}
