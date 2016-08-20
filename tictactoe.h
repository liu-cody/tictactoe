//
//  tictactoe.h
//  projecteuler
//
//  Created by Cody Liu on 8/12/16.
//  Copyright © 2016 Cody Liu. All rights reserved.
//

#ifndef tictactoe_h
#define tictactoe_h
#include <stdio.h>
#include <iostream>

class Game {
private:
    char Player1;
    char Player2;
    char board[9];
    
    bool checkrows();
    bool checkcols();
    bool checkdiags();
    
public:
    //default constructor
    Game();
    
    //input constructor
    Game(char input);
    
    char getPlayer1();
    char getPlayer2();
    void printboard();
    void move(char turn);
    bool threeinarow();
};


Game initializegame(char input);
void playgame(Game &current);


#endif /* tictactoe_h */
