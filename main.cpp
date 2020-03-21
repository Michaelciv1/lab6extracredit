/*
  CIS 22B

    Lab 6: This lab allows the user to define the size of a square grid and then proceed to fill in values.
    It will then check if the square is a magic square.

  Author: Michael Wallerius

  Date: 3/12/2020
*/

#include <iostream>
#include "LoShuSquare.h"
#include <vector>

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
            for (col = 0; col < SIZE; col++){
                cin >> value;
                if (value <= SIZE*SIZE)
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

/* OUTPUT
Enter the side length of the grid: 3
0   0   0
0   0   0
0   0   0
Please enter values between 1 and 9 with no duplicates for row 0 separated by a space: 4 9 2
4   9   2
0   0   0
0   0   0
Please enter values between 1 and 9 with no duplicates for row 1 separated by a space: 7 5 3
4   9   2
7   5   3
0   0   0
Please enter values between 1 and 9 with no duplicates for row 2 separated by a space: 6 1 8
4   9   2
7   5   3
6   1   8
This is not a magic square. Try again.
Please enter values between 1 and 9 with no duplicates for row 0 separated by a space: 4 9 2
4   9   2
7   5   3
6   1   8
Please enter values between 1 and 9 with no duplicates for row 1 separated by a space: 3 5 7
4   9   2
3   5   7
6   1   8
Please enter values between 1 and 9 with no duplicates for row 2 separated by a space: 8 1 6
4   9   2
3   5   7
8   1   6
Congratulations, this is a magic square!

Process returned 0 (0x0)   execution time : 31.834 s
Press any key to continue.

DIFFERENT USER INPUT FOR SIDE:

Enter the side length of the grid: 4
0   0   0   0
0   0   0   0
0   0   0   0
0   0   0   0
Please enter values between 1 and 16 with no duplicates for row 0 separated by a space: 8 11 14 1
8   11  14  1
0   0   0   0
0   0   0   0
0   0   0   0
Please enter values between 1 and 16 with no duplicates for row 1 separated by a space: 13 7 12 2
8   11  14  1
13  7   12  2
0   0   0   0
0   0   0   0
Please enter values between 1 and 16 with no duplicates for row 2 separated by a space: 3 16 6 9
8   11  14  1
13  7   12  2
3   16  6   9
0   0   0   0
Please enter values between 1 and 16 with no duplicates for row 3 separated by a space: 10 15 5 4
8   11  14  1
13  7   12  2
3   16  6   9
10  15  5   4
This is not a magic square. Try again.
Please enter values between 1 and 16 with no duplicates for row 0 separated by a space: 8 11 14 1
8   11  14  1
13  7   12  2
3   16  6   9
10  15  5   4
Please enter values between 1 and 16 with no duplicates for row 1 separated by a space: 13 2 7 12
8   11  14  1
13  2   7   12
3   16  6   9
10  15  5   4
Please enter values between 1 and 16 with no duplicates for row 2 separated by a space: 3 16 9 6
8   11  14  1
13  2   7   12
3   16  9   6
10  15  5   4
Please enter values between 1 and 16 with no duplicates for row 3 separated by a space: 10 5 4 15
8   11  14  1
13  2   7   12
3   16  9   6
10  5   4   15
Congratulations, this is a magic square!

Process returned 0 (0x0)   execution time : 38.979 s
Press any key to continue.
*/
