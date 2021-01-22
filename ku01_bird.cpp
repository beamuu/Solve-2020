#include <iostream>
using namespace std;

int main(void) {

    int n , i;
    int check1 , check2 , res=0;

    cin >> n;
    // Array of trees
    int tree[n];
    for (i=0; i<n ; i++) {
        cin >> tree[i];
    }
    
    for (int i=0 ; i<n ; i++) {
        // start
        if (i == 0) {
            check1 = i+1;
            if (tree[i] > tree[check1]) {
                res++;
            }
        }
        // end
        else if (i == n-1) {
            check1 = i-1;
            if (tree[i] > tree[check1]) {
                res++;
            }
        }
        // others
        else {
            check1 = i-1;
            check2 = i+1;
            if (tree[i] > tree[check1] && tree[i] > tree[check2]) {
                res++;
            }
        }
    }

    cout << res << endl;
    return 0;
}
