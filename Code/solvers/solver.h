#ifndef SOLVER_H
#define SOLVER_H
#include <memory>
#include <vector>
#include <ostream>

#include "dictionaries/dictionary.h"
#include "board.h"
#include "typedefs.h"


const int POSITIONS = 8;
constexpr int R[POSITIONS] = { 1, 1,  1,  0, -1, -1, -1, 0 };
constexpr int C[POSITIONS] = { 1, 0, -1, -1, -1,  0,  1, 1 };

class Solver
{
public:
    
    virtual void setDictionary(shared_ptr<Dictionary>) = 0;
    
    virtual void setWords(vector<string>&) = 0;
    
    virtual void setBoard(Board &) = 0;
    
    virtual void solve() = 0;
    
    virtual std::ostream& printSolution(std::ostream &out) const = 0;
    
    friend std::ostream& operator<< (std::ostream &out, const Solver &s);
};

#endif // SOLVER_H
