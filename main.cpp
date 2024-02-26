#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string xS;
    int x;
    int count = 0;
    int triplets = 0;

    try {
        cout << "Введіть x(x > 0): ";
        cin >> xS;
        cout << endl;
        size_t pos;
        x = stoi(xS, &pos);
        if (pos < xS.size()||x <= 0) {throw 1;}
        }
    catch(...) {
        cout << "Ви ввели некоректре число!";
        return 1;
        }

    vector<int> binary;
    int num = x;
    while(num) {
        binary.push_back(num % 2);
        num /= 2;
    }
    cout << "Цифра у двійковому коді: ";
    for(int i = binary.size() - 1; i >= 0; i--) {
        cout << binary[i];
    }
    cout << endl;

    for (int i = 0; i <= 32; i++) {
        if ((x & (1 << i)) != 0) {
            count++;
            if (count == 3) {
                triplets++;
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    cout << "Кількість одиниць які зустрічаються 3 рази підряд: " << triplets << endl;
    return 0;
}
