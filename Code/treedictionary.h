#ifndef TREEDICTIONARY_H
#define TREEDICTIONARY_H
#include <unordered_map>
#include <string>

#include "dictionary.h"

using namespace std;

class TreeDictionaryNode
{
    typedef unordered_map<char, TreeDictionaryNode *>::iterator ucTit;

public:
    /**
     * @brief TreeDictionaryNode constructor
     * @param pParent Parent Node
     */
    TreeDictionaryNode(TreeDictionaryNode *pParent);

    /** 
     * @brief Destructor
     */
    ~TreeDictionaryNode();

    /**
     * @brief Inserts the string <b>element</b> into the dictionary
     * from the selected index.
     * @param element Element to insert
     * @param index Index from <b>element</b> to be inserted
     */
    void insertElement(const string &element, uint index);

    /**
     * @brief Check if the element is in the node at position index and below
     * @param element Element to be checked
     * @param index Index where to check
     * @return <b>true</b> if the element from index to length is in the node,
     * otherwise returns <b>false</b>
     */
    bool contains(const string &element, uint index);

    TreeDictionaryNode *getNode(char c);
    
    inline TreeDictionaryNode *parent() { return m_pParent; }

private:

    unordered_map<char, TreeDictionaryNode *> m_nodes;
    
    TreeDictionaryNode* m_pParent;
};

class TreeDictionary : public Dictionary
{
public:

    TreeDictionary();
    
    ~TreeDictionary();

    inline void insertElement(const string &element) {
        if (element.length() == 0) return;
        m_pRootNode->insertElement(element, 0);
    }

    inline bool contains(const string &element) {
        if (element.length() == 0) return false;
        return m_pRootNode->contains(element, 0);
    }

    inline TreeDictionaryNode *getNode(char c) {
        return m_pRootNode->getNode(c);
    }
    
    inline void reset() { m_pStepNode = m_pRootNode; }
    
    bool stepBackwards();
    
    bool stepForwards(char c);
    
    

private:

    TreeDictionaryNode *m_pRootNode;
    
    TreeDictionaryNode *m_pStepNode;
    
};

#endif // TREEDICTIONARY_H
