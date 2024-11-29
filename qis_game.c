#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_LINE_LENGTH 512
#define MAX_DISPLAY_QUESTIONS 15 // Maximum questions to display

// Structure to store a question
typedef struct {
    char question[256];
    char options[4][128];
    char correct_option;
} QuizQuestion;

// Function to load questions from a CSV file
int load_questions(const char *filename, QuizQuestion *questions) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return 0;
    }

    char line[MAX_LINE_LENGTH];
    int count = 0;

    // Skip the header line
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file) && count < MAX_QUESTIONS) {
        char *token = strtok(line, ",");
        if (!token) continue; // Skip invalid lines
        strcpy(questions[count].question, token);

        for (int i = 0; i < 4; i++) {
            token = strtok(NULL, ",");
            if (!token) break; // Stop if there are fewer than 4 options
            strcpy(questions[count].options[i], token);
        }

        token = strtok(NULL, ",");
        if (token) {
            questions[count].correct_option = token[0]; // First character (A/B/C/D)
            count++;
        }
    }

    fclose(file);
    return count;
}

// Function to display a question and get the user's answer
char ask_question(QuizQuestion q) {
    printf("\n%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%c) %s\n", 'A' + i, q.options[i]);
    }
    printf("Your answer (A/B/C/D): ");

    char answer;
    scanf(" %c", &answer);
    return answer;
}

// Function to check the answer
int check_answer(char user_answer, char correct_answer) {
    return (user_answer == correct_answer);
}

// Main function
int main() {
    QuizQuestion questions[MAX_QUESTIONS];
    int question_count = load_questions("questions.csv", questions);

    if (question_count == 0) {
        printf("No questions loaded. Exiting.\n");
        return 1;
    }

    int score = 0;
    int total_questions = question_count > MAX_DISPLAY_QUESTIONS ? MAX_DISPLAY_QUESTIONS : question_count;

    printf("Welcome to the QIS Game!\n");
    printf("------------------------\n");
    printf("Answer the questions by typing A, B, C, or D.\n\n");
    printf("The quiz will have a maximum of %d questions.\n\n", total_questions);

    // Loop through the questions, limited to the maximum number to display
    for (int i = 0; i < total_questions; i++) {
        char user_answer = ask_question(questions[i]);

        if (check_answer(user_answer, questions[i].correct_option)) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer was %c.\n", questions[i].correct_option);
        }
    }

    printf("\nGame Over!\n");
    printf("Your final score is %d/%d.\n", score, total_questions);

    return 0;
}
