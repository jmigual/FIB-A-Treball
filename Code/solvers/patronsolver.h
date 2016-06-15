#ifndef PATRONSOLVER_H
#define PATRONSOLVER_H
#include <memory>
#include <vector>
#include <list>
#include <unordered_set>

#include "dictionaries/dictionary.h"
#include "solvers/solver.h"
#include "board.h"

class PatronSolver : public Solver
{
public:

    PatronSolver();

    void setDictionary(shared_ptr<Dictionary> dict);

    void setWords(vector<string> &) {
    }

    void setBoard(Board &b);

    void solve();

    std::ostream &printSolution(std::ostream &out) const;

private:

    void findRecursive(int row, int col);

    bool validPos(int row, int col);

    shared_ptr<Dictionary> m_pDict;

    Board m_board;

    unordered_set<string> m_foundWords;
};

#endif // PATRONSOLVER_H
