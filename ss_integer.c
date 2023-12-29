#include <stdio.h>
#include <stdlib.h>

// seven-segment representation for all digits 0-9
const char segments[11][3][3] = {
    { {' ', '_', ' '}, {'|', ' ', '|'}, {'|', '_', '|'} },
    { {' ', ' ', ' '}, {' ', '|', ' '}, {' ', '|', ' '} },
    { {' ', '_', ' '}, {' ', '_', '|'}, {'|', '_', ' '} },
    { {' ', '_', ' '}, {' ', '_', '|'}, {' ', '_', '|'} },
    { {' ', ' ', ' '}, {'|', '_', '|'}, {' ', ' ', '|'} },
    { {' ', '_', ' '}, {'|', '_', ' '}, {' ', '_', '|'} },
    { {' ', '_', ' '}, {'|', '_', ' '}, {'|', '_', '|'} }, 
    { {' ', '_', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'} },
    { {' ', '_', ' '}, {'|', '_', '|'}, {'|', '_', '|'} },
    { {' ', '_', ' '}, {'|', '_', '|'}, {' ', '_', '|'} },
    { {' ', ' ', ' '}, {' ', '_', ' '}, {' ', ' ', ' '} }
};

// function to display a single digit in seven-digit format 
void displayDigit(int digit) {
    // if digit is less than 0 or greter than 9: 
    if (digit < 0 || digit > 9) {      
        printf("Invalid digit: %d\n", digit);       // invalid
        return; 
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c", segments[digit][i][j]);    
        }
        printf("\n"); 
    }
}

int main() {
    char choice; 
    int num; 

    do {
        printf("Enter an integer: ");       // user input for integer
        if (scanf("%d", &num) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            while (getchar() != '\n'); 
            continue;
        }

        printf("Displaying %d in seven-segment format:\n", num);

        // Display each digit
        do {
            int digit = num % 10;
            displayDigit(digit);
            num /= 10;
        } 
        while (num > 0);

        // ask user if they would like to continue
        printf("Do you want to continue? (Y/N) ");
        scanf(" %c", &choice); 

    } 
    while (choice == 'Y' || choice == 'y');

    return 0;
}

