#include "treedictionary.h"

void TreeDictionaryNode::insertElement(string element, uint index) {
    auto it = m_nodes.find(element[index]);
}

bool TreeDictionaryNode::contains(const string &element, uint index) {
    if (index >= element.length()) return true;
    
    
}

TreeDictionaryNode *TreeDictionaryNode::getNode(char c) {
    auto it = m_nodes.find(c);
    
    if (it == m_nodes.end()) return nullptr;
    return it->second;
}


