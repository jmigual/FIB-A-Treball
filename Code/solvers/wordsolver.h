#ifndef WORDSOLVER_H
#define WORDSOLVER_H
#include "solvers/solver.h"
#include "dictionaries/dictionary.h"

#include <ctime>
#include <unordered_set>
#include <vector>
#include <memory>
#include "board.h"

class WordSolver : public Solver
{
public:

    WordSolver();

    void setDictionary(shared_ptr<Dictionary>);

    void setWords(vector<string> &);

    void setBoard(Board &);

    void solve();

    ostream &printSolution(std::ostream &out) const;

private:
    bool findDFS(const string &s, uint spos, int row, int col);

    bool validPos(int row, int col);

    vector<string> m_Dict;

    Board m_board;

    unordered_set<string> m_foundWords;
    
    uint m_comparisons;
    uint m_failedComparisons;
    uint m_checkedCells;
    
    std::clock_t m_time;
};

#endif // WORDSOLVER_H
