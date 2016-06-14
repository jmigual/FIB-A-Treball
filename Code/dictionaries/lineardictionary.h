#ifndef LINEARDICTIONARY_H
#define LINEARDICTIONARY_H

#include <string>
#include <vector>
#include "dictionary.h"

class LinearDictionary : public Dictionary
{
public:
    LinearDictionary();

    void insertElement(const string &);

    bool contains(const string &);

    void reset();

    bool stepForwards(char);

    bool stepBackwards();

private:
    vector<string> m_Dict;
    string m_sCurrent;
};

#endif // LINEARDICTIONARY_H