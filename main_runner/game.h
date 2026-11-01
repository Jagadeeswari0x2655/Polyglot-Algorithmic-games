#ifndef GAME_H
#define GAME_H

/**
 * @brief Launches the Padlock Code Vault Game engine from the Padlock-game sub-repo.
 * Exposes the main gameplay evaluation loops, randomized sequence generation, 
 * and colorized terminal feedback logic.
 */
void start_padlock(void);

/**
 * @brief Placeholder interface hook for the upcoming Sudoku Grid Matrix engine.
 * Will manage matrix validation rules, user grid tracking, and search solvers.
 */
// void start_sudoku(void);

/**
 * @brief Placeholder interface hook for the upcoming Tic-Tac-Toe Game engine.
 * Will manage 2D array state tracks and win-condition validations.
 */
// void start_tictactoe(void);

#endif /* GAME_H */
