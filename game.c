#include <stdio.h>

#define ROWS 3
#define COLS 3

char board[ROWS][COLS] = { {' ', ' ', ' '},
                           {' ', ' ', ' '},
                           {' ', ' ', ' '} };

void printBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWinner() {
    // check rows
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
    }

    // check columns
    for (int i = 0; i < COLS; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }

    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return 1;
    }

    return 0;
}

int main() {
    int row, col;
    char player = 'X';
    int winner = 0;

    while (winner == 0) {
        printf("Player %c's turn.\n", player);
        printf("Enter row and column (0-2): ");
        scanf("%d %d", &row, &col);

        if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == ' ') {
            board[row][col] = player;
            printBoard();
            winner = checkWinner();
            if (winner == 1) {
                printf("Player %c wins!\n", player);
            }
            player = (player == 'X') ? 'O' : 'X';
        } else {
            printf("Invalid move.\n");
        }
    }

    return 0;
}
