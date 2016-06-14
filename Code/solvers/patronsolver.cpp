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
    
    
    for (int i = 0; i < m_board.getHeight(); ++i) {
        for (int j = 0; j < m_board.getWidth(); ++j) {
            m_pDict->reset();
            findRecursive(i, j);
        }
    }
}

void PatronSolver::printSolution(ostream &out) {
    out << m_foundWords.size() << " found words:" << endl;
    
    for (const string &s : m_foundWords) out << s << endl;
}

void PatronSolver::findRecursive(int row, int column) {
    char c = m_board.getValue(row, column);
    
    pair<bool,bool> p = m_pDict->stepForwards(c);
    
    
}

void PatronSolver::insertWord() {
    string s;
    s.reserve(m_find.size());
    
    for (char c : m_find) s.push_back(c);
    m_foundWords.push_back(s);
}

