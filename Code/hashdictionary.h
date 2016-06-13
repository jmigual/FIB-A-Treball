#ifndef HASHDICTIONARY_H
#define HASHDICTIONARY_H
#include <string>

#include "dictionary.h"

class HashDictionary : public Dictionary
{
public:
    HashDictionary();

    void insertElement(const string &elem);

    bool contains(const string &elem);

    void reset();

    bool stepForwards(char c);

    bool stepBackwards();
};

#endif // HASHDICTIONARY_H
