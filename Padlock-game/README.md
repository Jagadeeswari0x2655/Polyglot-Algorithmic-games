# 🔐 Padlock Puzzle Game

A terminal-based logical number-cracking puzzle game that challenges players to deduce a hidden secret combination using real-time, color-coded feedback. Built entirely with clean state logic to demonstrate strong foundational programming principles and algorithmic deductive reasoning in C.

## 🎮 Game Overview

The objective of the game is simple: crack the combination to open the padlock vault. The game engine generates a completely unique secret code with non-repeating digits at launch. Players must analyze sequential positional feedback to narrow down possibilities and find the exact sequence.

### 🌟 Key Features

* **Dynamic Matrix:** Choose your challenge level with support for **3-digit (Easy)**, **4-digit (Medium)**, and **5-digit (Hard)** secret codes.
* **Strict Input Validation Engine:** Instantly screens player guesses to filter out duplicate digits, alphabetical letters, or incorrect lengths before processing to prevent runtime crashes.
* **ANSI Terminal Color Mapping:** Provides immediate visual styling hints using classic terminal escaping codes to direct your logical deductions.
* **Recursive Match Engine:** Employs explicit heap memory tracking (`malloc` and `free`) inside continuous recursive function steps to protect performance and avoid leaks.

---

## 🎨 Feedback Rules

Every time you submit a guess, each individual digit receives a specific color code based on its accuracy:

| Status | Visual Feedback Indicator | Meaning |
| :--- | :--- | :--- |
| 🟩 **GREEN** | **Green Background** (`\033[1;30;42m`) | **Correct Place:** The number matches perfectly in the correct index position. |
| 🟦 **BLUE** | **Bold Blue Text** (`\033[1;34m`) | **Wrong Place:** The number exists in the lock code but is in the wrong spot. |
| 🟥 **RED** | **Bold Red Text** (`\033[1;31m`) | **Incorrect Number:** The number does not exist inside the vault combination. |

---

## ⚙️ Difficulty & Win Condition Matrix

The number of allowed attempts and dynamic player ratings adapt dynamically based on the complexity of the hidden code combination:

* **3-Digit Mode (Easy):**
  * 🌟 **Excellent (5/5 Stars):** Solved in 6 attempts or fewer.
  * 👍 **Good (3/5 Stars):** Solved on the 7th or 8th attempt.
  * ❌ **Loss:** Reaching more than 8 attempts.

* **4-Digit Mode (Medium):**
  * 🌟 **Excellent (5/5 Stars):** Solved in 7 attempts or fewer.
  * 👍 **Good (3/5 Stars):** Solved on the 8th or 9th attempt.
  * ❌ **Loss:** Reaching more than 9 attempts.

* **5-Digit Mode (Hard):**
  * 🌟 **Excellent (5/5 Stars):** Solved in 8 attempts or fewer.
  * 👍 **Good (3/5 Stars):** Solved on the 9th or 10th attempt.
  * ❌ **Loss:** Reaching more than 10 attempts.

---

## 🛠️ Internal Structure & Architecture

The system architecture decouples configuration, random state distribution, and structural matching across isolated function modules:

### 💾 Global Memory Allocation & State Fields
* **`int *padlock_code` & `int *user_guess_code`**: Dynamic array pointers tracking the hidden combination and active user input tracking layout frames respectively.
* **`int code_length`**: Stores the dynamic difficulty state bounds selected at configuration launch.
* **`int total_attempts` & `int yourattempts`**: Controls life-cycle structural runtime constraints and records active performance tracking states.

### ⚙️ Component Blueprint Subsections
* **`main()`**: Coordinates application entry setup initialization. Manages the system context difficulty menus, calls configuration modules, seeds systemic execution timelines exactly once using `srand(time(NULL))`, and establishes clean memory cleanups (`free()`) at round completions.
* **`set_padlock_code()`**: Leverages mathematical mod calculations (`rand() % 10`) coupled with explicit frequency vectors (`used_digit[10]`) to ensure the generated lock code values never duplicate.
* **`set_user_guess_code()`**: Intercepts terminal hardware inputs safely. Protects memory against character spam crashes using standard input clearing buffers (`while(getchar() != '\n')`), filters duplicate entries, and manages localized heap setup constraints (`malloc`).
* **`game_function(int attempts)`**: The foundational recursive tracking routine. Evaluates array indices side-by-side to distribute ANSI formatting codes, handles positional matching values, safely cleans active iteration guess heap blocks, and feeds structured tracking variables back into functional cascades cleanly without system leakage vectors.
* **`win_or_loss(int result)`**: Evaluates performance metric flags passing down from completion structures, formats multi-row dashboard summaries, and computes contextual star ratings based on your total operational speed thresholds.

---

## 🔧 Installation & Execution

### Prerequisites
You need a working standard C compiler configuration environment installed on your machine (such as `gcc`, `clang`, or `MinGW`).

### Execution Pipeline

1. **Save the Code**  
   Save the application source code into your project directory workspace as `padlock_game.c`.

2. **Compile the Program**  
   Open your command line interface terminal inside the directory containing the file and execute:
   ```bash
   gcc padlock.c -o padlock
   ```

3. **Run the Application**  
   * **Linux / macOS Platforms:**
     ```bash
     ./padlock
     ```
   * **Windows Environments:**
     ```cmd
     padlock.exe
     ```

