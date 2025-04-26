#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    char user_Choice[3], playAgain;
    int user_Score = 0, computer_Score = 0;
    char *computer_Choice;
    int randomNumber;

    srand(time(0)); 

    do {
        printf("\nEnter your choice:\nS for Stone\nP for Paper\nSC for Scissors\nYour choice: ");
        scanf("%s", user_Choice);

        for (int i = 0; user_Choice[i]; i++) {
            if (user_Choice[i] >= 'a' && user_Choice[i] <= 'z') {
                user_Choice[i] -= 32;
            }
        }

        if (!(strcmp(user_Choice, "S") == 0 || strcmp(user_Choice, "P") == 0 || strcmp(user_Choice, "SC") == 0)) {
            printf("Invalid choice! Please select S, P, or SC.\n");
            continue; 
        }

        randomNumber = rand() % 3;
        if (randomNumber == 0) computer_Choice = "S";    
        else if (randomNumber == 1) computer_Choice = "P";  
        else computer_Choice = "SC";                       

        printf("Computer chose: ");
        if (strcmp(computer_Choice, "S") == 0) printf("Stone\n");
        else if (strcmp(computer_Choice, "P") == 0) printf("Paper\n");
        else printf("Scissors\n");

        if (strcmp(user_Choice, computer_Choice) == 0) {
            printf("It's a Draw!\n");
        } 
        else if ((strcmp(user_Choice, "S") == 0 && strcmp(computer_Choice, "SC") == 0) ||
                 (strcmp(user_Choice, "P") == 0 && strcmp(computer_Choice, "S") == 0) ||
                 (strcmp(user_Choice, "SC") == 0 && strcmp(computer_Choice, "P") == 0)) {
            printf("You Win this round!\n");
            user_Score++;
        } 
        else {
            printf("Computer Wins this round!\n");
            computer_Score++;
        }

        printf("\nCurrent Score -> You: %d | Computer: %d\n", user_Score, computer_Score);

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain); 

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\n=== Final Score ===\nYou: %d\nComputer: %d\n", user_Score, computer_Score);

    if (user_Score > computer_Score) {
        printf("Congratulations! You won the game! \n");
    } else if (computer_Score > user_Score) {
        printf("Computer wins the game! Better luck next time. \n");
    } else {
        printf("The game ended in a Draw! \n");
    }

    printf("Thank you for playing!\n");

    return 0;
}