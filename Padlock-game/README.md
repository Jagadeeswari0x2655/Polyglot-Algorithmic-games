# Padlock Puzzle Game

A terminal-based logical number-cracking puzzle game that challenges players to deduce a hidden secret combination using real-time, color-coded feedback. Built entirely with clean state logic to demonstrate strong foundational programming principles and algorithmic deductive reasoning.

## 🎮 Game Overview

The objective of the game is simple: crack the combination to open the padlock. The game engine generates a completely unique secret code with non-repeating digits at launch. Players must analyze sequential positional feedback to narrow down possibilities and find the exact sequence.

### 🌟 Key Features

* **Dynamic Matrix:** Choose your challenge level with support for **3-digit (Easy)**, **4-digit (Medium)**, and **5-digit (Hard)** secret codes.
* **Strict Input Validation Engine:** Instantly screens player guesses to filter out duplicate digits, alphabetical letters, or incorrect lengths before processing.
* **ANSI Terminal Color Mapping:** Provides immediate visual styling hints using classic terminal colors to direct your logic.
* 
## 🎨 Feedback Rules

Every time you submit a guess, each individual digit receives a specific color code based on its accuracy:
| Status | Feedback Rule |
| :--- | :--- |
| 🟢 **GREEN** | **Correct Place:** The number is perfectly placed. |
| 🟠 **ORANGE** | **Wrong Place:** The number exists but is in the wrong spot. |
| 🔴 **RED** | **Incorrect Number:** The number does not exist in the code. |

## ⚙️ Difficulty & Win Condition Matrix
The number of allowed attempts and dynamic player ratings adapt based on the complexity of the hidden code combination:

*   **3-Digit Mode:**
    *   🌟 **Excellent (5/5):** Solved in 6 attempts.
    *   👍 **Good (3/5):** Solved in 7th or 8th attempts.
    *   ❌ **Loss:** more than 8 attempts.
*   **4-Digit Mode:**
    *   🌟 **Excellent (5/5):** Solved in 7 attempts.
    *   👍 **Good (3/5):** Solved in 8th or 9th attempts.
    *   ❌ **Loss:** more than 9 attempts.
*   **5-Digit Mode:**
    *   🌟 **Excellent (5/5):** Solved in 8 attempts.
    *   👍 **Good (3/5):** Solved in 9th or 10th attempts.
    *   ❌ **Loss:** more than 10 attempts.
