#include <iostream>
using namespace std;

int solve(int L , int N) {

    int res=0 , num=0;
    //  Find all orange.
    for (int i=L ; i>0 ; i--) {
        num += i*i;
    }

    num -= N;
    // Remove sold orange
    for (int i=L ; i>0 ; i--) {
        if (num <= 0 ) return res; // gg
        num -= i*i;
        res++;
        
    }
    return 0;
}

int main(void) {

    int L , N;
    cin >> L >> N;
    cout << solve(L,N) << endl;

    return 0;
}
