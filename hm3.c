#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 9 // Define the number of rows in the seating arrangement
#define COLUMNS 9 // Define the number of columns in the seating arrangement

// Function to display the current seating arrangement
void displaySeats(char seats[ROWS][COLUMNS]) {
    int i, j;
    printf("\n   123456789\n"); // Print column headers
    for (i = 0; i < ROWS; i++) {
        printf("%2d ", ROWS - i); // Print row headers
        for (j = 0; j < COLUMNS; j++) {
            printf("%c", seats[i][j]); // Print each seat's status
        }
        printf("\n");
    }
}

// Function to validate if a seat can be booked
int isValidSeat(int row, int col, char seats[ROWS][COLUMNS]) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLUMNS && seats[row][col] == '-';
}

// Function to handle seat booking
void bookSeats(char seats[ROWS][COLUMNS], int count, int autoAssign) {
    int booked = 0; // Counter for booked seats
    int i, j;
    if (autoAssign) { // Automatic seat assignment
        for (i = 0; i < ROWS && booked < count; i++) {
            for (j = 0; j < COLUMNS && booked < count; j++) {
                if (seats[i][j] == '-') { // Check if seat is available
                    seats[i][j] = '*'; // Mark seat as booked
                    booked++;
                }
            }
        }
    } else { // Manual seat selection
        while (booked < count) {
            int row, col;
            printf("\nEnter the row and column (e.g., 1 2): ");
            scanf("%d %d", &row, &col);
            row = ROWS - row; // Convert user input to array index
            col--;
            if (isValidSeat(row, col, seats)) { // Validate the seat
                seats[row][col] = '@'; // Mark seat as booked
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

// Function to display the main menu
void menu() {
    printf("\n------[Booking System]------\n");
    printf("a. Available seats\n"); // Display option to view available seats
    printf("b. Arrange for you\n"); // Display option for automatic seat booking
    printf("c. Choose by yourself\n"); // Display option for manual seat booking
    printf("d. Exit\n"); // Display option to exit the program
    printf("----------------------------\n");
}

// Main function
int main() {
    char seats[ROWS][COLUMNS]; // Array to represent seating arrangement
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            seats[i][j] = '-'; // Initialize all seats as available
        }
    }

    char choice;
    while (1) {
        menu(); // Display the menu
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                displaySeats(seats); // Display the seating arrangement
                break;
            case 'b': {
                int num;
                printf("\nEnter the number of seats to book (1-4): ");
                scanf("%d", &num);
                if (num >= 1 && num <= 4) {
                    bookSeats(seats, num, 1); // Book seats automatically
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
                    bookSeats(seats, num, 0); // Book seats manually
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
                    return 0; // Exit the program
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

/*
Reflection:
Completing this project has been a valuable learning experience. I was able to deepen my understanding of essential C programming concepts, such as arrays, loops, and functions. The task of designing a user-friendly seating booking system helped me develop better problem-solving skills and required careful consideration of both functionality and user experience. While implementing and testing the code, I encountered challenges like validating user input and ensuring seamless integration between different functionalities. These challenges encouraged me to think critically and improve my debugging skills. Overall, this project has significantly enhanced my programming abilities and has motivated me to tackle more complex problems in the future.
*/
