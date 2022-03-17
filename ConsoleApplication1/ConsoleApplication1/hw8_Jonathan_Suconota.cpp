// hw8_Jonathan_Suconota.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
using namespace std;

void print(int q[], int &count) {
    cout << "Solution:" << count++ << endl;
    cout << "Man    Women" << endl;
    for(int r = 0; r < 3; r++){
        // man  women 
        cout << r << " \t" << q[r] << endl;
    }
}

bool ok(int q[], int col) {
    // Male preferences
               // W  0  1  2
    int mp[3][3] = { 0, 2, 1,  // Male 1
                     0, 2, 1,  // Male 2
                     1, 2, 0 };// Male 3
    // Women preferences
               // M  0  1  2
    int wp[3][3] = { 2, 1, 0,  // Women 0
                     0, 1, 2,  // Women 1
                     2, 0, 1 };// women 2

    for (int i = 0; i < col; i++) {

        if (q[col] == q[i]) return false;
    }

    
    int currentMan = 0;
    int currentWoman = 0;

    // index man  == 2d row 
    // content is female == column 

   

    for (int i = 0; i < col; i++) {
        int newMan = col;
        int newWoman = q[col];
        currentMan = i;
        currentWoman = q[i];

        // if the rating we give our current woman is greater than the rating
        // we give another women from an existing pair, then we check if that women 
        // thinks we are a better partner than her current partner.
      
        if (mp[newMan][newWoman] > mp[newMan][currentWoman]) {
            if (wp[currentWoman][currentMan] > wp[currentWoman][newMan]) {
                return false;
            }
        }
    }
    return true;
}

int main(){

  
    int q[3] = { 0 };
    int c = 0; 
    int count = 1;
    q[c] = 0;
    while (c != -1 && c < 3) {
        c++;
        if (c == 3) {
            print(q, count);
            c--;
        }
        else q[c] = -1;
            while (c != -1 && q[c] < 3) {
                q[c]++;
                if (q[c] == 3) {
                    c--;
                }
                else if (ok(q, c)) { 
                    break;
                }
                
            }
    }
    return 0;
}

