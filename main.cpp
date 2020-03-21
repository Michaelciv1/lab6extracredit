//
//  main.cpp
//  This is the tester for the LoShuSquare class
//
//  Created by Hellen Pacheco on 6/9/19.
//  Copyright © 2018 Hellen Pacheco. All rights reserved.
//

#include <iostream>
#include "LoShuSquare.h"

using namespace std;

int main(int argc, const char * argv[]) {
    int SIZE = 0;
    int choice;
    cout << "Enter the side length of the grid: ";
    cin >> SIZE;

    LoShuSquare magic(SIZE);
    bool isMagic = false;
    int row, col, value;
    magic.printBoard();

    do
    {
        for (row = 0; row < SIZE; row++)
        {
            cout << "Please enter values for row " << row << " separated by space: ";
            for (col = 0; col < SIZE; col++)
            {
                cin >> value;
                magic.fill(row, col, value);
            }
            magic.printBoard();
        }
        if (magic.check())
            {
                isMagic = true;
                cout << "Congratulations, this is a magic square!" << endl;
            }
            else
            {
                cout << "This is not a magic square. Try again. " << endl;
            }
    } while (!magic.check());
    return 0;
}

