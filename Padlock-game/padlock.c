#include <stdio.h>
#include <stdlib.h> // ----Required for malloc and rand() and srand()----
#include <time.h>   // ----Required for time()----

// ----Declare a global pointer for array of padlock code and a global variable for size of code length----
int *padlock_code = NULL;
int code_length;

// ----Declare a global pointer for array of user guess code and a global variable for total atempst based on code length----
int *user_guess_code=NULL;
int total_atempts;

// ----Array of color highlight to show user code  hints----
const char* color_highlight[]={
    "\033[1;31m",   // 0: Bold Red Text (1 = Bold, 31 = Red)
    "\033[0;38;5;208m", // 1: Orange Text (Extended 256-color palette index 208)
    "\033[1;30;42m" // 2: Bold Black Text on Green Background (1 = Bold, 30 = Black Text, 42 = Green BG)
};
const char* RESET = "\033[0m";

//print game instructions and rules based on the difficult level
void print_game_instructions(int code_length, int total_attempts) {
    
    printf("\n==================================================\n");
    printf("              🔐 THE PADLOCK CODE GAME            \n");
    printf("==================================================\n");
    printf("A secret passcode has been locked inside the vault.\n");
    printf("Your mission is to crack it before you run out of turns!\n\n");
    
    printf("📜 THE RULES:\n");
    printf("1. The code is exactly %d digits long.\n", code_length);
    printf("2. Every single digit in the code is UNIQUE (0-9).\n");
    printf("3. No duplicate numbers are allowed in your guess.\n\n");

    // ----Clear color definitions added inside your game instructions----
    printf("🎨 THE COLOR FEEDBACK SYSTEM:\n");
    printf(" %s X %s -> Green background: number is correct place in lock code\n",color_highlight[2],RESET);
    printf(" %s X %s -> Red text: number is not in lockcode\n",color_highlight[0],RESET);
    printf(" %s X %s -> Orange text: number is in lock code but not in correct place\n\n",color_highlight[1],RESET);
    
    printf("🎯 YOUR DIFFICULTY:\n");
    printf("* Code Length: %d numbers\n", code_length);
    printf("* Maximum Attempts Allowed: %d\n", total_attempts);
    printf("==================================================\n");
    printf("Good luck, Enter your first guess...\n\n");
}

// ----Function to generate a user guess code with UNIQUE digits----
void set_user_guess_code(){
    
        //----⭐ CRITICAL FIX: Allocate memory for the code length before filling it!----
        user_guess_code = (int *)malloc(code_length * sizeof(int));
        if (user_guess_code == NULL) {
            printf("[ERROR❌] Memory allocation failed!\n");
        }
    
        // ----Track used digits: index represents the digit (0-9). 0 = unused, 1 = used----
        int used_digit[10] = {0}; 
        int digit;
    
        for (int i = 0; i < code_length; i++) {
            do {
                printf("Enter a unique digit (0-9) for position %d: ", i + 1);
        
                // ----Verify scanf actually read a valid integer----
                if (scanf("%d", &digit) != 1) {
                    printf("❌Invalid input! Please enter a number.\n");
                    
                    // ----Clear the stuck character from the input buffer----
                    while (getchar() != '\n'); 
                    digit = -1; // Force loop to repeat
                    continue;
                }
                
                // ----Verify the number is a single digit----
                if (digit < 0 || digit > 9) {
                    printf("❌Out of range! Must be between 0 and 9.\n");
                    continue;
                }
                // ----Check for duplicates----
                if (used_digit[digit] == 1) {
                    printf("❌Digit %d already used! Try another.\n", digit);
                }
            } while (digit < 0 || digit > 9 || used_digit[digit] == 1);
            
            // Assign and mark as used
            user_guess_code[i] = digit;
            used_digit[digit] = 1; 
        }
}


// ----Function to generate a padlock code with UNIQUE digits----
void set_padlock_code() {
    
    // ----Track used digits: index represents the digit (0-9). 0 = unused, 1 = used----
    int used_digit[10] = {0}; 
    int random_digit;

    for (int i = 0; i < code_length; i++) {
        // ----this do while is used to create unique digits in padlock_code array----
        do {
            random_digit = rand() % 10; // ----Generate a digit between 0 and 9----
        } while (used_digit[random_digit] == 1); // ----If already used, loop again----

        // ----Assign the unique digit to our padlock array----
        padlock_code[i] = random_digit;
        
        // ----Mark this used digit as used so it won't be picked again in this round----
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
        printf("       🔐PADLOCK GAME MENU\n");
        printf("=================================\n");
        printf("Select the game difficulty code length:\n");
        printf("🟢[3] For a 3-digit code\n");
        printf("🟡[4] For a 4-digit code\n");
        printf("🔴[5] For a 5-digit code\n\n");
        
        // ----Keep looping until the user gives a valid choice----
        do{   
            printf("Enter your choice (3, 4, or 5): ");
            
            //----check if use enter any text other than number----
            if (scanf("%d", &code_length) != 1) {
                printf("❌Invalid input! Please enter a number.\n");
                while (getchar() != '\n'); // Clear bad text input
                code_length = 0; // Force loop to repeat
                continue;
            }
            
            // ----Check if the choice is invalid to print a warning----
            if (code_length < 3 || code_length > 5) {
                printf("\n[ERROR❌] '%d' is invalid! YOUR CHOICE is (3, 4, or 5). Please try again.\n\n", code_length);
            }
        } while (code_length < 3 || code_length > 5); // ----The loop repeats as long as the condition is TRUE----
        
        //----total atempst to guess the code based on code length difficulty----
        total_atempts=(code_length==3)?8:(code_length==4)?9:10;
        
        //----⭐ CRITICAL FIX: Allocate memory for the code length before filling it!----
        padlock_code = (int *)malloc(code_length * sizeof(int));
        if (padlock_code == NULL) {
            printf("[ERROR❌] Memory allocation failed!\n");
            return 1; // ----Exit program if computer runs out of memory----
        }
        
        // ----create padlock code to guess----
        set_padlock_code();

        //----print game rules----
        print_game_instructions(code_length,total_atempts);
        
        // ----Clean up the memory allocated for this specific round----
        free(padlock_code);
        padlock_code = NULL;

        // ----Ask the user if they want to play again----
        printf("\nDo you want to play again? (y/n): ");
        
        // ----Note: The space before %c skips any leftover newline character in the buffer----
        scanf(" %c", &replay_choice); 
        printf("\n");
    }while(replay_choice == 'y' || replay_choice == 'Y');
    
    printf("Thank you for playing the Padlock Game! Goodbye👋.\n");
    return 0;
}
