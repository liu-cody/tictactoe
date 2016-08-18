//
//  chapter8.cpp
//  projecteuler
//
//  Created by Cody Liu on 8/12/16.
//  Copyright © 2016 Cody Liu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "tictactoe.h"

int main(int argc, char* argv[]) {
    
    //menu
    std::cout << "Welcome to tic tac toe! Press '1' to play against a friend, '2' to play against the computer, or 'q' to exit!\n";
    char input;
    while (std::cin >> input) {
        if (input == '1' || input == '2') {
            Game newgame = initializegame(input);
            playgame(newgame); 
            
        }
        else if (input == 'q') {
            std::cout << "Thank you for playing!\n";
            exit(0);
        }
        else {
            std::cout << "Invalid input";
        }
        
    }


    
}


