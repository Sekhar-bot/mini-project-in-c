#include <stdio.h>

// Function to print a triangle pattern
void trianglePattern(int rows) {
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

// Function to print an inverted triangle pattern
void invertedTrianglePattern(int rows) {
    for (int i = rows; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

// Function to print a pyramid pattern
void pyramidPattern(int rows) {
    for (int i = 1; i <= rows; i++) {
        // Print spaces
        for (int j = 1; j <= rows - i; j++) {
            printf("  ");
        }
        // Print numbers
        for (int k = 1; k <= i; k++) {
            printf("%d ", k);
        }
        // Print numbers in reverse
        for (int k = i - 1; k >= 1; k--) {
            printf("%d ", k);
        }
        printf("\n");
    }
}

int main() {
    int choice, rows;

    while (1) {
        // Display menu
        printf("\nNumber Pattern Generator\n");
        printf("------------------------\n");
        printf("1. Triangle Pattern\n");
        printf("2. Inverted Triangle Pattern\n");
        printf("3. Pyramid Pattern\n");
        printf("4. Exit\n");
        printf("------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle choices
        switch (choice) {
            case 1:
                printf("Enter the number of rows: ");
                scanf("%d", &rows);
                trianglePattern(rows);
                break;

            case 2:
                printf("Enter the number of rows: ");
                scanf("%d", &rows);
                invertedTrianglePattern(rows);
                break;

            case 3:
                printf("Enter the number of rows: ");
                scanf("%d", &rows);
                pyramidPattern(rows);
                break;

            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}
