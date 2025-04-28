#include <iostream>
#include <vector>
using namespace std;

// Function to check if it's safe to place a queen
bool isSafe(vector<vector<int>> &board, int row, int col, int n)
{
    // Check vertically up
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false;
    }

    // Check left diagonal
    int i = row, j = col;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
            return false;
        i--;
        j--;
    }

    // Check right diagonal
    i = row;
    j = col;
    while (i >= 0 && j < n)
    {
        if (board[i][j] == 1)
            return false;
        i--;
        j++;
    }

    return true; // Safe to place queen
}

// Recursive function to solve N-Queens
bool nQueen(vector<vector<int>> &board, int row, int n)
{
    if (row >= n)
        return true; // All queens placed successfully

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 1; // Place queen

            if (nQueen(board, row + 1, n))
                return true; // Move to next row

            board[row][col] = 0; // Backtrack
        }
    }
    return false; // No valid position in this row
}

int main()
{
    int n;
    cout << "Enter number of Queens: ";
    cin >> n;

    // Create n x n board filled with 0
    vector<vector<int>> board(n, vector<int>(n, 0));

    if (nQueen(board, 0, n))
    {
        // Print the board
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Solution does not exist!\n";
    }

    return 0;
}
