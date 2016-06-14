#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <ostream>
#include <istream>
using namespace std;

#include "typedefs.h"

class Board
{
public:
    
    Board(int m_rows = -1, int m_cols = -1);
    
    void setValue(char value, int row, int column);
    
    char getValue(int row, int column);
    
    inline int getRows() { return m_rows; }
    
    inline int getCols() { return m_cols; }
    
    friend ostream& operator<< (ostream &out, const Board &b);
    
    friend istream& operator>> (istream &in, Board &b);
    
    VVC m_data;
    
    int m_cols;
    int m_rows;
};

#endif // BOARD_H
