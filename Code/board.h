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
    
    Board(int m_height = -1, int m_width = -1);
    
    void setValue(char value, int row, int column);
    
    char getValue(int row, int column);
    
    inline int getHeight() { return m_height; }
    
    inline int getWidth() { return m_width; }
    
    friend ostream& operator<< (ostream &out, const Board &b);
    
    friend istream& operator>> (istream &in, Board &b);
    
    VVC m_data;
    
    int m_width;
    int m_height;
};

#endif // BOARD_H
