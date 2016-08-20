//
//  tictactoe.cpp
//  projecteuler
//
//  Created by Cody Liu on 8/20/16.
//  Copyright © 2016 Cody Liu. All rights reserved.
//

#include "tictactoe.h"

bool Game::checkrows() {
    for (int row = 0; row < 3; ++row) {
        int currentsquare = 3 * row;
        if (board[currentsquare] == board[currentsquare + 1] &&
            board[currentsquare] == board[currentsquare + 2] &&
            (board[currentsquare] == 'o' ||
             board[currentsquare] == 'x')) {
                return true;
            }
    }
    return false;
}

bool Game::checkcols() {
    for (int cols = 0; cols < 3; ++cols) {
        if (board[cols] == board[cols + 3] &&
            board[cols] == board[cols + 6] &&
            (board[cols] == 'x'
             || board[cols] == 'o')) {
                return true;
            }
    }
    return false;
}

bool Game::checkdiags() {
    return ((board[0] == board[4] &&
             board[0] == board[8]) ||
            (board[2] == board[4] &&
             board[2] == board[6])) &&
    (board[4] == 'x' || board[4] == 'o');
}

Game::Game() : Player1('x'), Player2('o') {
    
}

Game::Game(char input) {
    if (std::tolower(input) == 'x') {
        Player1 = 'x';
        Player2 = 'o';
    }
    else {
        Player1 = 'o';
        Player2 = 'x';
    }
    
    for (int i = 0; i < 9; ++i) {
        board[i] = ' ';
    }
}

char Game::getPlayer1() {
    return Player1;
}

char Game::getPlayer2() {
    return Player2;
}

void Game::printboard() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (j < 2) {
                std::cout << i*3 + j << " "
                << board[i * 3 + j] << "|";
            }
            else {
                std::cout << i*3 + j
                << " " << board[i * 3 + j];
            }
        }
        if (i < 2) {
            std::cout << "\n" << "-----------\n";
        }
        else {
            std::cout << "\n";
        }
    }
}

void Game::move(char turn) {
    std::cout << "Enter the number of the square you would like to mark.\n";
    int input;
    
    while (std::cin >> input) {
        if (input <= 8 && input >= 0) {
            if (board[input] != ' ') {
                std::cout << "Invalid input. Please try again\n";
            }
            else {
                board[input] = turn;
                break;
            }
        }
        else {
            std::cout << "Invalid input. Please try again\n";
        }
    }
}

bool Game::threeinarow() {
    return checkcols() || checkdiags() || checkrows();
}

Game initializegame(char input) {
    std::cout << "Press 'X' if you would like to play as 'X' or 'O' if you would like to play as 'O'.\n";
    char XorO;
    while (std::cin >> XorO) {
        std::tolower(XorO);
        if (XorO != 'x' && XorO != 'o') {
            std::cout << "Invalid input. Please try again\n";
        }
        else {
            break;
        }
    }
    return Game(XorO);
}

void playgame(Game &current) {
    std::cout << "Beginning game\n";
    int movesmade = 0;
    while (movesmade < 9) {
        current.printboard();
        
        if (movesmade % 2 == 0) {
            std::cout << "Player 1: ";
            current.move(current.getPlayer1());
            if (current.threeinarow()) {
                std::cout << "Player 1 wins!\n";
                break;
            }
        }
        else {
            std::cout << "Player 2: ";
            current.move(current.getPlayer2());
            if (current.threeinarow()) {
                std::cout << "Player 2 wins!\n";
                break;
            }
        }
        ++movesmade;
    }
    
    current.printboard();
    if (movesmade == 9) {
        std::cout << "Draw.\n";
    }
    std::cout << "Play again: press '1' to play against a friend, '2' to play against the computer, or 'q' to quit.\n";
    
}