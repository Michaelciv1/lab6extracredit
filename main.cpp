/*
  CIS 22B

    Lab 6: This lab allows the user to define the size of a square grid and then proceed to fill in values.
    It will then check if the square is a magic square.

  Author: Michael Wallerius

  Date: 3/12/2020
*/

#include <iostream>
#include "LoShuSquare.h"

using namespace std;

int main(int argc, const char * argv[]) {
    int SIZE = 0;
    cout << "Enter the side length of the grid: ";
    cin >> SIZE;

    LoShuSquare magic(SIZE);
    int row, col, value;
    magic.printBoard();

    do
    {
        for (row = 0; row < SIZE; row++)
        {
            cout << "Please enter values between 1 and " << SIZE*SIZE << " with no duplicates for row " << row << " separated by a space: ";
            for (col = 0; col < SIZE; col++)
            {
                cin >> value;
                magic.fill(row, col, value);
            }
            magic.printBoard();
        }
        if (magic.check())
            {
                cout << "Congratulations, this is a magic square!" << endl;
            }
        else
            {
                cout << "This is not a magic square. Try again. " << endl;
            }
    } while (!magic.check());
}

