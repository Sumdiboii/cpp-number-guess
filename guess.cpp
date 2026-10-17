#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

// Function to load the best score from a file
int loadHighScore() {
    std::ifstream file("highscore.txt");
    int bestScore = 999; // Default high score (lower is better)
    if (file.is_open()) {
        file >> bestScore;
        file.close();
    }
    return bestScore;
}

// Function to save the best score to a file
void saveHighScore(int score) {
    std::ofstream file("highscore.txt");
    if (file.is_open()) {
        file << score;
        file.close();
    }
}

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    char playAgain = 'y';
    int highScore = loadHighScore();

    std::cout << "=====================================\n";
    std::cout << "       WELCOME TO NUMBER GUESS       \n";
    std::cout << "=====================================\n";
    if (highScore != 999) {
        std::cout << "Current Best Score (Fewest Tries): " << highScore << "\n\n";
    } else {
        std::cout << "No high score set yet. Be the first!\n\n";
    }

    while (playAgain == 'y' || playAgain == 'Y') {
        int secretNumber = std::rand() % 100 + 1; // Number between 1 and 100
        int guess = 0;
        int attempts = 0;

        std::cout << "I have picked a number between 1 and 100. Try to guess it!\n";

        // Game Loop
        while (guess != secretNumber) {
            std::cout << "Enter your guess: ";
            if (!(std::cin >> guess)) {
                std::cout << "Invalid input. Please enter a number.\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            }

            attempts++;

            if (guess > secretNumber) {
                std::cout << "Too high! Try again.\n";
            } else if (guess < secretNumber) {
                std::cout << "Too low! Try again.\n";
            } else {
                std::cout << "\n🎉 Correct! You found the number in " << attempts << " attempts.\n";
            }
        }

        // Check and update high score
        if (attempts < highScore) {
            highScore = attempts;
            saveHighScore(highScore);
            std::cout << "🏆 NEW HIGH SCORE! Saved to disk.\n";
        } else {
            std::cout << "Your best score remains: " << highScore << " attempts.\n";
        }

        std::cout << "\nPlay again? (y/n): ";
        std::cin >> playAgain;
        std::cout << "\n-------------------------------------\n";
    }

    std::cout << "Thanks for playing!\n";
    return 0;
}