import Padlock.*;
import java.util.*;
public class Main{
     public static void main(String[] args) {
          Scanner scanner = new Scanner(System.in);
          int choice;
          boolean running = true;

          while (running) {
              System.out.printf("\n==================================================\n");
              System.out.printf("       🚀 POLYGLOT ALGORITHMIC GAME HUBS 🚀       \n");
              System.out.printf("==================================================\n");
              System.out.printf(" 1. Play Padlock Code vault Game 🔐\n");
              System.out.printf(" 2. Play Sudoku Grid Solver Matrix 🧩 [Coming Soon]\n");
              System.out.printf(" 3. Play Tic-Tac-Toe Game Engine ❌⭕ [Coming Soon]\n");
              System.out.printf(" 4. Close & Exit Application Matrix 🛑\n");
              System.out.printf("==================================================\n");
              System.out.printf("Select an option (1-4): ");

              // ---- Verify user input is a valid integer ----
              if (!scanner.hasNextInt()) {
                  System.out.printf("\n❌ Invalid choice selection! Please input a valid selection number.\n");
    
                  // ---- Clear the stuck character from the input buffer to prevent infinite loops ----
                  continue;
              }
              choice = scanner.nextInt();


              switch (choice) {
                    case 1:
                        // ----Jumps across directories directly into your Padlock-game logic!----
                        new Padlock();
                        break;
                    case 2:
                        System.out.printf("\n==================================================\n");
                        System.out.printf("🧩 [Sudoku Coming Soon!] Feature slot is fully ready.\n");
                        System.out.printf("==================================================\n");
                        break;
                    case 3:
                        System.out.printf("\n==================================================\n");
                        System.out.printf("❌⭕ [Tic-Tac-Toe Coming Soon!] Feature slot is fully ready.\n");
                        System.out.printf("==================================================\n");
                        break;
                    case 4:
                        System.out.printf("\nThank you for exploring the algorithmic game matrix! Closing console dashboard...\n\n");
                        running = false;
                        break;
                    default:
                        System.out.printf("\n⚠️ Choice out of range! Please choose a number between 1 and 4.\n");
                }
            }
      }
}
