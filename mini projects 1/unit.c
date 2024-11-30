#include <stdio.h>

void convertTemperature() {
    int choice;
    float celsius, fahrenheit;

    printf("\nTemperature Conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &celsius);
        fahrenheit = (celsius * 9 / 5) + 32;
        printf("Temperature in Fahrenheit: %.2f°F\n", fahrenheit);
    } else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);
        celsius = (fahrenheit - 32) * 5 / 9;
        printf("Temperature in Celsius: %.2f°C\n", celsius);
    } else {
        printf("Invalid choice! Returning to main menu.\n");
    }
}

void convertDistance() {
    int choice;
    float miles, kilometers;

    printf("\nDistance Conversion:\n");
    printf("1. Miles to Kilometers\n");
    printf("2. Kilometers to Miles\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter distance in miles: ");
        scanf("%f", &miles);
        kilometers = miles * 1.60934;
        printf("Distance in kilometers: %.2f km\n", kilometers);
    } else if (choice == 2) {
        printf("Enter distance in kilometers: ");
        scanf("%f", &kilometers);
        miles = kilometers / 1.60934;
        printf("Distance in miles: %.2f miles\n", miles);
    } else {
        printf("Invalid choice! Returning to main menu.\n");
    }
}

void convertWeight() {
    int choice;
    float pounds, kilograms;

    printf("\nWeight Conversion:\n");
    printf("1. Pounds to Kilograms\n");
    printf("2. Kilograms to Pounds\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter weight in pounds: ");
        scanf("%f", &pounds);
        kilograms = pounds * 0.453592;
        printf("Weight in kilograms: %.2f kg\n", kilograms);
    } else if (choice == 2) {
        printf("Enter weight in kilograms: ");
        scanf("%f", &kilograms);
        pounds = kilograms / 0.453592;
        printf("Weight in pounds: %.2f lbs\n", pounds);
    } else {
        printf("Invalid choice! Returning to main menu.\n");
    }
}

int main() {
    int choice;

    while (1) {
        // Display menu
        printf("\nUnit Converter\n");
        printf("---------------\n");
        printf("1. Convert Temperature\n");
        printf("2. Convert Distance\n");
        printf("3. Convert Weight\n");
        printf("4. Exit\n");
        printf("---------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform selected conversion
        switch (choice) {
            case 1:
                convertTemperature();
                break;
            case 2:
                convertDistance();
                break;
            case 3:
                convertWeight();
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
