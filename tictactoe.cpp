#include "tictactoe.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

TicTacToeMaster::TicTacToeMaster() {
    for (int i = 0; i < 9; i++) board[i] = '1' + i;
}

void TicTacToeMaster::printBoard() {
    cout << "\n";
    for (int i = 0; i < 9; i++) {
        cout << " " << board[i] << " ";
        if (i % 3 == 2) cout << "\n";
        if (i % 3 != 2) cout << "|";
    }
    cout << "\n";
}

bool TicTacToeMaster::isFull() {
    for (int i = 0; i < 9; i++)
        if (board[i] >= '1' && board[i] <= '9') return false;
    return true;
}

char TicTacToeMaster::checkWinner() {
    int wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    for (auto& w : wins) {
        if (board[w[0]] == board[w[1]] && board[w[1]] == board[w[2]])
            return board[w[0]];
    }
    return ' ';
}

int TicTacToeMaster::minimax(bool isMaximizing) {
    char winner = checkWinner();
    if (winner == ai) return 10;
    if (winner == player) return -10;
    if (isFull()) return 0;

    if (isMaximizing) {
        int best = -1000;
        for (int i = 0; i < 9; i++) {
            if (board[i] >= '1' && board[i] <= '9') {
                char temp = board[i];
                board[i] = ai;
                best = max(best, minimax(false));
                board[i] = temp;
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < 9; i++) {
            if (board[i] >= '1' && board[i] <= '9') {
                char temp = board[i];
                board[i] = player;
                best = min(best, minimax(true));
                board[i] = temp;
            }
        }
        return best;
    }
}

int TicTacToeMaster::bestAIMove() {
    int bestVal = -1000;
    int bestMove = -1;
    for (int i = 0; i < 9; i++) {
        if (board[i] >= '1' && board[i] <= '9') {
            char temp = board[i];
            board[i] = ai;
            int moveVal = minimax(false);
            board[i] = temp;
            if (moveVal > bestVal) {
                bestVal = moveVal;
                bestMove = i;
            }
        }
    }
    return bestMove;
}

void TicTacToeMaster::saveHighStreak() {
    ofstream out("highscore.txt");
    if (out) out << highStreak;
}

int TicTacToeMaster::loadHighStreak() {
    ifstream in("highscore.txt");
    int s = 0;
    if (in) in >> s;
    return s;
}

void TicTacToeMaster::start() {
    srand(time(0));
    highStreak = loadHighStreak();
    int choice;
    do {
        cout << "\n=== TIC-TAC-TOE MASTER BATTLE ===\n";
        cout << "High Streak: " << highStreak << "\n";
        cout << "1. Play Game\n2. Difficulty (1.Easy 2.Normal 3.Hard)\n3. Quit\n> ";
        cin >> choice;

        if (choice == 1) play();
        if (choice == 2) {
            cout << "Choose Difficulty (1-3) > ";
            cin >> difficulty;
        }
    } while (choice != 3);
}

void TicTacToeMaster::play() {
    for (int i = 0; i < 9; i++) board[i] = '1' + i;
    char winner = ' ';
    bool playerTurn = true;
    int moveCount = 0;

    while (winner == ' ' && !isFull()) {
        printBoard();

        if (playerTurn) {
            int pos;
            cout << "Your turn (1-9): ";
            cin >> pos;
            pos--;
            if (pos >= 0 && pos < 9 && board[pos] >= '1' && board[pos] <= '9') {
                board[pos] = player;
                playerTurn = false;
                moveCount++;
            } else {
                cout << "Invalid move!\n";
            }
        } else {
            cout << "AI is thinking...\n";
            int move = -1;
            if (difficulty == 1) {
                do { move = rand() % 9; } while (board[move] < '1' || board[move] > '9');
            } else {
                move = bestAIMove();
            }
            board[move] = ai;
            playerTurn = true;
        }
        winner = checkWinner();
    }

    printBoard();
    if (winner == player) {
        cout << "You Win!\n";
        winStreak++;
        if (winStreak > highStreak) {
            highStreak = winStreak;
            saveHighStreak();
            cout << "New High Streak Record!\n";
        }
    } else if (winner == ai) {
        cout << "AI Wins!\n";
        winStreak = 0;
    } else {
        cout << "It's a Draw!\n";
        winStreak = 0;
    }
    cout << "Current Win Streak: " << winStreak << "\n";
}