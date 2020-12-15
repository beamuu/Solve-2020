#include <iostream>
using namespace std;

int main(void) {

    int P1,P2,P3;
    int R1,R2,R3;
    int N , res;

    cin >>  P1 >> P2 >> P3;
    cin >> N;

    int item[N];
    for (int i=0 ; i<N ; i++) {
        cin >> item[i];
    }
    
    for (int i=0 ; i<N ; i++) {
        switch (item[i]) {
            case 1:
                R1++;
                break;
            case 2:
                R2++;
                break;
            case 3:
                R3++;
                break;
        }
    }

    R1 *= P1;
    R2 *= P2;
    R3 *= P3;

    if (R1 <= R2 && R1 <= R3) cout << R1 << endl;
    else if (R2 <= R1 && R2 <= R3) cout << R2 << endl;
    else cout << R3 << endl;
    return 0;

}