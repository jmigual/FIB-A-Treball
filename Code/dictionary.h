#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <string>
using namespace std;

// Interface for all dictionaries
class Dictionary
{
public:
    
    virtual ~Dictionary() {}

    virtual void insertElement(const string &);

    virtual bool contains(const string &);

    virtual void reset();

    virtual void stepForwards(char c);
    
    virtual void stepBackwards();
};

#endif // DICTIONARY_H
