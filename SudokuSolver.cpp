#include <iostream>
using namespace std;
#define N 9

void printSudoku(int sudoku[N][N])
{
    for (int row = 0; row < N; row++)
    {
        if (row % 3 == 0 && row != 0)
        {
            cout << "-----------\n";
        }
        for (int column = 0; column < N; column++)
        {
            if (column % 3 == 0 && column != 0)
            {
                cout << "|";
            }
            cout <<  sudoku[row][column];
        }
        cout << "\n";
    }
}

bool isNumberInRow(int sudoku[N][N], int number, int row)
{
    for (int i = 0; i < N; i++)
    {
        if (sudoku[row][i] == number)
        {
            return true;
        }
    }
    return false;
}

bool isNumberInColumn(int sudoku[N][N], int number, int column)
{
    for (int i = 0; i < N; i++)
    {
        if (sudoku[i][column] == number)
        {
            return true;
        }
    }
    return false;
}

bool isNumberInBox(int sudoku[N][N], int number, int row, int column)
{
    int rowOfBox = row - row % 3;
    int columnOfBox = column - column % 3;

    for (int i = rowOfBox; i < rowOfBox + 3; i++)
    {
        for (int j = columnOfBox; j < columnOfBox + 3; j++)
        {
            if (sudoku[i][j] == number)
            {
                return true;
            }
        }
    }
    return false;
}

bool isNumberValid(int sudoku[N][N], int number, int row, int column)
{
    return (!isNumberInColumn(sudoku, number, column) && !isNumberInRow(sudoku, number, row) && !isNumberInBox(sudoku, number, row, column));
}

bool solveSudoku(int sudoku[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int column = 0; column < N; column++)
        {
            if (sudoku[row][column] == 0)
            {
                for (int numberToTry = 1; numberToTry <= N; numberToTry++)
                {
                    if (isNumberValid(sudoku, numberToTry, row, column))
                    {
                        sudoku[row][column] = numberToTry;

                        if (solveSudoku(sudoku))
                        {
                            return true;
                        }
                        else
                        {
                            sudoku[row][column] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
