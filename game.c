#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 3
#define COLUMNS 3
char player = 'X';
int winner = 1; 
bool gameEnd = false; 

// Creating a 3x3 grid for keeping the information

char board[ROWS][COLUMNS];

void initialzeBoard(){
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLUMNS; j++){
            board[i][j] = ' ';
        }
    }
}

void clearScreen(){
     printf("\033[H\033[J"); 
}

// Function for displaying the board

void displayBoard() {
    printf("\n");
    printf("  1   2   3\n");
    printf("1 %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("  ---------\n");
    printf("2 %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("  ---------\n");
    printf("3 %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

// Displaying which player's turn it is

void displayPlayer(){
    printf("It's player %c's turn\n", player);
    printf("Please make a choice\n");
}

// Chaching whose turn it is

void changeTurn(){
    if (player == 'X') {
        player = 'O';
    } else {
        player = 'X';
    }
}



// Update the board

bool updateBoard(){
    int rowPos;
    int colPos; 

    // Let current player choose row
    printf("Pick row position\n");
    scanf("%i", &rowPos);

    // Let current player choose column
    printf("Pick column position\n");
    scanf("%i",  &colPos);

    // Update board if valid position is chosen 
    if (rowPos >= 1 && rowPos <= ROWS && colPos >= 1 && colPos <= COLUMNS && board[rowPos - 1][colPos - 1] == ' ') {
        board[rowPos - 1][colPos - 1] = player;
        return true;
    } else {
        printf("Invalid move! Try again.\n");
        return false;
    }
}

bool isGameOver(){
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            winner = (player == 'X') ? 1 : 2;
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < COLUMNS; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            winner = (player == 'X') ? 1 : 2;
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        winner = (player == 'X') ? 1 : 2;
        return true;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        winner = (player == 'X') ? 1 : 2;
        return true;
    }

    // Check for draw
    bool draw = true;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] == ' ') {
                draw = false;
                break;
            }
        }
        if (!draw) break;
    }
    if (draw) {
        winner = 0;
        return true;
    }

    return false;
}

// End the game

void endGame() {
    if (winner == 0) {
        printf("It's a draw!\n");
    } else {
        printf("Player %c won!\n", (winner == 1) ? 'X' : 'O');
    }
}

// Main function

int main(){
   initialzeBoard();
   displayBoard();

   // Main game loop
   while (!gameEnd) {
        displayPlayer();
        while (!updateBoard()) {
            // Keep asking until a valid move is made
        }
        clearScreen();
        displayBoard();
        gameEnd = isGameOver();
        if (!gameEnd) {
            changeTurn();
        } else {
            endGame();
        }
   }

}