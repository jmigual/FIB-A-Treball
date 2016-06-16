#include "hashdictionary.h"

HashDictionary::HashDictionary() {

}

void HashDictionary::insertElement(const string &S) {
    m_Dict.insert(S);
}

bool HashDictionary::contains(const string &S) {
    if (m_Dict.find(S) != m_Dict.end()) {
        m_sCurrent = S;
        return true;
    }
    return false;
}

void HashDictionary::reset() {
    m_sCurrent.clear();
}

pair<bool, bool> HashDictionary::stepForwards(char c) {
    string aux = m_sCurrent;
    aux.push_back(c);
    pair<bool, bool> p;

    p.first = p.second = false;

    auto mapit = m_Dynamic.find(aux);
    if (mapit != m_Dynamic.end())return mapit->second;

    if (contains(aux)) {
        p.first = p.second = true;
        return p;
    }

    for (string s : m_Dict) {
        if (aux.size() <= s.size()) {
            auto res = mismatch(aux.begin(), aux.end(), s.begin());
            if (res.first == aux.end()) {
                p.first = true;
                m_Dynamic[aux] = p;
                m_sCurrent.push_back(c);
                return p;
            }
        }
    }
    m_Dynamic[aux] = p;
    return p;
}

void HashDictionary::stepBackwards() {
    if (m_sCurrent.size() > 0) m_sCurrent.pop_back();
}

string HashDictionary::popWord(){
    m_Dict.erase(m_sCurrent);
    return m_sCurrent;
}

bool HashDictionary::isEmpty(){
    return m_sCurrent.size() == 0;
}
