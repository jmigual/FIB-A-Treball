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
    
    
    
private:
    
    shared_ptr<Dictionary> m_pDict;
    
    Board m_board;
};

#endif // PATRONSOLVER_H
