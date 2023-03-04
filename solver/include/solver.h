#ifndef SOLVER_H_
#define SOLVER_H_

#define BOARD_SIZE 9
#define _EXIT_SUCCESS 0
#define _EXIT_FAILURE 84

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int solve_sudoku(int **board);
void print_board(int **board);
int **get_map(void);

#endif /* !SOLVER_H_ */