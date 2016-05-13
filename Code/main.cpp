#include <iostream>
#include "typedefs.h"
using namespace std;

int main()
{
    // Read dictionary
    int n;
    cin >> n;

    VVC dictionary(n);
    for (VC &V : dictionary) {
        int m;
        cin >> m;
        V.resize(n);

        for (char &c: V) {
            cin >> c;
            c -= '0';

            if (c > 9) {
                cout << "Error! wrong symbol: " << c + '0';
                return 1;
            }
        }
    }

    // Read soup
    VVC alphabetSoup(n, VC(n));
    for (VC &V : alphabetSoup) {
        for (char &c : V) {
            cin >> c;
            c -= '0';

            if (c > 9) {
                cout << "Error! wrong symbol: " << c + '0';
                return 1;
            }
        }
    }

    algorithm(dictionary, alphabetSoup);
}

