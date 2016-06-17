#include <iostream>
#include <ctime>
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
        if (i%10 == 0) cerr << "Checking row " << i << " to " << i + 9 << endl;
        for (int j = 0; j < m_board.getCols(); ++j) {
            m_pDict->reset();
            if (m_pDict->isEmpty()) {
                cerr << "Finished all words have been found!" << endl;
                return;
            }
            findRecursive(i, j);
        }
    }
}

ostream &PatronSolver::printSolution(ostream &out) const {
    out << m_foundWords.size() << " found words:" << endl;

    for (const string &s : m_foundWords) out << s << endl;
    return out;
}

void PatronSolver::findRecursive(int row, int col) {
    char c = m_board[row][col];

    pair<bool, bool> p = m_pDict->stepForwards(c);
    if (!p.first) return;

    // Word found
    if (p.second) {
        m_foundWords.insert(m_pDict->popWord());
    }

    for (int i = 0; i < POSITIONS; ++i) {
        int r2 = row + R[i];
        int c2 = col + C[i];

        if (validPos(r2, c2)) findRecursive(r2, c2);
    }
    m_pDict->stepBackwards();
}

bool PatronSolver::validPos(int row, int col) {
    return row >= 0 && col >= 0 &&
           row < m_board.getRows() && col < m_board.getCols();
}

