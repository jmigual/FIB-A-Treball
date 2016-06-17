#include "wordsolver.h"
#include <iostream>

WordSolver::WordSolver()
        : m_comparisons(0),
          m_failedComparisons(0),
          m_checkedCells(0) {

}
void WordSolver::setDictionary(shared_ptr<Dictionary>) {

}
void WordSolver::setWords(vector<string> &dict) {
    m_Dict = dict;
}

void WordSolver::setBoard(Board &b) {
    m_board = b;
}

void WordSolver::solve() {
    m_time = clock();
    for (const string &s : m_Dict) {
        cout << "Checking word " << s << endl;
        for (int i = 0; i < m_board.getRows(); ++i) {
            for (int j = 0; j < m_board.getCols(); ++j) {
                if (findDFS(s, 0, i, j)) m_foundWords.insert(s);
            }
        }
    }
    m_time = clock() - m_time;
}

ostream &WordSolver::printSolution(std::ostream &out) const {
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

bool WordSolver::findDFS(const string &s, uint spos, int row, int col) {
    if (spos == s.size()) return true;
    
    ++m_comparisons;
    if (s[spos] == m_board.getValue(row, col)) {

        for (int i = 0; i < POSITIONS; ++i) {
            int r2 = row + R[i];
            int c2 = col + C[i];
            ++m_checkedCells;
            if (validPos(r2, c2) and findDFS(s, spos + 1, r2, c2)) return true;
        }
    }
    ++m_failedComparisons;
    return false;
}
/*
   bool WordSolver::findHash(string s, uint value, int row, int col){
    if (spos == s.size()) return true;

    if (s[spos] == m_board.getValue(row,col)) {

        for (int i = 0; i < POSITIONS; ++i) {
            int r2 = row + R[i];
            int c2 = col + C[i];

            if (validPos(r2, c2) and findDFS(s, spos+1, r2, c2)) return true;
        }
    }

    return false;
   }

   int stringToInt(string s){
    return s[0] + 10* stringToInt(s.pop_back());
   }
 */
bool WordSolver::validPos(int row, int col) {
    return row >= 0 && col >= 0 &&
           row < m_board.getRows() && col < m_board.getCols();
}
