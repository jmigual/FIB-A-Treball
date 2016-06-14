#include "treedictionary.h"

TreeDictionaryNode::TreeDictionaryNode(TreeDictionaryNode *pParent)
        : m_pParent(pParent),
          m_isFinal(false) {

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
        auto p = m_nodes.insert(ins);
        it = p.first;
    }

    if (element.length() > index + 1) {
        it->second->insertElement(element, index + 1);
    }
    else it->second->m_isFinal = true;
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

TreeDictionary::TreeDictionary()
        : Dictionary(),
          m_pRootNode(new TreeDictionaryNode(nullptr)),
          m_pStepNode(m_pRootNode) {

}

TreeDictionary::~TreeDictionary() {
    delete m_pRootNode;
}

void TreeDictionary::stepBackwards() {
    if (m_pStepNode->parent() == nullptr) return;
    m_pStepNode = m_pStepNode->parent();
}

pair<bool, bool> TreeDictionary::stepForwards(char c) {
    pair<bool,bool> p;
    
    TreeDictionaryNode *pNode = m_pStepNode->getNode(c);
    if (pNode == nullptr) {
        return make_pair(false, false);
    }
    m_pStepNode = pNode;
    return make_pair(true, pNode->isFinal());
}
