#include <iostream>
using namespace std;

<<<<<<< HEAD
int cummulativePrice[100000];


int solve (int money , int n) {
    for (int i=0 ; i<n ; i++) {
        if ( money < cummulativePrice[i] ) {
            return i;
        }
    }
    return n;
}


int main() {
    
    int n , k , bookPrice , sum=0, money;
    cin >> n >> k;

    for (int i=0 ; i<n ; i++) {
        cin >> bookPrice;
        sum += bookPrice;
        cummulativePrice[i] = sum;
    }    
    while (k--) {
        cin >> money;
        cout << solve(money , n) << endl;
    }
    return 0;
=======
int main() {
    
    int n,k;
    cin >> n >> k;
    
    int lib[n];
    int count=0;
    int input;
    for (int i=0 ; i<n ; i++) {
        cin >> lib[i];
    }

    while (k--) {
        cin >> input;
        for (int i=0 ; i<n ; i++) {
            if (input-lib[i] < 0) {
                cout << count << endl;
                break;
            }
            else {
                input -= lib[i];
                count++;
            }
        }
        count = 0;
    }
    return 0;


>>>>>>> 5988f672c240eab9de70352d75e1ff730165330f
}
