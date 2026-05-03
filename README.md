# Tic-Tac-Toe 

A text-based Tic-Tac-Toe game with AI opponent for ENGG1340 / COMP2113 Course Project.
Video:https://drive.google.com/file/d/1PFxMAjAtCfgb6P4-e2nEzORQxh0rhCLt/view?usp=sharing

## Team Members
- So Yuet (3036060874）

## Game Description
Classic 3x3 Tic-Tac-Toe with 3 difficulty levels. Hard mode uses Minimax algorithm.
Rules for Tic-Tac-Toe
  The game is played on a grid that's 3 squares by 3 squares.
  You are X , your friend (or the computer in this case) is O . Players take turns putting their marks in empty squares.
  The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner.
  When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.

## Features 
- **Random events**: Easy AI uses random move (rand())
- **Data structures**: `char board[9]` + `std::vector<int>` for move history
- **Dynamic memory management**: `std::vector` automatically expands for move history
- **File I/O**: `highscore.txt` for saving/loading highest win streak
- **Multiple files**: main.cpp, tictactoe.h, tictactoe.cpp, utils.h, utils.cpp
- **Multiple difficulty levels**: Easy / Normal / Hard

## Compilation & Execution
-To compile and run the game, follow these steps:Open the terminal and go to the project folder (the folder that contains the Makefile).
-Compile the program by typing:

  make clean
  make

-After successful compilation, run the game by typing:

  ./tictactoe

-The game will start and show the main menu immediately.Note:  The program is compiled using standard g++ with C++11.  
No extra libraries are needed.  



