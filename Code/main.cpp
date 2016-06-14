/// @file main.cpp
/// @brief Contains the main code
/// @mainpage Super Sopa Solver
/// In this project we create a resolution program for the SuperSopa
/// problem invented by the Algoritmia teachers.
/// 
/// We use two interfaces to handle all the solver methods:
/// <ul>
/// <li>Dictionary interface for the dictionaries</li>
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <fstream>
#include <memory>

#include "typedefs.h"

#include "dictionaries/dictionary.h"
#include "dictionaries/treedictionary.h"
#include "dictionaries/hashdictionary.h"

using namespace std;

vector<string> getWords() {
    cout << "What words file do you want to open? ";
    string fileName;
    cin >> fileName;
    
    ifstream file(fileName);
    if (!file.good()) return vector<string>();
    
    int n;
    file >> n;
    vector<string> dictionary(n);
    for (string &s:  dictionary) file >> s;
    return dictionary;
}

VVC generateBoard() {
    string fileName;
    uint w, h;
    int seed;
    cout << "File name for the board file: ";
    cin >> fileName;
    cout << "Size of the board (width x height): ";
    cin >> w >> h;
    cout << "What seed you whant (-1 for current time)? ";
    cin >> seed;
    
    // Set seed
    default_random_engine rEngine(seed < 0 ? time(0) : seed);
}

void generateWordsList() {
    string fileName;
    uint min, max, words;
    int seed;
    cout << "File name for the words file: ";
    cin >> fileName;
    cout << "How many words do you want? ";
    cin >> words;
    cout << "What's the minimum and maximum length of the words? ";
    cin >> min >> max;
    cout << "What seed you want (-1 for current time)? ";
    cin >> seed;
    
    // Set seed
    default_random_engine rEngine(seed < 0 ? time(0) : seed);
    
    // Calculate mean and std values
    double avg = (min + max)/2.0;
    double stD = (min - avg)*(min - avg) + (max - avg)*(max - avg);
    stD = sqrt(stD/2.0);
    
    // Create distributions
    normal_distribution<float> dist(avg, stD);
    uniform_int_distribution<uint> uniformDist('0', '9');
    
    ofstream file(fileName);
    file << words << endl;
    while (words > 0) {
        uint val = (int) dist(rEngine);
        if (val < min || val > max) continue;
        
        for (uint i = 0; i < val; ++i) file << (char)uniformDist(rEngine);
        file << endl;
        --words;
    }
}

shared_ptr<Dictionary> getDictionary() {
    cout << "What type of dictionary do you want?" << endl
         << "1) Tree dictionary" << endl
         << "2) Hash dictionary" << endl;
    
    int option;
    cin >> option;
    
    // Shared pointer for better security
    shared_ptr<Dictionary> d;
    switch(option) {
        case 1:
            d = make_shared<TreeDictionary>();
            break;
        case 2:
            d = make_shared<HashDictionary>();
    }
    return d;
}

void solveProblem() {
    shared_ptr<Dictionary> d = getDictionary();
    
    vector<string> dict = getWords();
    for (string s : dict) {
        d->insertElement(s);
    }
    
}

int main()
{
    // Let the user choose an option
    bool ask = true;
    while (ask) {
        cout << "What do you want to do?" << endl
             << "0) Exit" << endl
             << "1) Generate dictionary file" << endl
             << "2) Call solver" << endl;
        
        uint option;
        cin >> option;
        
        switch(option) {
            case 0:
                ask = false;
                break;
            case 1:
                generateWordsList();
                break;
            case 2:
                solveProblem();
                break;
        }
    }
}

