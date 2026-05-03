#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <string>

class TicTacToeMaster {
private:
    char board[9];
    char player = 'X';
    char ai = 'O';
    int difficulty = 2;        // 1 Easy, 2 Normal, 3 Hard
    int winStreak = 0;
    int highStreak = 0;

    void printBoard();
    bool isFull();
    char checkWinner();
    int minimax(bool isMaximizing);
    int bestAIMove();
    void saveHighStreak();
    int loadHighStreak();

public:
    TicTacToeMaster();
    void start();
    void play();
};

#endif