#include "solver.h"

int puzzle[9][9] = {{1, 7, 4, 0, 9, 0, 6, 0, 0},
                    {0, 0, 0, 0, 3, 8, 1, 5, 7},
                    {5, 3, 0, 7, 0, 1, 0, 0, 4},
                    {0, 0, 7, 3, 4, 9, 8, 0, 0},
                    {8, 4, 0, 5, 0, 0, 3, 6, 0},
                    {3, 0, 5, 0, 0, 6, 4, 7, 0},
                    {2, 8, 6, 9, 0, 0, 0, 0, 1},
                    {0, 0, 0, 6, 2, 7, 0, 3, 8},
                    {0, 5, 3, 0, 8, 0, 0, 9, 6}};

int main(void)
{
    int **board = get_map();

    if (!board)
        return _EXIT_FAILURE;
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