#include <iostream>
#include "patronsolver.h"

PatronSolver::PatronSolver()
        : m_comparisons(0),
          m_failedComparisons(0),
          m_checkedCells(0) {

}

void PatronSolver::setDictionary(shared_ptr<Dictionary> dict) {
    m_pDict = dict;
}

void PatronSolver::setBoard(Board &b) {
    m_board = b;
}

void PatronSolver::solve() {
    m_time = clock();
    for (int i = 0; i < m_board.getRows(); ++i) {
        if (i % 10 == 0) cerr << "Checking row " << i << " to " << i + 9 << endl;
        for (int j = 0; j < m_board.getCols(); ++j) {
            m_pDict->reset();
            if (m_pDict->isEmpty()) {
                cerr << "Finished all words have been found!" << endl;
                return;
            }
            findRecursive(i, j);
        }
    }
    m_time = clock() - m_time;
}

ostream &PatronSolver::printSolution(ostream &out) const {
    out << "Patron Solver" << endl;
    out << "Found Words       : " << m_foundWords.size() << endl;
    out << "Comparisons       : " << m_comparisons << endl;
    out << "Failed comparisons: " << m_failedComparisons << endl;
    out << "Checked cells     : " << m_checkedCells << endl << endl;
    out << "Execution ticks   : " << m_time << endl;
    out << "Execution time    : " << m_time /((float) CLOCKS_PER_SEC) << endl;

    out << "This words have been found:" << endl;
    for (const string &s : m_foundWords) out << s << endl;
    return out;
}

void PatronSolver::findRecursive(int row, int col) {
    char c = m_board[row][col];

    ++m_comparisons;
    pair<bool, bool> p = m_pDict->stepForwards(c);
    if (!p.first) {
        ++m_failedComparisons;
        return;
    }

    // Word found
    if (p.second) {
        m_foundWords.insert(m_pDict->popWord());
    }

    for (int i = 0; i < POSITIONS; ++i) {
        int r2 = row + R[i];
        int c2 = col + C[i];

        ++m_checkedCells;
        if (validPos(r2, c2)) findRecursive(r2, c2);
    }
    m_pDict->stepBackwards();
}

bool PatronSolver::validPos(int row, int col) {
    return row >= 0 && col >= 0 &&
           row < m_board.getRows() && col < m_board.getCols();
}

