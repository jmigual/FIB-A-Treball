#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <string>
using namespace std;

// Interface for all dictionaries
class Dictionary
{
public:
    
    virtual ~Dictionary() {}

    virtual void insertElement(const string &) = 0;

    virtual bool contains(const string &) = 0;

    virtual void reset() = 0;

    virtual void stepForwards(char c) = 0;
    
    virtual void stepBackwards() = 0;
};

#endif // DICTIONARY_H
