#include <iostream>
#include <bitset>

using namespace std;
main() {
    int x;
    int count = 0;
    int triplets = 0;

    cout << "Enter a number: ";
    cin >> x;
    cout << "Binary representation: " << bitset<8*sizeof(x)>(x) << endl;

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
    cout << "Number of triplets: " << triplets << endl;
    return 0;
}