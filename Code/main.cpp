#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <fstream>
#include <memory>

#include "dictionary.h"
#include "treedictionary.h"

using namespace std;

vector<string> getDictonary() {
    cout << "What dictoinary do you want to open? ";
    string fileName;
    cin >> fileName;
    
    ifstream file(fileName);
    int n;
    cin >> n;
    vector<string> dictionary(n);
    for (string &s:  dictionary) file >> s;
    return dictionary;
}

void generateDictionary() {
    string fileName;
    uint min, max, seed, words;
    cout << "File name for the dictionary: ";
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
    uniform_int_distribution<uint> uniformDist('A', 'Z');
    
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

void solveProblem() {
    cout << "What type of dictionary do you want?" << endl
         << "1) Tree dictionary" << endl
         << "2) Hash dictionary" << endl;
    
    int option;
    cin >> option;
    
    shared_ptr<Dictionary> d;
    switch(option) {
        case 1:
            d = make_shared<TreeDictionary>();
            break;
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
                generateDictionary();
                break;
            case 2:
                solveProblem();
                break;
        }
    }
}

