#include <stdio.h>

void start_tictoctoe(void)
{
    char replay_choice; // ----Variable to store 'y' or 'n' to ask user they want to play again----
    int mode;//----Variable to store mode of the game----
    // ----OUTER LOOP: Controls the entire game session----
    do{
        
        // ----Display the clean menu to the user----
        printf("=================================\n");
        printf("       ❌⭕ Tic-Tac-Toe\n");
        printf("=================================\n");
      
       // 1. Display Game Mode Menu 
        printf("+-----------------------------------------+\n");
        printf("|   ❌⭕TIC-TAC-TOE: SELECT GAME MODE     |\n");
        printf("+-----------------------------------------+\n");
        printf("|  👤🆚👤  [1] Player vs. Player (Local)  |\n");
        printf("|  🤖 🌱   [2] Player vs. AI (Easy)       |\n");
        printf("|  🤖 ⚡   [3] Player vs. AI (Medium)     |\n");
        printf("|  🤖 🧠   [4] Player vs. AI (Hard)       |\n");
        printf("+-----------------------------------------+\n");
       
        // ----Keep looping until the user gives a valid choice----
        do{   
            printf("Enter your choice (1, 2, 3, or 4): ");
            
            //----check if use enter any text other than number----
            if (scanf("%d", &mode) != 1) {
                printf("❌Invalid input! Please enter a number.\n");
                while (getchar() != '\n'); // Clear bad text input
                mode = 0; // Force loop to repeat
                continue;
            }
            
            // ----👇 MAKE SURE THIS LINE IS HERE (Right after scanf succeeds!) to remove leftover space ----
            while (getchar() != '\n'); 
            
            // ----Check if the choice is invalid to print a warning----
            if (mode < 1 || mode > 4) {
                printf("\n[ERROR❌] '%d' is invalid! YOUR CHOICE is (1, 2, 3, or 5). Please try again.\n\n", mode);
            }
        } while (mode < 1 || mode > 4); // ----The loop repeats as long as the condition is TRUE----  
      
        // ----Ask the user if they want to play again----
        printf("\nDo you want to play again? (y/n): ");
        
        // ----Note: The space before %c skips any leftover newline character in the buffer----
        scanf(" %c", &replay_choice); 
        // ----🧹 The C Broom: Loop until we hit the end of the line to clear extra text----
        while ((getchar()) != '\n'); 
        printf("\n");
    }while(replay_choice == 'y' || replay_choice == 'Y');
    
    printf("Thank you for playing the TicTocToe Game! Goodbye👋.\n\n");
}
