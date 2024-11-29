#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to display the current state of the word
void displayWord(char word[], char guessed[]) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (guessed[i]) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

// Function to check if the player has guessed the word
int isWordGuessed(char word[], char guessed[]) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (!guessed[i]) {
            return 0; // Word is not fully guessed
        }
    }
    return 1; // Word is fully guessed
}

int main() {
    char word[100];           // The word to guess
    char guessedLetters[26];  // Tracks guessed letters (A-Z)
    int incorrectGuesses = 0; // Counter for wrong guesses
    int maxAttempts = 6;      // Max allowed wrong guesses

    printf("Enter a word for Hangman (player 1): ");
    scanf("%s", word);

    // Convert the word to uppercase for consistency
    for (int i = 0; word[i] != '\0'; i++) {
        word[i] = toupper(word[i]);
    }

    // Hide the word by clearing the screen
    printf("\033[H\033[J"); // Clear screen for most terminals
    printf("The Hangman game begins!\n");

    // Initialize guessed array to track correctly guessed letters
    char guessed[strlen(word)];
    memset(guessed, 0, sizeof(guessed));
    memset(guessedLetters, 0, sizeof(guessedLetters));

    while (incorrectGuesses < maxAttempts) {
        char guess;
        printf("\nCurrent word: ");
        displayWord(word, guessed);

        printf("\nIncorrect guesses: %d/%d\n", incorrectGuesses, maxAttempts);
        printf("Guessed letters: ");
        for (int i = 0; i < 26; i++) {
            if (guessedLetters[i]) {
                printf("%c ", 'A' + i);
            }
        }
        printf("\nEnter your guess (A-Z): ");
        scanf(" %c", &guess);

        // Convert guess to uppercase
        guess = toupper(guess);

        // Validate input
        if (!isalpha(guess)) {
            printf("Invalid input! Please enter a letter (A-Z).\n");
            continue;
        }

        // Check if the letter was already guessed
        if (guessedLetters[guess - 'A']) {
            printf("You already guessed '%c'!\n", guess);
            continue;
        }

        // Mark the letter as guessed
        guessedLetters[guess - 'A'] = 1;

        // Check if the guessed letter is in the word
        int found = 0;
        for (int i = 0; word[i] != '\0'; i++) {
            if (word[i] == guess) {
                guessed[i] = 1;
                found = 1;
            }
        }

        if (found) {
            printf("Good guess! '%c' is in the word.\n", guess);
        } else {
            printf("Wrong guess! '%c' is not in the word.\n", guess);
            incorrectGuesses++;
        }

        // Check if the word is fully guessed
        if (isWordGuessed(word, guessed)) {
            printf("\nCongratulations! You guessed the word: %s\n", word);
            return 0;
        }
    }

    // If the player runs out of guesses
    printf("\nGame over! You've been hanged.\n");
    printf("The word was: %s\n", word);
    return 0;
}
