#ifndef SOLVER_H
#define SOLVER_H
#include <memory>
#include <vector>
#include <ostream>
#include "dictionaries/dictionary.h"

class Solver
{
public:
    
    virtual void setDictionary(shared_ptr<Dictionary>) = 0;
    
    virtual void setBoard(vector<vector<char>> &) = 0;
    
    virtual void solve() = 0;
    
    virtual void printSolution(std::ostream out) = 0;
};

#endif // SOLVER_H
