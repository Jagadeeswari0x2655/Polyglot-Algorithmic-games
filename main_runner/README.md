# 🚀 Polyglot Game Matrix Runner

This directory serves as the central control station for the entire multi-repository algorithmic games hub. It contains the primary dashboard controllers for **C, Java, and Python**, allowing users to navigate and launch independent games (like Padlock, Sudoku, and Tic-Tac-Toe) stored across separate sub-repositories.

## 📂 Multi-Language Architecture Layout
The orchestration framework connects your multi-language main runner programs to individual sub-repository game modules using the following structural setup:

```text
Polyglot-Algorithmic-games/         <-- Main Root Hub Repository
│
├── main_runner/                     <-- Central Dashboard Workspace
│   ├── main.c                       <-- Central C Menu Controller
│   ├── Main.java                    <-- Central Java Menu Controller
│   ├── main.py                      <-- Central Python Menu Controller
│   ├── games.h                      <-- Global Handshake Header [Updated Location]
│   └── README.md                    <-- This Operational Manual
│
├── Padlock-game/                    <-- Padlock Game Sub-Repository
│   ├── padlock.c                    
│   ├── Padlock.java                 
│   └── padlock.py                   
│
├── sudoku-subrepo/                  <-- Sudoku Game Sub-Repository [Coming Soon]
└── tictactoe-subrepo/               <-- Tic-Tac-Toe Sub-Repository [Coming Soon]
```

---

## 🛠️ Execution Manual (GitHub Codespaces)

Since these programs call code distributed across distinct sub-folders, you must run them from the **root directory** of your workspace using the specialized commands below. 

Before running any program, make sure your game submodules are fully downloaded and synchronized:
```bash
git submodule update --init --recursive
```

### 1. Running the C Dashboard Matrix
The C compiler must explicitly stitch the split source files together and use an Include flag (`-I`) to trace the header file folder across sub-directories.

* **Compilation Command:**
  ```bash
  gcc main_runner/main.c Padlock-game/padlock.c -I games_hub -o game
  ```
* **Execution Command:**
  ```bash
  ./game
  ```

### 2. Running the Java Dashboard Matrix
Java compiles the central class menu alongside the sub-repository file layouts by tracking their paths relative to the classpath.

* **Compilation Command:**
  ```bash
  javac -d out main_runner/*.java Padlock-game/*.java
  ```
* **Execution Command:**
  ```bash
  java -cp out Main
  ```

### 3. Running the Python Dashboard Matrix
The Python main controller dynamically appends the root directory path to the system path tracking structure, allowing seamless dot-notation module imports across folders.

* **Execution Command:**
  ```bash
  python main_runner/main.py
  ```

---

## 💎 Interview Portfolio Highlights
Building a cross-directory multi-language runner hub directly demonstrates high-level software engineering skills to technical interviewers:
1. **Dependency Orchestration:** Showcases your understanding of Git Submodules and tracking code across decoupled micro-repositories.
2. **Polyglot Fluency:** Proves your capability to manage the same modular structural logic cleanly across low-level procedural code (C), strictly typed object-oriented paradigms (Java), and dynamic scripting engines (Python).
3. **Architecture Scalability:** Adding future game profiles (like Sudoku or Tic-Tac-Toe) requires zero updates to older files—you simply plug the new module paths straight into the existing dashboard menus.
