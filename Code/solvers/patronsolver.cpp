#include "patronsolver.h"

PatronSolver::PatronSolver() {

}

void PatronSolver::setDictionary(shared_ptr<Dictionary> dict) {
    m_pDict = dict;
}

void PatronSolver::setBoard(Board &b) {
    m_board = b;
}

void PatronSolver::solve() {    
    for (int i = 0; i < m_board.getRows(); ++i) {
        for (int j = 0; j < m_board.getCols(); ++j) {
            m_pDict->reset();
            findRecursive(i, j);
        }
    }
}

void PatronSolver::printSolution(ostream &out) {
    out << m_foundWords.size() << " found words:" << endl;
    
    for (const string &s : m_foundWords) out << s << endl;
}

void PatronSolver::findRecursive(int row, int col) {
    char c = m_board.getValue(row, col);
    
    pair<bool,bool> p = m_pDict->stepForwards(c);
    if (! p.first) return;
    
    m_find.push_back(c);
    
    // Word found
    if (p.second) insertWord();
    
    for (int i = 0; i < POSITIONS; ++i) {
        int r2 = row + R[i];
        int c2 = col + C[i];
        
        if (validPos(r2, c2)) findRecursive(r2, c2);
    }
    m_find.pop_back();
    m_pDict->stepBackwards();
}

void PatronSolver::insertWord() {
    string s;
    s.reserve(m_find.size());
    
    for (char c : m_find) s.push_back(c);
    m_foundWords.insert(s);
}

bool PatronSolver::validPos(int row, int col) {
    return row >= 0 && col >= 0 && 
            row < m_board.getRows() && col < m_board.getCols();
}

