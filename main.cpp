#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    string continueRunning;
    do {
        string nS, kS;
        int n, k;

        try {
            cout << "Введіть n1 (натуральне число): ";
            cin >> kS;
            cout << endl;
            size_t pos;
            k = stoi(kS, &pos);
            if (pos < kS.size()|| k < 1) {throw 1;}
        }
        catch(...) {
            cout << "Ви ввели некоректне число!";
            continueRunning = "y";
            cout << endl;
            continue;
        }
        try {
            cout << "Введіть n2(натуральне число яке >n1): ";
            cin >> nS;
            cout << endl;
            size_t pos1;
            n = stoi(nS, &pos1);
            if (pos1 < nS.size()|| n < k) {throw 1;}
        }
        catch(...) {
            cout << "Ви ввели некоректре число!";
            cout << endl;
            continueRunning = "y";
            continue;
        }

        long double product = 1.0;
        for (int i = k; i <= n; i++) {
            double numer =(1.0 - pow(-1.0, i - 1) / (3 * i - 1));
            cout << "Числове значення: " << numer << endl;
            product *= numer;
        }

        cout << "Значення формули: " << product << endl;

        cout << "Продовжити виконання програми? (y/n): ";
        cin >> continueRunning;
        cout << endl;
    } while (continueRunning == "y" || continueRunning == "Y");

    return 0;
}