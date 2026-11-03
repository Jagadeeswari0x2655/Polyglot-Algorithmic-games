package padlock;
import java.util.*;
class global_data{
  //---- code_length:store difficulty level based on code length, total_attempts: store total chance to guess the code based on code_length----
  public static int code_length,total_attempts,your_attempts;
  //----used store secret padlock code----
  public static ArrayList<Integer> padlock_code = new ArrayList<>();
  //----used to store user guessing code----
  public static ArrayList<Integer> user_code = new ArrayList<>();
  // ----TRULY CONSTANT GLOBAL STRING ARRAY (Immutable)----
  public static final List<String> color_highlight = List.of(
      "\033[1;31m",   // 0: Bold Red Text (1 = Bold, 31 = Red)
      "\033[1;34m", // 1: Blue Text (Extended 256-color palette index 208)
      "\033[1;30;42m" // 2: Bold Black Text on Green Background (1 = Bold, 30 = Black Text, 42 = Green BG)
  );
  public static final String RESET ="\033[0m";
}
//----Function as start_padlock function to start game----
public class Padlock{
  
  public Padlock(){
      Scanner scanner = new Scanner(System.in);
      char replayChoice;// ----Variable to store 'y' or 'n' to ask user they want to play again----
      // ----OUTER LOOP: Controls the entire game session----
      do{
        
          // ----Display the clean menu to the user----
          System.out.printf("=================================\n");
          System.out.printf("       🔐PADLOCK GAME MENU\n");
          System.out.printf("=================================\n");
          System.out.printf("Select the game difficulty code length:\n");
          System.out.printf("🟢[3] For a 3-digit code\n");
          System.out.printf("🟡[4] For a 4-digit code\n");
          System.out.printf("🔴[5] For a 5-digit code\n\n");
        
          //----Reset Dynamic ArrayLists (Wipes size to 0)----
            global_data.padlock_code.clear();
            global_data.user_code.clear();
          // ----Define your specified range----
          final int MIN = 3;
          final int MAX = 5;
          int score = 0;
          boolean isValid = false;
          // ----Keep looping until the user gives a valid choice----
          while (!isValid) {
              System.out.printf("Enter your choice (3, 4, or 5): ");
              String input = scanner.nextLine(); // Read full line

              try {
                  int parsedNumber = Integer.parseInt(input); // Try converting to integer
                
                  // ----Check if the number falls within the specified range----
                  if (parsedNumber >= MIN && parsedNumber <= MAX) {
                      global_data.code_length = parsedNumber;
                      isValid = true; // Input is completely valid exits loop
                  } else {
                      System.out.printf("\n[ERROR❌] '%d' is invalid! YOUR CHOICE is (3, 4, or 5). Please try again.\n\n",parsedNumber);
                  }
              } catch (NumberFormatException e) {
                  System.out.println("❌ Invalid Format: Please enter whole numbers only.");
              }
          }
        /*
        //----total attempts to guess the code based on code length difficulty----
        total_attempts=(code_length==3)?8:(code_length==4)?9:10;
        
        //----⭐ CRITICAL FIX: Allocate memory for the code length before filling it!----
        padlock_code = (int *)malloc(code_length * sizeof(int));
        if (padlock_code == NULL) {
            printf("[ERROR❌] Memory allocation failed!\n");
        }
        */
        /*
        // ----create padlock code to guess----
        set_padlock_code();

        //----print game rules----
        print_game_instructions(code_length,total_attempts);
        
        //----call game_function----
        int attempts=0;
        int result;
        result=game_function(attempts);
        
        //----call win_or_loss function----
        win_or_loss(result);
        
        // ----Clean up the memory allocated for this specific round----
        free(padlock_code);
        padlock_code = NULL;
        */
        // ----Ask the user if they want to play again----
        System.out.printf("\nDo you want to play again? (y/n): ");
        
        // ----🧹 The Java Broom: Sweeps the full line out of the way instantly----
        replayChoice= scanner.nextLine().trim().charAt(0);
        System.out.println();
    }while(replayChoice == 'y' || replayChoice == 'Y');
    
    System.out.printf("Thank you for playing the Padlock Game! Goodbye👋.\n\n");
  }
}
