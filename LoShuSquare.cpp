#include "LoShuSquare.h"
#include <iostream>
#include <iomanip>

using namespace std;

LoShuSquare::LoShuSquare(int x){
    SIZE = x;
    for(int i = 0; i < SIZE; i++)
        square[i] = new int[SIZE];  // allocates elements for each row

    for (int i=0; i < SIZE; i++)
        for (int j=0; j < SIZE; j++)
        square[i][j] = 0;
}

LoShuSquare::~LoShuSquare()
{
    for(int i = 0; i < SIZE; i++){
        delete [] square[i];   // deletes each row
    }
    delete [] square; // deletes the array of pointers
}

void LoShuSquare::printBoard(){
    int cnt = 0;
    for (int i=0; i < SIZE; i++)
        for (int j=0; j < SIZE; j++){
        cout << setw(2) << left << square[i][j] << " ";
        cnt += 1;
        if (cnt % SIZE == 0)
            cout << endl;
    }
}

void LoShuSquare::fill(int row, int col, int value){
    square[row][col] = value;
}

bool LoShuSquare::isUnique(int value){
    for (int i=0; i < SIZE; i++)
        for (int j=0; j<SIZE; j++)
            if (value == square[i][j]){
                cout << "Not unique digit, please try again: ";
                return false;
            }
    return true;
}

bool LoShuSquare::checkRow(){
    int sum = 0;
    int rowSum = 0;

    for (int i=0; i < SIZE; i++)
        rowSum += square[0][i];

    for (int i=0; i < SIZE; i++)
        for (int j=0; j<SIZE; j++)
        sum += square[i][j];

    if (sum == rowSum*SIZE)
        return true;
    else
        return false;
}

bool LoShuSquare::checkCol(){
    int sum = 0;
    int rowSum = 0;

    for (int i=0; i < SIZE; i++)
        rowSum += square[i][0];

    for (int i=0; i < SIZE; i++)
        for (int j=0; j<SIZE; j++)
        sum += square[j][i];

    if (sum == rowSum*SIZE)
        return true;
    else
        return false;
}

bool LoShuSquare::checkDiag(){
    int leftDiag = 0;
    int rightDiag = 0;

    for (int i=0; i < SIZE; i++)
        leftDiag += square[i][i];

    for (int i=SIZE-1, j=0; i >= 0 && j <= SIZE; i--, j++)
        rightDiag += square[i][j];

    if (leftDiag == rightDiag)
        return true;
    else
        return false;
}

bool LoShuSquare::check(){
    if (checkCol() && checkRow() && checkDiag())
        return true;
    else
        return false;
}

