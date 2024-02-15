#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int main() {
    string continueRunning;
    do {
        string nS, kS, epsilonS;
        int n, k;
        double epsilon;

        // Введення даних

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
            return 1;
        }
        try {
            cout << "Введіть n2(натуральне число яке >n1): ";
            cin >> nS;
            cout << endl;
            size_t pos;
            n = stoi(nS, &pos);
            if (pos < nS.size()|| n < k) {throw 1;}
        }
        catch(...) {
            cout << "Ви ввели некоректре число!";
            return 1;
        }
        try {
            cout << "Введіть точність обчислення (додатне число): ";
            cin >> epsilonS;
            cout << endl;
            size_t pos;
            epsilon = stod(epsilonS, &pos);
            if (pos < epsilonS.size()|| epsilon <= 0) {throw 1;}
        }
        catch(...) {
            cout << "Ви ввели некоректне число!";
            return 1;
        }

        long double product = 1.0;
        for (int i = k; i <= n; i++) {
            product *= (1.0 - pow(-1.0, i - 1) / (3 * i - 1));
        }

        cout << fixed << setprecision(epsilon) << "Значення формули: " << product << endl;

        cout << "Продовжити виконання програми? (y/n): ";
        cin >> continueRunning;
        cout << endl;
    } while (continueRunning == "y" || continueRunning == "Y");

    return 0;
}