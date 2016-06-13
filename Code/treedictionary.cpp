#include "treedictionary.h"

TreeDictionaryNode::TreeDictionaryNode(TreeDictionaryNode *pParent)
        : m_pParent(pParent) {

}

TreeDictionaryNode::~TreeDictionaryNode() {
    for (auto it : m_nodes) {
        delete it.second;
    }
}

void TreeDictionaryNode::insertElement(const string &element, uint index) {
    auto it = m_nodes.find(element[index]);

    if (it == m_nodes.end()) {
        // Insert the element
        pair<char, TreeDictionaryNode *> ins;
        ins.first = element[index];
        ins.second = new TreeDictionaryNode(this);
        pair<ucTit, bool> p = m_nodes.insert(ins);
        it = p.first;
    }

    if (element.length() > index + 1) {
        it->second->insertElement(element, index + 1);
    }
}

bool TreeDictionaryNode::contains(const string &element, uint index) {
    auto it = m_nodes.find(element[index]);

    if (it == m_nodes.end()) return false;
    if (element.length() <= index + 1) return true;
    return it->second->contains(element, index + 1);
}

TreeDictionaryNode *TreeDictionaryNode::getNode(char c) {
    auto it = m_nodes.find(c);

    if (it == m_nodes.end()) return nullptr;
    return it->second;
}

TreeDictionary::TreeDictionary()
        : Dictionary(),
          m_pRootNode(new TreeDictionaryNode(nullptr)),
          m_pStepNode(m_pRootNode) {

}

TreeDictionary::~TreeDictionary() {
    delete m_pRootNode;
}

bool TreeDictionary::stepBackwards() {
    if (m_pStepNode->parent() == nullptr) return false;
    m_pStepNode = m_pStepNode->parent();
    return true;
}

bool TreeDictionary::stepForwards(char c) {
    TreeDictionaryNode *pNode = m_pStepNode->getNode(c);
    if (pNode == nullptr) return false;
    m_pStepNode = pNode;
    return true;
}
