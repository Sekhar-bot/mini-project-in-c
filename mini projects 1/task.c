#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100   // Maximum number of tasks
#define MAX_LENGTH 100  // Maximum length of each task

void displayMenu() {
    printf("\nTo-Do List Application\n");
    printf("-----------------------\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Delete Task\n");
    printf("4. Exit\n");
    printf("-----------------------\n");
    printf("Enter your choice: ");
}

int main() {
    char tasks[MAX_TASKS][MAX_LENGTH]; // Array to store tasks
    int taskCount = 0; // Current number of tasks
    int choice, deleteIndex;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add Task
                if (taskCount >= MAX_TASKS) {
                    printf("Error: Task list is full! Cannot add more tasks.\n");
                } else {
                    printf("Enter the task: ");
                    getchar(); // Clear input buffer
                    fgets(tasks[taskCount], MAX_LENGTH, stdin);
                    tasks[taskCount][strcspn(tasks[taskCount], "\n")] = '\0'; // Remove trailing newline
                    taskCount++;
                    printf("Task added successfully.\n");
                }
                break;

            case 2: // View Tasks
                if (taskCount == 0) {
                    printf("No tasks to display.\n");
                } else {
                    printf("\nYour Tasks:\n");
                    for (int i = 0; i < taskCount; i++) {
                        printf("%d. %s\n", i + 1, tasks[i]);
                    }
                }
                break;

            case 3: // Delete Task
                if (taskCount == 0) {
                    printf("No tasks to delete.\n");
                } else {
                    printf("Enter the task number to delete (1-%d): ", taskCount);
                    scanf("%d", &deleteIndex);

                    if (deleteIndex < 1 || deleteIndex > taskCount) {
                        printf("Invalid task number.\n");
                    } else {
                        // Shift tasks to fill the gap
                        for (int i = deleteIndex - 1; i < taskCount - 1; i++) {
                            strcpy(tasks[i], tasks[i + 1]);
                        }
                        taskCount--;
                        printf("Task deleted successfully.\n");
                    }
                }
                break;

            case 4: // Exit
                printf("Exiting the To-Do List application. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}
