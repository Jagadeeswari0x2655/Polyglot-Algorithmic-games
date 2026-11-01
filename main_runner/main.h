#include <stdio.h>
#include <stdlib.h>
#include "game.h" // ----In the same folder: directs access to game hooks----

int main(void) {
    int choice;
    int running = 1;

    while (running) {
        printf("\n==================================================\n");
        printf("       🚀 POLYGLOT ALGORITHMIC GAME HUBS 🚀       \n");
        printf("==================================================\n");
        printf(" 1. Play Padlock Code vault Game 🔐\n");
        printf(" 2. Play Sudoku Grid Solver Matrix 🧩 [Coming Soon]\n");
        printf(" 3. Play Tic-Tac-Toe Game Engine ❌⭕ [Coming Soon]\n");
        printf(" 4. Close & Exit Application Matrix 🛑\n");
        printf("==================================================\n");
        printf("Select an option (1-4): ");

        // ---- Verify user input is a valid integer ----
        if (scanf("%d", &choice) != 1) {
            printf("\n❌ Invalid choice selection! Please input a valid selection number.\n");
            
            // ---- Clear the stuck character from the input buffer to prevent infinite loops ----
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
                // ----Jumps across directories directly into your Padlock-game logic!----
                start_padlock();
                break;
            case 2:
                printf("\n==================================================\n");
                printf("🧩 [Sudoku Coming Soon!] Feature slot is fully ready.\n");
                printf("==================================================\n");
                break;
            case 3:
                printf("\n==================================================\n");
                printf("❌⭕ [Tic-Tac-Toe Coming Soon!] Feature slot is fully ready.\n");
                printf("==================================================\n");
                break;
            case 4:
                printf("\nThank you for exploring the algorithmic game matrix! Closing console dashboard...\n\n");
                running = 0;
                break;
            default:
                printf("\n⚠️ Choice out of range! Please choose a number between 1 and 4.\n");
        }
    }

    return 0;
}
