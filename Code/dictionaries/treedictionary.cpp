#include "treedictionary.h"
#include <cassert>
#include <iostream>

TreeDictionaryNode::TreeDictionaryNode(TreeDictionaryNode *pParent)
        : m_pParent(pParent),
          m_isFinal(false),
          m_count(0),
          m_data(0) {

}

TreeDictionaryNode::~TreeDictionaryNode() {
    for (auto it : m_nodes) {
        delete it.second;
    }
}

void TreeDictionaryNode::insertElement(const string &element, uint index) {
    ++m_count;    
    if (element.length() > index) {        
        auto it = m_nodes.find(element[index]);
        // The character is not in the tree
        if (it == m_nodes.end()) {
            // Insert the element
            pair<char, TreeDictionaryNode *> ins;
            ins.second = new TreeDictionaryNode(this);
            ins.second->m_data = element[index];
            ins.first = element[index];
            auto p = m_nodes.insert(ins);
            it = p.first;
        }
        
        it->second->insertElement(element, index + 1);
    }
    else {
        this->m_isFinal = true;
    }
}

bool TreeDictionaryNode::contains(const string &element, uint index) {
    auto it = m_nodes.find(element[index]);

    if (it == m_nodes.end()) return false;
    if (element.length() > index + 1) {
        return it->second->contains(element, index + 1);
    }
    return it->second->m_isFinal;
}

TreeDictionaryNode *TreeDictionaryNode::getNode(char c) {
    auto it = m_nodes.find(c);

    if (it == m_nodes.end()) return nullptr;
    return it->second;
}

string TreeDictionaryNode::popWord(string s, TreeDictionaryNode *&node, int &deleted) {
    --m_count;
    // The root node
    if (node == nullptr) node = this;
    m_isFinal = false;

    vector<char> toDelete;

    for (auto it : m_nodes) {
        if (it.second->m_count <= 0) {
            if (it.second == node) {
                node = this;
            }
            delete it.second;
            toDelete.push_back(it.first);
        }
    }
    if (toDelete.size() > 0) ++deleted;
    
    for (char c : toDelete) m_nodes.erase(m_nodes.find(c));
    if (this->m_data == 0) return s;
    return this->m_pParent->popWord(m_data + s, node, deleted);
}

bool TreeDictionaryNode::isEmpty() {
    return m_nodes.size() == 0;
}

TreeDictionary::TreeDictionary()
        : Dictionary(),
          m_pRootNode(new TreeDictionaryNode(nullptr)),
          m_pStepNode(m_pRootNode),
          m_deleted(0) {

}

TreeDictionary::~TreeDictionary() {
    delete m_pRootNode;
}

void TreeDictionary::stepBackwards() {
    if (m_deleted > 0) {
        --m_deleted;
        return;
    }
    
    if (m_pStepNode->parent() == nullptr) return;
    m_pStepNode = m_pStepNode->parent();
}

pair<bool, bool> TreeDictionary::stepForwards(char c) {
    if (m_deleted > 0) return make_pair(false, false);

    TreeDictionaryNode *pNode = m_pStepNode->getNode(c);
    if (pNode == nullptr) return make_pair(false, false);
    
    m_pStepNode = pNode;
    return make_pair(true, pNode->isFinal());
}

string TreeDictionary::popWord() {
    TreeDictionaryNode* node = nullptr;
    string s = m_pStepNode->popWord("", node, m_deleted);
    assert(node != nullptr);
    m_pStepNode = node;
    
    return s;
}

bool TreeDictionary::isEmpty() {
    return m_pRootNode->isEmpty();
}
