#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 5 // Maximum number of attempts allowed
#define LOWER_LIMIT 1  // Lower bound of the range
#define UPPER_LIMIT 100 // Upper bound of the range

void playGame() {
    int randomNumber, userGuess, attempts = 0;
    char playAgain;

    // Generate a random number between LOWER_LIMIT and UPPER_LIMIT
    srand(time(0));
    randomNumber = (rand() % (UPPER_LIMIT - LOWER_LIMIT + 1)) + LOWER_LIMIT;

    printf("I have picked a number between %d and %d. Can you guess it?\n", LOWER_LIMIT, UPPER_LIMIT);

    while (attempts < MAX_ATTEMPTS) {
        printf("Enter your guess: ");
        scanf("%d", &userGuess);

        // Validate input
        if (userGuess < LOWER_LIMIT || userGuess > UPPER_LIMIT) {
            printf("Please guess a number within the range %d to %d.\n", LOWER_LIMIT, UPPER_LIMIT);
            continue;
        }

        attempts++;

        // Check the guess
        if (userGuess == randomNumber) {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            break;
        } else if (userGuess < randomNumber) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }
    }

    // Check if the user has exhausted attempts
    if (attempts == MAX_ATTEMPTS && userGuess != randomNumber) {
        printf("Sorry, you've used all %d attempts. The number was %d.\n", MAX_ATTEMPTS, randomNumber);
    }

    // Ask to play again
    printf("Do you want to play again? (y/n): ");
    getchar(); // Clear input buffer
    scanf("%c", &playAgain);
    if (playAgain == 'y' || playAgain == 'Y') {
        playGame(); // Restart the game
    } else {
        printf("Thanks for playing! Goodbye.\n");
    }
}

int main() {
    printf("Welcome to the Guess the Number Game!\n");
    playGame();
    return 0;
}
