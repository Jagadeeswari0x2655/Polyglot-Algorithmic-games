package Padlock;
import java.util.*;

//----all global used data in one class----
class global_data{
  
  //---- code_length:store difficulty level based on code length, total_attempts: store total chance to guess the code based on code_length----
  public static int code_length,total_attempts,yourattempts;
  
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
  
  Scanner scanner = new Scanner(System.in);
  
  public Padlock(){
      
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
        
          //----total attempts to guess the code based on code length difficulty----
          global_data.total_attempts=(global_data.code_length==3)?8:(global_data.code_length==4)?9:10;
          print_game_instructions();
        
          // ----create padlock code to guess----
          set_padlock_code();

          //----print game rules----
          print_game_instructions();
        
          //----call game_function----
          int attempts=0;
          int result;
          result=game_function(attempts);
        
          //----call win_or_loss function----
          win_or_loss(result);
          /*
          // ----Clean up the memory allocated for this specific round----
          global_data.padlock_code = new ArrayList<>();
          */
          // ----Ask the user if they want to play again----
          System.out.printf("\nDo you want to play again? (y/n): ");
        
          // ----🧹 The Java Broom: Sweeps the full line out of the way instantly----
          replayChoice = scanner.next().trim().charAt(0);
          scanner.nextLine(); // ----Clears out extra input and the Enter key----
          System.out.println();
      }while(replayChoice == 'y' || replayChoice == 'Y');
    
      System.out.printf("Thank you for playing the Padlock Game! Goodbye👋.\n\n");
    }

  
    //----print game instructions and rules based on the difficult level----
    private void print_game_instructions() {
    
        System.out.printf("\n==================================================\n");
        System.out.printf("              🔐 THE PADLOCK CODE GAME            \n");
        System.out.printf("==================================================\n");
        System.out.printf("A secret passcode has been locked inside the vault.\n");
        System.out.printf("Your mission is to crack it before you run out of turns!\n\n");
    
        System.out.printf("📜 THE RULES:\n");
        System.out.printf("1. The code is exactly %d digits long.\n", global_data.code_length);
        System.out.printf("2. Every single digit in the code is UNIQUE (0-9).\n");
        System.out.printf("3. No duplicate numbers are allowed in your guess.\n\n");

        // ----Clear color definitions added inside your game instructions----
        System.out.printf("🎨 THE COLOR FEEDBACK SYSTEM:\n");
        System.out.printf(" %s X %s -> Green background: number is correct place in lock code\n",global_data.color_highlight.get(2),global_data.RESET);
        System.out.printf(" %s X %s -> Red text: number is not in lockcode\n",global_data.color_highlight.get(0),global_data.RESET);
        System.out.printf(" %s X %s -> blue text: number is in lock code but not in correct place\n\n",global_data.color_highlight.get(1),global_data.RESET);
    
        System.out.printf("🎯 YOUR DIFFICULTY:\n");
        System.out.printf("* Code Length: %d numbers\n", global_data.code_length);
        System.out.printf("* Maximum Attempts Allowed: %d\n", global_data.total_attempts);
        System.out.printf("==================================================\n");
        System.out.printf("Good luck, Enter your first guess...\n\n");
  }

  
  //----print win or loss the game using this function----
  private void win_or_loss(int result){
      if(result==1){
        System.out.printf("\n");
        System.out.printf("==============================================\n");
        System.out.printf("🎉 CONGRATULATIONS! PADLOCK UNLOCKED 🎉\n");
        System.out.printf("      🏆🏆🏆YOU WIN THE GAME🏆🏆🏆     \n");
        System.out.printf("==============================================\n");
        System.out.printf("You 🔓 🔑 unlocked the padlock in %d attempts 🔐.\n\n", global_data.yourattempts);
        
        // ----Star Ranking Logic----
        System.out.printf("YOUR SCORE: ");
        if(global_data.yourattempts<=global_data.total_attempts-2){
            // ----Excellent: 5 Stars----
            System.out.printf("🌟🌟🌟🌟🌟 Excellent!\n\n");
        }else{
            //----Good: 3 Stars----
            System.out.printf("🌟🌟🌟 Good!\n\n");
        }
        System.out.printf("=============================================\n");
      }else{
        System.out.printf("=============================================\n");
        System.out.printf("     ❌❌GAME OVER! YOU LOSS THE GAME❌❌\n");
        System.out.printf("=============================================\n");
        System.out.printf("You reached the maximum limit of %d attempts.\n", global_data.total_attempts);
        System.out.printf("The padlock remains locked. 🔒\n");
        System.out.printf("=============================================\n\n");
        
        // ----Prints the secret answer to the user----
        System.out.printf("The correct padlock 🔒 combination was: ");
        for(int i=0;i<global_data.code_length;i++){
            System.out.printf("%d ",global_data.padlock_code.get(i));
        }
        System.out.printf("🔑\n\n");
        System.out.printf("=============================================\n\n");
      }
  }

  
  // ----Function to generate a padlock code with UNIQUE digits----
  private void set_padlock_code() {
    
    // ----Track used digits: index represents the digit (0-9). false = unused, true = used----
    boolean[] used_digit = new boolean[10]; 
    Random rand = new Random();
    int random_digit;

    for (int i = 0; i < global_data.code_length; i++) {
        // ----this do while is used to create unique digits in padlock_code array----
        do {
             random_digit = rand.nextInt(0, 10);  // ----Generate a digit between 0 and 9----
        } while (used_digit[random_digit]); // ----If already used, loop again----

        // ----Assign the unique digit to our padlock array----
        global_data.padlock_code.add(random_digit);
        
        // ----Mark this used digit as used so it won't be picked again in this round----
        used_digit[random_digit] = true; 
    }
  }

  
  // ----Function to generate a user guess code with UNIQUE digits----
  private void set_user_guess_code(){
      String input;  
      boolean isValid;

      // ----Clear previous guesses if this method is called multiple times per round----
      global_data.user_code.clear();

      do {
          isValid = true;
          boolean[] used_digit = new boolean[10];
        
          System.out.printf("Enter a %d-digit code with unique numbers (e.g., 123): ", global_data.code_length);
        
          // ----Reads the ENTIRE line, including any accidental spaces----
          input = scanner.nextLine().trim();

          // ----Optional: If you WANT to allow spaces like "12 45" and treat it as "1245", uncomment the line below:
          // input = input.replaceAll("\\s+", "");
        

          // ----1. Check if the input matches the required code length----
          if (input.length() != global_data.code_length) {
            System.out.printf("❌ Invalid length! Please enter exactly %d digits.\n", global_data.code_length);
            isValid = false;
            continue;
          }

          // ----2. Validate every character in the string----
          for (int i = 0; i < input.length(); i++) {
              char ch = input.charAt(i);

              // ----Check if the character is a number (0-9)----
              if (!Character.isDigit(ch)) {
                  System.out.println("❌ Invalid input! Only numeric digits (0-9) are allowed.");
                  isValid = false;
                  break;
              }

              // ----Convert char to its integer value----
              int digit = Character.getNumericValue(ch);

              // ----Check for duplicate digits----
              if (used_digit[digit]) {
                  System.out.printf("❌ Duplicate digit '%d' found! All digits must be unique.\n", digit);
                  isValid = false;
                  break;
              }

              used_digit[digit] = true;
          }

        } while (!isValid);

        // ----3. Store the validated digits into your list----
        for (int i = 0; i < input.length(); i++) {
          global_data.user_code.add(Character.getNumericValue(input.charAt(i)));
        }
    }

  
    //----create a game function to compare user code and padlock code, print hints and run the function untill complete all atmepts----
    private int game_function(int attempts){
    
          int[] hints = new int[5];//----array to store hints about digits----
          int check_win=0;//----check win through this variable----
    
          //----call the set_user_guess_code function to take user guess code----
          set_user_guess_code();
    
          //----check digits of user_guess_code in padlock_code----
          for(int i=0;i<global_data.code_length;i++){
                if(global_data.user_code.get(i)==global_data.padlock_code.get(i)){
                    hints[i]=2;
                    check_win++;
                }else{
                    for(int j=0;j<global_data.code_length;j++){
                        if(global_data.padlock_code.get(j)==global_data.user_code.get(i)){
                            hints[i]=1;
                        }
                    }
                }
           }
          attempts++;
          //----enter the user code with hints using colours based----
          for(int i=0;i<global_data.code_length;i++){
                System.out.printf(" %s%d%s",global_data.color_highlight.get(hints[i]),global_data.user_code.get(i),global_data.RESET);
          }
          System.out.printf("\n ⚠️ you have %d attempts left!\n\n",global_data.total_attempts-attempts);
    
          // Discard the old list and point the variable to a brand-new empty list
          global_data.user_code = new ArrayList<>();
    
          if(check_win==global_data.code_length){
              global_data.yourattempts=attempts;
              return 1;//----win the game return 1----
          }
   
          if(attempts>=global_data.total_attempts){
              return 0;//----loss the game return 0----
          }
    
          return game_function(attempts);
    }
}
