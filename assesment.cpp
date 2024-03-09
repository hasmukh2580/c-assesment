#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class RockPaperScissors {
public:
    void playGame() {
        int playerChoice, computerChoice;
        char continueGame;

        // Seed the random number generator
        srand(time(0));

        do {
            // Display menu
            cout << "Rock Paper Scissors Game\n";
            cout << "1. Rock\n";
            cout << "2. Paper\n";
            cout << "3. Scissors\n";
            cout << "Enter your choice (1-3): ";
            cin >> playerChoice;

            // Generate computer's choice
            computerChoice = (rand() % 3) + 1;

            // Display choices
            cout << "Your choice: ";
            displayChoice(playerChoice);
            cout << "Computer's choice: ";
            displayChoice(computerChoice);

            // Determine the winner
            determineWinner(playerChoice, computerChoice);

            // Ask if the user wants to play again
            cout << "Do you want to play again? (y/n): ";
            cin >> continueGame;
        } while (tolower(continueGame) == 'y');
    }

private:
    void displayChoice(int choice) {
        switch (choice) {
            case 1:
                cout << "Rock\n";
                break;
            case 2:
                cout << "Paper\n";
                break;
            case 3:
                cout << "Scissors\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    }

    void determineWinner(int playerChoice, int computerChoice) {
        if (playerChoice == computerChoice) {
            cout << "It's a tie!\n";
        } else if ((playerChoice == 1 && computerChoice == 3) ||
                   (playerChoice == 2 && computerChoice == 1) ||
                   (playerChoice == 3 && computerChoice == 2)) {
            cout << "You win!\n";
        } else {
            cout << "Computer wins!\n";
        }
    }
};

int main() {
    RockPaperScissors game;
    game.playGame();

    return 0;
}

