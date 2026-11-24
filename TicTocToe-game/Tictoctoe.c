#include <stdio.h>

//----delcare the gird and used globally in a function----
char grid={
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

//----function to change the value in grid----
void change_grid(int choice,char symbol){
    switch(choice){
        case 1: grid[0][0] = symbol; break;
        case 2: grid[0][1] = symbol; break;
        case 3: grid[0][2] = symbol; break;
        case 4: grid[1][0] = symbol; break;
        case 5: grid[1][1] = symbol; break;
        case 6: grid[1][2] = symbol; break;
        case 7: grid[2][0] = symbol; break;
        case 8: grid[2][1] = symbol; break;
        case 9: grid[2][2] = symbol; break;
    }
}

void print_grid(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[i][j]=='X'){
                printf("%s%c%s","\033[1;36m",grid[i][j],"\033[0m");
            }else if(grid[i][j]=='O'){
                printf("%s%c%s","\033[1;33m,grid[i][j],\033[0m");
            }else{
                printf("%s%c%s","\033[0;37m,grid[i][j],\033[0m");
            }
            if (j < 2) printf("|"); // ----Vertical divider between columns----
        }
        printf("\n"); // ----Move to the next row----
        if (i < 2) printf("---+---+---\n"); // ----Horizontal divider between rows----
    }
}

void printInstructions(int mode, int userTurn, char p1Mark, char p2Mark) {
    printf("\n+-----------------------------------------+\n");
    printf("|           📜 HOW TO PLAY                |\n");
    printf("+-----------------------------------------+\n");

    // 1. Dynamic Matchup & Symbol Info
    if (mode == 1) {
        printf("• MODE: Player vs. Player (Local)\n");
        printf("• MARKS: Player 1 is [%c] | Player 2 is [%c]\n", p1Mark, p2Mark);
    } else {
        const char *difficulty = (mode == 2) ? "Easy 🌱" : 
                                 (mode == 3) ? "Medium ⚡" : "Hard 🧠";
        printf("• MODE: Player vs. AI (%s)\n", difficulty);
         if (userTurn == 1) {
            printf("• PLAYER 1 (Moves 1st): You [%c]\n", p1Mark);
            printf("• PLAYER 2 (Moves 2nd): AI  [%c]\n", p2Mark);
        } else {
            printf("• PLAYER 1 (Moves 1st): AI  [%c]\n", p1Mark);
            printf("• PLAYER 2 (Moves 2nd): You [%c]\n", p2Mark);
        }
    }

    // 2. Core Rules & Input Guide
    printf("• GOAL: Get 3 of your marks in a row\n");
    printf("  (horizontal, vertical, or diagonal).\n");
    printf("• CONTROLS: Enter a number (1-9) to place\n");
    printf("  your mark on an empty square:\n\n");

    // 3. Numbered Reference Grid
    printf("               1 | 2 | 3 \n");
    printf("              ---+---+---\n");
    printf("               4 | 5 | 6 \n");
    printf("              ---+---+---\n");
    printf("               7 | 8 | 9 \n\n");

    // 4. Mode-Specific Tip
    if (mode == 2) {
        printf("• TIP: Easy AI makes random moves.\n");
    } else if (mode == 3) {
        printf("• TIP: Medium AI will block your wins!\n");
    } else if (mode == 4) {
        printf("• TIP: Hard AI plays optimally. Good luck!\n");
    }

    printf("+-----------------------------------------+\n\n");
}

void start_tictoctoe(void)
{
    char replay_choice; // ----Variable to store 'y' or 'n' to ask user they want to play again----
    int mode;//----Variable to store mode of the game----
    int userTurn = 1; //----Default: Player 1 is human----
    char userMark, aiMark;

    char p1Mark, p2Mark;//----Variable to store mark for player1 and player2----
    
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
        
        //----Setup Players & Marks----
        if (mode == 1) {
                do {
                    printf("Player 1, choose your mark (X or O): ");
                    scanf(" %c", &p1Mark);
                    while (getchar() != '\n'); // ----Clear extra input buffer----
                    p1Mark = toupper(p1Mark);
        
                    if (p1Mark != 'X' && p1Mark != 'O') {
                        printf("Invalid input! Please enter X or O.\n");
                     }
                } while (p1Mark != 'X' && p1Mark != 'O');

                p2Mark = (p1Mark == 'X') ? 'O' : 'X';

        } else {
            //----set the turn----
            while (1) {
                printf("Do you want to be Player 1 (moves 1st) or Player 2 (moves 2nd)? (1/2): ");
                if (scanf("%d", &userTurn) == 1 && (userTurn == 1 || userTurn == 2)) {
                    while (getchar() != '\n'); // ----Clear extra input buffer----
                    break;
                }
                printf("Invalid input! Please enter 1 or 2.\n");
                while (getchar() != '\n'); // ----Clear invalid input from buffer----
            }
            //---- set the usermark----
            do {
                printf("Choose your mark (X or O): ");
                scanf(" %c", &userMark);
                while (getchar() != '\n'); // ----Clear extra input buffer----
                userMark = toupper(userMark);
        
                if (userMark != 'X' && userMark != 'O') {
                    printf("Invalid input! Please enter X or O.\n");
                }
            } while (userMark != 'X' && userMark != 'O');

            aiMark = (userMark == 'X') ? 'O' : 'X';

            // ----Assign marks to Player 1 and Player 2 slots based on user's turn choice----
            if (userTurn == 1) {
                p1Mark = userMark;
                p2Mark = aiMark;
            } else {
                p1Mark = aiMark;
                p2Mark = userMark;
            }
        }

        //----print instructions----
        printInstructions(mode, userTurn, p1Mark, p2Mark);

      
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
