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
    
}

