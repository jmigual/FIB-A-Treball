#include "lineardictionary.h"
#include "algorithm"

void LinearDictionary::insertElement(const string & S){
    m_Dict.push_back(S);
}

bool LinearDictionary::contains(const string & S){
    if (find(m_Dict.begin(), m_Dict.end(), S) != m_Dict.end()){
        m_sCurrent = S;
        return true;
    }
    return false;
}

void LinearDictionary::reset(){
    m_sCurrent.clear();
}

bool LinearDictionary::stepForwards(char c){
    string aux = m_sCurrent;
    aux.push_back(c);

    for (string s : m_Dict) {
        if (aux.size() <= s.size()){
            auto res = mismatch(aux.begin(), aux.end(), s.begin());
            if (res.first == aux.end()) {
                m_sCurrent.push_back(c);
                return true;
            }
        }
    }

    return false;
}

bool LinearDictionary::stepBackwards(){
    if (m_sCurrent.size() == 0) return false;
    m_sCurrent.pop_back();
    return true;
}

