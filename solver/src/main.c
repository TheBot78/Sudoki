#include "solver.h"

int main(void)
{
    int **board = get_map();

    if (solve_sudoku(board))
    {
        print_board(board);
        return _EXIT_SUCCESS;
    }
    else
    {
        printf("Unable to solve the Sudoku board.\n");
        return _EXIT_FAILURE;
    }
    return _EXIT_SUCCESS;
}