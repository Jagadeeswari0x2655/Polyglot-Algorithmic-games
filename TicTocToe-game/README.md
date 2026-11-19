# ❌⭕ Tic-Tac-Toe Polyglot Strategy Game

A multi-language tactical grid game that challenges players to outsmart an algorithmic opponent or compete locally in a classic 3x3 arena. Part of the **[polyglot-algorithm-game](../)** repository, implemented across **C, Java, Python, and JavaScript** to compare procedural memory management, object-oriented encapsulation, and scripting paradigms using identical core game-tree logic.

## 🎮 Game Overview

The objective of the game is simple: align three of your marks (**X** or **O**) horizontally, vertically, or diagonally before your opponent does. Each language module renders a live 3x3 coordinate grid, validates every move in real time, and evaluates terminal board states after every turn.

### 🌟 Key Features

* **4-Language Polyglot Architecture:** Side-by-side implementations in **C**, **Java**, **Python**, and **JavaScript** demonstrating identical state-machine and game-tree algorithms across different paradigms.
* **Multiple Game Modes:** Choose between **Player vs. Player (Local)** for head-to-head matches or **Player vs. AI** to test your strategy against an automated engine.
* **Strict Input Validation Engine:** Instantly screens player coordinates to filter out occupied cells, out-of-bounds numbers, or invalid characters before processing to prevent runtime crashes.
* **ANSI Terminal Color Mapping:** Provides immediate visual clarity in CLI versions using terminal color codes to distinguish **Player X**, **Player O**, and winning grid lines.
* **Algorithmic Decision Engine:** Employs recursive game-tree evaluation (**Minimax**) alongside O(1) board-state checks to compute optimal counter-moves.

---

## 🎨 Visual Board & Symbol Indicators

Every turn updates the 3x3 matrix with color-coded markers to clearly separate available coordinates from claimed squares:

| Symbol | Visual Feedback Indicator | Meaning |
| :--- | :--- | :--- |
| ❌ **X** | **Bold Cyan / Red Text** (`\033[1;36m`) | **Player 1:** Marks cells claimed by the first player. |
| ⭕ **O** | **Bold Yellow / Green Text** (`\033[1;33m`) | **Player 2 / AI:** Marks cells claimed by the second player or CPU engine. |
| 🔢 **1–9** | **Dim White Text** (`\033[0;37m`) | **Available Cell:** Open grid position ready for player input. |

---

## ⚙️ Game Modes & Win Condition Matrix

The engine evaluates 8 distinct winning vectors (3 rows, 3 columns, and 2 diagonals) after each turn and adapts gameplay based on your selected mode:

* **Player vs. AI — Hard (Unbeatable):**
  * 🧠 **Algorithm:** Full recursive **Minimax** search exploring all remaining board states.
  * 🏆 **Outcome:** Forces a **Draw** against optimal play and capitalizes immediately on any human mistake.

* **Player vs. AI — Easy / Medium (Casual):**
  * 🎲 **Algorithm:** Randomized valid move selection or depth-limited heuristic evaluation.
  * 🏆 **Outcome:** Ideal for quick practice rounds and testing opening traps.

* **Player vs. Player (2-Player Local):**
  * 🤝 **Mode:** Alternating turn-based input on a shared screen/terminal.
  * 🏆 **Outcome:** First player to complete a 3-cell line wins; filling all 9 cells without a line       triggers a **Draw**.

---

## 🛠️ Internal Structure & Polyglot Architecture

Each implementation decouples board state representation, input sanitization, and win/AI evaluation into clean, modular routines adapted to the target language's strengths:

### 📂 Sub-Repository Layout
```text
TicTocToe-game/
├── c/                  # Procedural implementation with explicit array/pointer state & buffer sanitization
├── java/               # Object-oriented implementation encapsulating Board, Player, and GameEngine classes
├── python/             # Clean, Pythonic implementation utilizing list comprehensions and recursive Minimax
├── javascript/         # Node.js CLI / Browser implementation leveraging event-driven or async readline I/O
└── README.md           # Sub-repository documentation
```
