# Tic-Tac-Toe Master Battle

A text-based Tic-Tac-Toe game with AI opponent for ENGG1340 / COMP2113 Course Project.

## Team Members
- So Yuet (3036060874）

## Game Description
Classic 3x3 Tic-Tac-Toe with 3 difficulty levels. Hard mode uses Minimax algorithm.

## Features 
- **Random events**: Easy AI uses random move (rand())
- **Data structures**: `char board[9]` + `std::vector<int>` for move history
- **Dynamic memory management**: `std::vector` automatically expands for move history
- **File I/O**: `highscore.txt` for saving/loading highest win streak
- **Multiple files**: main.cpp, tictactoe.h, tictactoe.cpp, utils.h, utils.cpp
- **Multiple difficulty levels**: Easy / Normal / Hard

## Compilation & Execution
```bash
make
./tictactoe
