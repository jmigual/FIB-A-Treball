#include "solver.h"

ostream &operator<<(ostream &out, const Solver &s) {
    return s.printSolution(out);
}
