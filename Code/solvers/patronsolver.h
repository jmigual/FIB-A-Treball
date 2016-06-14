#ifndef PATRONSOLVER_H
#define PATRONSOLVER_H
#include <memory>
#include <vector>
#include <list>

#include "dictionaries/dictionary.h"
#include "solvers/solver.h"
#include "board.h"

const int POSITIONS = 8;
constexpr int R[POSITIONS] = { 1, 1,  1,  0, -1, -1, -1, 0 };
constexpr int C[POSITIONS] = { 1, 0, -1, -1, -1,  0,  1, 1 };

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
    
    void findRecursive(int row, int col);
    
    void insertWord();
    
    bool validPos(int row, int col);
    
    shared_ptr<Dictionary> m_pDict;
    
    Board m_board;
    
    list<string> m_foundWords;
    
    list<char> m_find;
};

#endif // PATRONSOLVER_H
