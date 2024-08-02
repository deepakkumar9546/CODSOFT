#include <iostream>

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;

    void initializeBoard() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = ' ';
            }
        }
    }

    void displayBoard() {
        std::cout << "\n";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << " " << board[i][j] << " ";
                if (j < 2) std::cout << "|";
            }
            std::cout << "\n";
            if (i < 2) std::cout << "---+---+---\n";
        }
        std::cout << "\n";
    }

    bool isBoardFull() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') return false;
            }
        }
        return true;
    }

    bool checkWin() {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
                return true;
            }
        }
        // Check diagonals
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
            return true;
        }
        return false;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

public:
    TicTacToe() : currentPlayer('X') {
        initializeBoard();
    }

    void playGame() {
        bool gameEnded = false;
        while (!gameEnded) {
            displayBoard();
            int row, col;
            std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            std::cin >> row >> col;

            // Check for valid input
            if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
                std::cout << "Invalid move. Try again.\n";
                continue;
            }

            // Update the board with the player's move
            board[row - 1][col - 1] = currentPlayer;

            // Check for a win
            if (checkWin()) {
                displayBoard();
                std::cout << "Player " << currentPlayer << " wins!\n";
                gameEnded = true;
            } else if (isBoardFull()) {
                // Check for a draw
                displayBoard();
                std::cout << "The game is a draw.\n";
                gameEnded = true;
            } else {
                // Switch players if the game is not over
                switchPlayer();
            }
        }
    }
};

int main() {
    char playAgain;
    do {
        TicTacToe game;
        game.playGame();
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
