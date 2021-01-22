// NOT SEND !!!

#include <iostream>
using namespace std;

int main(void) {
    
    int dest , level=0 , now=0 , res=-2;
    cin >> dest;

    while (now<dest) {
        now += 2*level+1;
        level++;
        res += 2;
    }

    if (level%2==0) {
        if (dest%2==0) {
            cout << res << endl;
        }
        else {
            cout << res-1 << endl;
        }
    }
    else {
        if (dest%2==1) {
            cout << res << endl;
        }
        else {
            cout << res-1 << endl;
        }
    }
    return 0;

}