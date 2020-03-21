#ifndef LOSHUSQUARE_H
#define LOSHUSQUARE_H


class LoShuSquare
{
    public:
        LoShuSquare(int x);
        ~LoShuSquare();
        bool check();
        void fill(int row, int col, int value);
        void printBoard();
        bool isUnique(int value);
    protected:

    private:
        int** square = new int*[SIZE];
        int SIZE;
        bool checkRow();
        bool checkCol();
        bool checkDiag();
};

#endif // LOSHUSQUARE_H
