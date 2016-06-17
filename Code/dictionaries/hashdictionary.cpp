#include "hashdictionary.h"

HashDictionary::HashDictionary() {

}

void HashDictionary::insertElement(const string &S) {
    m_dict.insert(S);
}

bool HashDictionary::contains(const string &S) {
    if (m_dict.find(S) != m_dict.end()) {
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

    auto mapit = m_dynamic.find(aux);
    if (mapit != m_dynamic.end()){
        if ((mapit->second).first) m_sCurrent.push_back(c);
        return mapit->second;
    }

    if (contains(aux)) {
        p.first = p.second = true;
        return p;
    }

    for (const string &s : m_dict) {
        if (aux.size() <= s.size()) {
            auto res = mismatch(aux.begin(), aux.end(), s.begin());
            if (res.first == aux.end()) {
                p.first = true;
                m_dynamic[aux] = p;
                m_sCurrent.push_back(c);
                return p;
            }
        }
    }
    m_dynamic[aux] = p;
    return p;
}

void HashDictionary::stepBackwards() {
    if (m_sCurrent.size() > 0) m_sCurrent.pop_back();
}

string HashDictionary::popWord(){
    m_dict.erase(m_sCurrent);
    return m_sCurrent;
}

bool HashDictionary::isEmpty(){
    return m_dict.empty();
}
