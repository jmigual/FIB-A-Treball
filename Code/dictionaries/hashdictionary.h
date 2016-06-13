#ifndef HASHDICTIONARY_H
#define HASHDICTIONARY_H
#include <string>

#include "dictionary.h"

class HashDictionary : public Dictionary
{
public:
    HashDictionary();

    void insertElement(const string &);

    bool contains(const string &);

    void reset();

    bool stepForwards(char);

    bool stepBackwards();
};

#endif // HASHDICTIONARY_H
