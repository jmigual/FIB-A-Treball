#ifndef PATRONSOLVER_H
#define PATRONSOLVER_H
#include <memory>
#include <vector>

#include "dictionaries/dictionary.h"
#include "solvers/solver.h"
#include "board.h"

class PatronSolver : public Solver
{
public:
    
    PatronSolver();
    
    void setDictionary(shared_ptr<Dictionary> dict);
    
    void setWords(vector<string>&) {}
    
    void setBoard(Board &b);
    
    void solve();
    
    void printSolution(std::ostream &out);
    
private:
    
    void findRecursive(int row, int column);
    
    shared_ptr<Dictionary> m_pDict;
    
    Board m_board;
    
    vector<string> m_foundWords;
};

#endif // PATRONSOLVER_H
