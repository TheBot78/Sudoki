#include "solver.h"

void free_board(int **board)
{
    for (int i = 0; i < BOARD_SIZE; i++)
        free(board[i]);
    free(board);
}

int main(void)
{
    int **board = get_map();

    if (!board)
        return _EXIT_FAILURE;
    if (solve_sudoku(board))
    {
        print_board(board);
        free_board(board);
        return _EXIT_SUCCESS;
    }
    else
    {
        printf("Unable to solve the Sudoku board.\n");
        free_board(board);
        return _EXIT_FAILURE;
    }
    return _EXIT_SUCCESS;
}