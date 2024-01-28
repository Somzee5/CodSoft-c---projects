#include <iostream>

// Function prototypes
void initializeBoard(char board[3][3]);
void displayBoard(const char board[3][3]);
char currentPlayerMove(char board[3][3], char currentPlayer);
char checkWin(const char board[3][3], char currentPlayer);
char switchPlayer(char currentPlayer);
char playAgain();

int main() {
    char currentPlayer = 'X';
    char board[3][3];

    do {
        initializeBoard(board);
        displayBoard(board);

        int row, col;
        char result;

        do {
            std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            result = currentPlayerMove(board, currentPlayer);

            if (result == 'I') {
                std::cout << "Invalid move. Try again.\n";
            }

        } while (result == 'I');

        if (result == currentPlayer) {
            displayBoard(board);
            std::cout << "Player " << currentPlayer << " wins! Congratulations!\n";
        } else if (result == 'D') {
            displayBoard(board);
            std::cout << "It's a draw!\n";
        } else {
            currentPlayer = switchPlayer(currentPlayer);
        }

    } while (playAgain() == 'Y');

    std::cout << "Thanks for playing Tic-Tac-Toe!\n";

    return 0;
}

void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const char board[3][3]) {
    std::cout << "  1 2 3\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}

char currentPlayerMove(char board[3][3], char currentPlayer) {
    int row, col;
    std::cin >> row >> col;

    if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') {
        board[row - 1][col - 1] = currentPlayer;
        return checkWin(board, currentPlayer);
    } else {
        return 'I'; // Invalid move
    }
}

char checkWin(const char board[3][3], char currentPlayer) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return currentPlayer;
        }
    }

    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return currentPlayer;
    }

    // Check if the board is full (no empty spaces)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return 'C'; // Continue playing
            }
        }
    }

    return 'D'; // It's a draw
}

char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}

char playAgain() {
    char choice;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> choice;
    return choice;
}
