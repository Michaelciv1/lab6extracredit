#ifndef LOSHUSQUARE_H
#define LOSHUSQUARE_H


class LoShuSquare
{
    private:
        int SIZE;
        int** square = new int*[SIZE];
        bool checkRow();
        bool checkCol();
        bool checkDiag();

    public:
        LoShuSquare(int x);
        ~LoShuSquare();
        bool check();
        bool checkDuplicate();
        void fill(int row, int col, int value);
        void printBoard();
};

#endif // LOSHUSQUARE_H
