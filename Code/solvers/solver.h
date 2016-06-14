#ifndef SOLVER_H
#define SOLVER_H
#include <memory>
#include <vector>
#include <ostream>

#include "dictionaries/dictionary.h"
#include "board.h"
#include "typedefs.h"

class Solver
{
public:
    
    virtual void setDictionary(shared_ptr<Dictionary>) = 0;
    
    virtual void setWords(vector<string>&) = 0;
    
    virtual void setBoard(Board &) = 0;
    
    virtual void solve() = 0;
    
    virtual void printSolution(std::ostream &out) = 0;
};

#endif // SOLVER_H
