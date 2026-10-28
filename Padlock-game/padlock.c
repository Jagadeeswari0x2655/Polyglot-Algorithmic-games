#include <stdio.h>
#include <stdlib.h> // ----Required for malloc and rand() and srand()----
#include <time.h>   // Required for time()
// ----Declare a global pointer for array of padlock code and a global variable for size of code length----
int *padlock_code = NULL;
int code_length;
// ----Function to generate a padlock code with UNIQUE digits----
void set_padlock_code() {
    // ----Track used digits: index represents the digit (0-9). 0 = unused, 1 = used.
    int used_digit[10] = {0}; 
    int random_digit;

    for (int i = 0; i < code_length; i++) {
        // this do while is used to create unique digits in padlock_code array
        do {
            random_digit = rand() % 10; // Generate a digit between 0 and 9
        } while (used_digit[random_digit] == 1); // If already used, loop again

        // ----Assign the unique digit to our padlock array----
        padlock_code[i] = random_digit;
        
        // ----Mark this digit as used so it won't be picked again in this round----
        used_digit[random_digit] = 1; 
    }
}
int main()
{
    //----⭐ CRITICAL FIX: Seed the random generator ONCE at the start of main----
    srand(time(NULL)); 
    char replay_choice; // ----Variable to store 'y' or 'n' to ask user they want to play again----
    // ----OUTER LOOP: Controls the entire game session----
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
            scanf(" %d", &code_length);
            // ----Check if the choice is invalid to print a warning----
            if (code_length < 3 || code_length > 5) {
                printf("\n[ERROR] '%d' is invalid! Please try again.\n\n", code_length);
            }
        } while (code_length < 3 || code_length > 5); // ----The loop repeats as long as the condition is TRUE----
        //----⭐ CRITICAL FIX: Allocate memory for the code length before filling it!----
        padlock_code = (int *)malloc(code_length * sizeof(int));
        if (padlock_code == NULL) {
            printf("[ERROR] Memory allocation failed!\n");
            return 1; // Exit program if computer runs out of memory
        }
        // ----create padlock code to guess----
        set_padlock_code();
        // ----Clean up the memory allocated for this specific round----
        free(padlock_code);
        padlock_code = NULL;

        // ----Ask the user if they want to play again----
        printf("\nDo you want to play again? (y/n): ");
        
        // ----Note: The space before %c skips any leftover newline character in the buffer----
        scanf(" %c", &replay_choice); 
        printf("\n");
    }while(replay_choice == 'y' || replay_choice == 'Y');
    printf("Thank you for playing the Padlock Game! Goodbye.\n");
    return 0;
}
