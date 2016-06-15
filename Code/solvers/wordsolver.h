#ifndef WORDSOLVER_H
#define WORDSOLVER_H
#include "solvers/solver.h"
#include "dictionaries/dictionary.h"

#include <set>
#include <vector>
#include <memory>
#include "board.h"

class WordSolver : public Solver
{
public:

    WordSolver();

    void setDictionary(shared_ptr<Dictionary>);

    void setWords(vector<string>&);

    void setBoard(Board &);

    void solve();

    ostream &printSolution(std::ostream &out) const;

private:
    bool findDFS(const string &s, uint spos, int row, int col);

    bool validPos(int row, int col);

    vector<string> m_Dict;

    Board m_board;

    set<string> m_foundWords;
};

#endif // WORDSOLVER_H
