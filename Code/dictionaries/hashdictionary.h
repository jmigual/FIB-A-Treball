#ifndef HASHDICTIONARY_H
#define HASHDICTIONARY_H
#include <string>
#include <unordered_set>

#include "dictionary.h"

class HashDictionary : public Dictionary
{
public:
    HashDictionary();

    void insertElement(const string &);

    bool contains(const string &);

    void reset();

    pair<bool, bool> stepForwards(char);

    void stepBackwards();

private:
    unordered_set<string> m_Dict;
    string m_sCurrent;
};

#endif // HASHDICTIONARY_H
