#include "generator.h"

int main(void)
{
    int board[BOARD_SIZE][BOARD_SIZE];
    generate_sudoku(board, 40);
    print_board(board);
    return 0;
}