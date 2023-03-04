#ifndef GENERATOR_H_
#define GENERATOR_H_

#define BOARD_SIZE 9

struct Generator {
    
};
typedef struct Generator Generator;

int generate_sudoku(int board[BOARD_SIZE][BOARD_SIZE], int num_cells_to_remove);
void print_board(int board[BOARD_SIZE][BOARD_SIZE]);

#endif  /* !GENERATOR_H_ */