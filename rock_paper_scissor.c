#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int userChoice, computerChoice;
    int userScore = 0, computerScore = 0;
    char playAgain;

    srand(time(0)); 


    do {
        printf("\nEnter your choice:\n1. Stone\n2. Paper\n3. Scissors\nYour choice: ");
        scanf("%d", &userChoice);

        if (userChoice < 1 || userChoice > 3) {
            printf("Invalid choice! Please select 1, 2, or 3.\n");
            continue; 
        }

        computerChoice = (rand() % 3) + 1;

        printf("Computer chose: ");
        if (computerChoice == 1) printf("Stone\n");
        else if (computerChoice == 2) printf("Paper\n");
        else printf("Scissors\n");

        
        if (userChoice == computerChoice) {
            printf("It's a Draw!\n");
        } 
        else if ((userChoice == 1 && computerChoice == 3) ||
                 (userChoice == 2 && computerChoice == 1) ||
                 (userChoice == 3 && computerChoice == 2)) {
            printf("You Win this round!\n");
            userScore++;
        } 
        else {
            printf("Computer Wins this round!\n");
            computerScore++;
        }

        printf("\nCurrent Score -> You: %d | Computer: %d\n", userScore, computerScore);

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain); 

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\n=== Final Score ===\nYou: %d\nComputer: %d\n", userScore, computerScore);

    if (userScore > computerScore) {
        printf("Congratulations! You won the game! \n");
    } else if (computerScore > userScore) {
        printf("Computer wins the game! Better luck next time. \n");
    } else {
        printf("The game ended in a Draw! \n");
    }

    printf("Thank you for playing!\n");

    return 0;
}
