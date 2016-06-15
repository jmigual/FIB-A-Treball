#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <string>
#include <utility>
using namespace std;

typedef unsigned int uint;

/**
 * @brief The Dictionary interface is used in all the dictionaries
 */
class Dictionary
{
public:
    /**
     * @brief Insert the element into the dictionary
     * @param elem Element to be inserted
     */
    virtual void insertElement(const string &elem) = 0;

    /**
     * @brief Check if the element is in the dictionary
     * @param elem Element to be checked
     * @return <b>true</b> if the element is in the dictionary
     * otherwise returns <b>false</b>
     */
    virtual bool contains(const string &elem) = 0;

    /**
     * @brief reset Used in incremental search, resets the incremental search
     */
    virtual void reset() = 0;

    /**
     * @brief Add one char in the dictionary incremental search and
     * checks if the current generated word is in the dictionary
     * @param c Character added to check if the formed word is in the dictionary
     * @return Returns a pair with two balues, first is <b>true</b> if the current
     * element contains a valid leter. Second is <b>true</b> if with this letter
     * a word is found.
     */
    virtual pair<bool, bool> stepForwards(char c) = 0;

    /**
     * @brief Remove the last character in the dictionary incremental search
     * and check if it is possible to go backwards
     * @return <b>true</b> if it is possible to go backwards in the current
     * state, otherwise returns <b>false</b>
     */
    virtual void stepBackwards() = 0;

    virtual string popWord() {
        return "";
    }
    
    virtual bool isEmpty();
};

#endif // DICTIONARY_H
