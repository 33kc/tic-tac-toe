#include <iostream>
#include <vector>
#include <limits> //numeric_limits

using namespace std;


void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}


bool checkWin(const vector<vector<char>>& board, char player) {
    
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true; // Check rows
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true; // Check columns
    }
    
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true; // Main diagonal
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true; // Anti-diagonal
    return false;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, '.')); 
    char currentPlayer = 'X'; 

    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "Player X goes first." << endl;

    // Game loop
    while (true) {
        printBoard(board); 
        int row, col;
        
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        
        while (!(cin >> row) || row < 0 || row >= 3) {
            cout << "Invalid row. Enter a number between 0 and 2: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        cout << "Enter the column (0-2): ";
        while (!(cin >> col) || col < 0 || col >= 3) {
            cout << "Invalid column. Enter a number between 0 and 2: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        
        if (board[row][col] == '.') {
            board[row][col] = currentPlayer;

            
            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                break; 
            }

            
            bool boardFull = true;
            for (const auto& row : board) {
                for (char cell : row) {
                    if (cell == '.') {
                        boardFull = false;
                        break;
                    }
                }
            }
            if (boardFull) {
                printBoard(board);
                cout << "It's a tie!" << endl;
                break; 
            }

            
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move. That cell is already taken. Try again." << endl;
        }
    }

    return 0;
}
