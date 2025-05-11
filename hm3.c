#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 9
#define COLUMNS 9

void displaySeats(char seats[ROWS][COLUMNS]) {
    int i, j;
    printf("\n   123456789\n");
    for (i = 0; i < ROWS; i++) {
        printf("%2d ", ROWS - i);
        for (j = 0; j < COLUMNS; j++) {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
}

int isValidSeat(int row, int col, char seats[ROWS][COLUMNS]) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLUMNS && seats[row][col] == '-';
}

void bookSeats(char seats[ROWS][COLUMNS], int count, int autoAssign) {
    int booked = 0;
    int i, j;
    if (autoAssign) {
        for (i = 0; i < ROWS && booked < count; i++) {
            for (j = 0; j < COLUMNS && booked < count; j++) {
                if (seats[i][j] == '-') {
                    seats[i][j] = '*';
                    booked++;
                }
            }
        }
    } else {
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
    }

    if (booked == count) {
        printf("\nSeats successfully booked.\n");
    } else {
        printf("\nNot enough seats available.\n");
    }
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
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            seats[i][j] = '-';
        }
    }

    char choice;
    while (1) {
        menu();
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                displaySeats(seats);
                break;
            case 'b': {
                int num;
                printf("\nEnter the number of seats to book (1-4): ");
                scanf("%d", &num);
                if (num >= 1 && num <= 4) {
                    bookSeats(seats, num, 1);
                    displaySeats(seats);
                } else {
                    printf("\nInvalid number of seats.\n");
                }
                break;
            }
            case 'c': {
                int num;
                printf("\nEnter the number of seats to book (1-4): ");
                scanf("%d", &num);
                if (num >= 1 && num <= 4) {
                    bookSeats(seats, num, 0);
                    displaySeats(seats);
                } else {
                    printf("\nInvalid number of seats.\n");
                }
                break;
            }
            case 'd': {
                char confirm;
                printf("\nContinue? (y/n): ");
                scanf(" %c", &confirm);
                if (confirm == 'n') {
                    printf("\nExiting the system. Goodbye!\n");
                    return 0;
                }
                break;
            }
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}
