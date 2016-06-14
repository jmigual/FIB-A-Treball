#include "board.h"

Board::Board(int height, int width)
        : m_cols(width),
          m_rows(height) {
    if (width >= 0 && height >= 0) {
        m_data = VVC(height, VC(width));
    }
}

void Board::setValue(char value, int row, int column) {
    m_data[row][column] = value;
}

char Board::getValue(int row, int column) {
    return m_data[row][column];
}

ostream& operator<<(ostream &out, const Board &b) {
    out << b.m_rows << " " << b.m_cols << endl;
    for (const VC &V : b.m_data) {
        for (char c : V) out << c;
        out << endl;
    }
    return out;
}

istream& operator>>(istream &in, Board &b) {
    in >> b.m_rows >> b.m_cols;
    
    b.m_data = VVC(b.m_rows, VC(b.m_cols));
    for (VC &V : b.m_data) for (char &c : V) in >> c;
    return in;
}

