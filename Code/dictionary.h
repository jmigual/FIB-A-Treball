#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <string>
using namespace std;

/**
 * @brief The Dictionary interface is used in all the dictionaries
 */
class Dictionary
{
public:
    
    /// @brief Destructor
    virtual ~Dictionary() {}

    /**
     * @brief Insert the element into the dictionary
     * @param elem Element to be inserted
     */
    virtual void insertElement(const string &elem) = 0;

    /**
     * @brief Check if the element is in the dictionary
     * @param elem Element to be checked
     * @return <em>true</em> if the element is in the dictionary
     * otherwise returns <em>false</em>
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
     * @return <em>true</em> if the current generated sequence is in the 
     * dictionary, otherwise returns <em>false</em>
     */
    virtual bool stepForwards(char c) = 0;
    
    /**
     * @brief Remove the last character in the dictionary incremental search
     * and check if it is possible to go backwards
     * @return <em>true</em> if it is possible to go backwards in the current 
     * state, otherwise returns <em>false</em>
     */
    virtual bool stepBackwards() = 0;
};

#endif // DICTIONARY_H
