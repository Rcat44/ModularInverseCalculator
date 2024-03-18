#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    unsigned long long int s = 17;
    int initialNum, phi, exponentCalc;
    unsigned int modNum;
    int squareNum = 2;
    unsigned long long int inverseCalc = 1;
    long long int showWork = 1;

    vector <int> powersToUse;
    vector <long long int> showCalc;
    int powerCounter = 1;

    cout << "Enter a number to find the inverse of: ";
    cin  >> s;
    initialNum = s;

    cout << "Enter N: ";
    cin  >> modNum;

    cout << "Enter Phi of N: ";
    cin  >> phi;
    exponentCalc = phi - 1;

    while (exponentCalc > powerCounter) {
        powerCounter *= 2;
    }
    powerCounter /= 2;

    while (exponentCalc != 0) {

        if (exponentCalc - powerCounter >= 0) {
            exponentCalc -= powerCounter;
            powersToUse.push_back(powerCounter); 
        }
        powerCounter /= 2;
    }
    sort(powersToUse.begin(), powersToUse.end());

    if (powersToUse[0] == 1) {
        inverseCalc *= initialNum;
        showCalc.push_back(initialNum);
    }

    cout << "\nInverse of " << initialNum << " (mod " << modNum << ")\n\n";

    while (squareNum <= powersToUse[powersToUse.size() - 1]) {
        s *= s;
        cout << initialNum << "^" << squareNum << " = " << s << " = ";
        s %= modNum;
        cout << s << " (mod " << modNum << ")\n";

        for (unsigned int i = 0; i < powersToUse.size(); i++) {
            if (powersToUse[i] == squareNum) {
                showCalc.push_back(s);
                inverseCalc *= s;
                inverseCalc %= modNum;
                i = powersToUse.size();
            }
        }
        squareNum *= 2;  
    }
    if ((initialNum * inverseCalc) % modNum == 1) {
        cout << "\nInverse: " << inverseCalc << endl;

        cout <<"\nCALCULATIONS\n\n";

        for (unsigned int i = 0; i < showCalc.size(); i++) {
            cout << showWork << " * " << showCalc[i] << " = ";
            showWork *= showCalc[i];
            cout << showWork << " = ";
            showWork %= modNum;
            cout << showWork << " (mod " << modNum << ")\n";
        }

        cout << "\nInverse: " << inverseCalc << endl << endl;
    }
    else {
        char displayWork;
        cout << "\nNOT INVERTIBLE!\n\n";
        cout << "Show work anyway? (y/n): ";
        cin  >> displayWork;

        if (displayWork == 'Y' || displayWork == 'y') {
            cout << "\nINCORRECT Inverse: " << inverseCalc << endl;

            cout <<"\nCALCULATIONS\n\n";

            for (unsigned int i = 0; i < showCalc.size(); i++) {
                cout << showWork << " * " << showCalc[i] << " = ";
                showWork *= showCalc[i];
                cout << showWork << " = ";
                showWork %= modNum;
                cout << showWork << " (mod " << modNum << ")\n";
            }

            cout << initialNum << "^(" << phi << "-1) = " << inverseCalc << endl << endl;
            cout << initialNum << " * " << inverseCalc << " = " << initialNum * inverseCalc << " = "
                << (initialNum * inverseCalc) % modNum << "(mod " << modNum << ")\n\n";
        }
    }
    
    return 0;
}