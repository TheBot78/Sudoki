#include "generator.h"

void print_board(int board[BOARD_SIZE][BOARD_SIZE])
{
    printf("|------------------|\n");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("|");
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == 0) {
                printf("  ");
            } else {
                printf(" %d", board[i][j]);
            }
        }
        printf("|\n");
    }
    printf("|------------------|\n");
}

int used_in_row(int board[BOARD_SIZE][BOARD_SIZE], int row, int num)
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

int used_in_col(int board[BOARD_SIZE][BOARD_SIZE], int col, int num)
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

int used_in_subgrid(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int num)
{
    int subgrid_row = row - row % SUBGRID_SIZE;
    int subgrid_col = col - col % SUBGRID_SIZE;
    for (int i = 0; i < SUBGRID_SIZE; i++)
    {
        for (int j = 0; j < SUBGRID_SIZE; j++)
        {
            if (board[subgrid_row + i][subgrid_col + j] == num)
            {
                return true;
            }
        }
    }
    return false;
}

int is_valid_placement(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int num)
{
    // Check whether a number placement is valid according to the rules of Sudoku
    return !used_in_row(board, row, num) && !used_in_col(board, col, num) && !used_in_subgrid(board, row, col, num);
}

int find_empty_cell(int board[BOARD_SIZE][BOARD_SIZE], int *row, int *col)
{
    // Find the next empty cell in the board
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

int solve_sudoku(int board[BOARD_SIZE][BOARD_SIZE])
{
    int row, col;

    // Find the next empty cell in the board
    if (!find_empty_cell(board, &row, &col))
    {
        // All cells are filled, board is solved
        return true;
    }

    // Try placing a number in the empty cell
    for (int num = 1; num <= BOARD_SIZE; num++)
    {
        if (is_valid_placement(board, row, col, num))
        {
            board[row][col] = num;

            // Recursively solve the remaining cells
            if (solve_sudoku(board))
            {
                return true;
            }

            // Backtrack and try a different number
            board
                [row][col] = 0;
        }
    }
    return false;
}

void generate_sudoku(int board[BOARD_SIZE][BOARD_SIZE], int num_cells_to_remove)
{
    // Start with an empty board
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }

    // Fill in the first row with random numbers
    srand(time(NULL));
    for (int col = 0; col < BOARD_SIZE; col++)
    {
        int num;
        do
        {
            num = rand() % BOARD_SIZE + 1;
        } while (!is_valid_placement(board, 0, col, num));
        board[0][col] = num;
    }

    // Use the backtracking algorithm to fill in the rest of the cells
    solve_sudoku(board);

    // Remove a specified number of cells to create an incomplete puzzle
    for (int i = 0; i < num_cells_to_remove; i++)
    {
        int row, col;
        do
        {
            row = rand() % BOARD_SIZE;
            col = rand() % BOARD_SIZE;
        } while (board[row][col] == 0);
        board[row][col] = 0;
    }
}