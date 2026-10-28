#include <stdio.h>
#include <stdlib.h> // Required for malloc and free
// Declare a global pointer for array of padlock code and a global variable for size of code length
int *padlock_code = NULL;
int code_length;
int main()
{
    char replay_choice; // Variable to store 'y' or 'n'
    // OUTER LOOP: Controls the entire game session
    do{
            // ----Display the clean menu to the user----
        printf("=================================\n");
        printf("       PADLOCK GAME MENU\n");
        printf("=================================\n");
        printf("Select the game difficulty code length:\n");
        printf("[3] For a 3-digit code\n");
        printf("[4] For a 4-digit code\n");
        printf("[5] For a 5-digit code\n\n");
            // ----Keep looping until the user gives a valid choice----
        do{   
            printf("Enter your choice (3, 4, or 5): ");
            scanf("%d", &code_length);
                // ----Check if the choice is invalid to print a warning----
            if (code_length < 3 || code_length > 5) {
                printf("\n[ERROR] '%d' is invalid! Please try again.\n\n", code_length);
            }
        } while (code_length < 3 || code_length > 5); // ----The loop repeats as long as the condition is TRUE----
            // Clean up the memory allocated for this specific round
        free(padlock_code);
        padlock_code = NULL;

            // Ask the user if they want to play again
        printf("\nDo you want to play again? (y/n): ");
        
        // Note: The space before %c skips any leftover newline character in the buffer
        scanf(" %c", &replay_choice); 
        printf("\n");
    }while(replay_choice == 'y' || replay_choice == 'Y');
    printf("Thank you for playing the Padlock Game! Goodbye.\n");
    return 0;
}
