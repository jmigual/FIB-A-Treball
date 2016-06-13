#include "treedictionary.h"

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
        ins.second = new TreeDictionaryNode;
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
        : m_rootNode(new TreeDictionaryNode) {

}
