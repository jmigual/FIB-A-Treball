#include "wordsolver.h"

WordSolver::WordSolver() {

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
    for (string s : m_Dict) {
        for (int i = 0; i < m_board.getRows(); ++i) {
            for (int j = 0; j < m_board.getCols(); ++j) {
                if (findDFS(s, 0, i, j)) m_foundWords.insert(s);
            }
        }
    }
}

ostream &WordSolver::printSolution(std::ostream &out) const {
    out << m_foundWords.size() << " found words:" << endl;

    for (const string &s : m_foundWords) out << s << endl;
    return out;
}

bool WordSolver::findDFS(const string &s, uint spos, int row, int col) {
    if (spos == s.size()) return true;

    if (s[spos] == m_board.getValue(row, col)) {

        for (int i = 0; i < POSITIONS; ++i) {
            int r2 = row + R[i];
            int c2 = col + C[i];

            if (validPos(r2, c2) and findDFS(s, spos + 1, r2, c2)) return true;
        }
    }

    return false;
}


bool WordSolver::validPos(int row, int col) {
    return row >= 0 && col >= 0 &&
           row < m_board.getRows() && col < m_board.getCols();
}
