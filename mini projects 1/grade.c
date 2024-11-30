#include <stdio.h>

int main() {
    int numStudents;
    float grade, sum = 0, highest = 0, lowest = 100; // Initial lowest set to maximum possible grade.

    // Input the number of students
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Check for valid student count
    if (numStudents <= 0) {
        printf("Invalid number of students. Exiting the program.\n");
        return 1;
    }

    float grades[numStudents]; // Array to store grades

    // Input grades
    for (int i = 0; i < numStudents; i++) {
        printf("Enter grade for student %d (0-100): ", i + 1);
        scanf("%f", &grade);

        // Validate grade
        if (grade < 0 || grade > 100) {
            printf("Invalid grade. Please enter a value between 0 and 100.\n");
            i--; // Retry the same student
            continue;
        }

        grades[i] = grade;
        sum += grade;

        // Update highest and lowest grades
        if (grade > highest) highest = grade;
        if (grade < lowest) lowest = grade;
    }

    // Calculate average
    float average = sum / numStudents;

    // Output results
    printf("\nClass Grades Summary:\n");
    printf("---------------------\n");
    printf("Number of students: %d\n", numStudents);
    printf("Average grade: %.2f\n", average);
    printf("Highest grade: %.2f\n", highest);
    printf("Lowest grade: %.2f\n", lowest);

    return 0;
}
