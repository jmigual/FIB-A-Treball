#ifndef LINEARDICTIONARY_H
#define LINEARDICTIONARY_H

#include <string>
#include <vector>
#include <unordered_map>
#include "dictionary.h"

class LinearDictionary : public Dictionary
{
public:
    LinearDictionary();

    void insertElement(const string &);

    bool contains(const string &);

    void reset();

    pair<bool, bool> stepForwards(char);

    void stepBackwards();

    string popWord();

    bool isEmpty();

private:
    vector<string> m_Dict;
    string m_sCurrent;
    unordered_map<string,pair<bool,bool> > m_Dynamic;
};

#endif // LINEARDICTIONARY_H
