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
    
}

void PatronSolver::printSolution(ostream &out) {
    out << m_foundWords.size() << " found words:" << endl;
    
    for (const string &s : m_foundWords) out << s << endl;
}

