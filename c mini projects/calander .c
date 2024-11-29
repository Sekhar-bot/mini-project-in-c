#include <stdio.h>

// Function to check if a year is a leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to get the number of days in a month
int getDaysInMonth(int month, int year) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29; // February in a leap year
    }
    return days[month - 1];
}

// Function to calculate the weekday of January 1st for a given year
int getStartDay(int year) {
    int startDay = 1; // January 1, 1900 is a Monday
    for (int i = 1900; i < year; i++) {
        startDay += isLeapYear(i) ? 366 : 365;
    }
    return startDay % 7; // Return day of the week (0 = Sunday, 6 = Saturday)
}

// Function to print the calendar for a given year
void printCalendar(int year) {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    const char *days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    int startDay = getStartDay(year);

    printf("\nCalendar for the Year %d\n\n", year);

    for (int month = 1; month <= 12; month++) {
        int daysInMonth = getDaysInMonth(month, year);

        // Print month name
        printf("      %s\n", months[month - 1]);
        printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        // Print leading spaces for the first week
        for (int i = 0; i < startDay; i++) {
            printf("     ");
        }

        // Print all days in the month
        for (int day = 1; day <= daysInMonth; day++) {
            printf("%3d  ", day);
            if ((startDay + day) % 7 == 0) {
                printf("\n");
            }
        }

        // Adjust start day for the next month
        startDay = (startDay + daysInMonth) % 7;

        printf("\n\n");
    }
}

int main() {
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);

    if (year < 1900) {
        printf("Error: Year must be 1900 or later.\n");
        return 1;
    }

    printCalendar(year);

    return 0;
}
