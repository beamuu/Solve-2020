#include <iostream>
using namespace std;

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
}
