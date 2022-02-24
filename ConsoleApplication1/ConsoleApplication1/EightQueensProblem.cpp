

#include <iostream>
using namespace std;
int main() {
    int testCount = 1;
    int b[8] = { 0 }, c = 0;
    b[0] = 0;
    // nc
nc:
    c++;
    if (c == 8) goto print;
    // nr
    b[c] = -1;
nr:
    b[c]++;
    if (b[c] == 8)goto bt;

    for (int i = 0; i < c; i++) {
        if (c - i == b[c] - b[i]) goto nr;
        if (c - i == abs(b[c] - b[i])) goto nr; //
        if (b[c] == b[i]) goto nr; // row test
    }
    goto nc;
    //backtracking
bt:
    c--;
    if (c == -1) return 0;
    goto nr;
    // print board
print:
    cout << "\nTest: " << testCount++ << endl;
    cout << " 1D Array: ";
    for (int r = 0; r < 8; r++) {
        cout << b[r] << " ";
    }
    cout << endl;
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            if (b[c] == r) {
                cout << "1";
            }
            else {
                cout << "0";
            }
        }
        cout << endl;
    }
    goto bt;

    return 0;
}
