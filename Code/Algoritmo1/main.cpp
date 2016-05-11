#include <iostream>
#include <vector>
using namespace std;

typedef vector< char > VC;
typedef vector< VC > VVC;

int main()
{
    int k;
    cin >> k;
    vector<string> D(k);
    
    // Read dictionary
    for (string &s : D) cin >> s;
    
    int n;
    cin >> n;
    
    
    VVC S(n, VC(n));
    
    // Read alphabet soup
    for (VC &V : S) for (char &c : V) cin >> c;
    
    // Do some stuff here
}

