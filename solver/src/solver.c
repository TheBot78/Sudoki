#include "solver.h"

void print_board(int **board)
{
    printf("|------------------|\n");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("|");
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf(" %d", board[i][j]);
        }
        printf("|\n");
    }
    printf("|------------------|\n");
}

int used_in_row(int **board, int row, int num)
{
    for (int col = 0; col < BOARD_SIZE; col++)
    {
        if (board[row][col] == num)
        {
            return true;
        }
    }
    return false;
}

int used_in_col(int **board, int col, int num)
{
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        if (board[row][col] == num)
        {
            return true;
        }
    }
    return false;
}

int used_in_subgrid(int **board, int start_row, int start_col, int num)
{
    for (int row = 0; row < SUBGRID_SIZE; row++)
    {
        for (int col = 0; col < SUBGRID_SIZE; col++)
        {
            if (board[row + start_row][col + start_col] == num)
            {
                return true;
            }
        }
    }
    return false;
}

int is_valid_placement(int **board, int row, int col, int num)
{
    return !used_in_row(board, row, num) &&
           !used_in_col(board, col, num) &&
           !used_in_subgrid(board, row - row % SUBGRID_SIZE, col - col % SUBGRID_SIZE, num);
}

int find_unassigned_cell(int **board, int *row, int *col)
{
    for (*row = 0; *row < BOARD_SIZE; (*row)++)
    {
        for (*col = 0; *col < BOARD_SIZE; (*col)++)
        {
            if (board[*row][*col] == 0)
            {
                return true;
            }
        }
    }
    return false;
}

int solve_sudoku(int **board)
{
    int row, col;
    if (!find_unassigned_cell(board, &row, &col))
    {
        return true;
    }
    for (int num = 1; num <= 9; num++)
    {
        if (is_valid_placement(board, row, col, num))
        {
            board[row][col] = num;
            if (solve_sudoku(board))
            {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return EXIT_SUCCESS;
}