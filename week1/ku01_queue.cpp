#include <iostream>
using namespace std;

int MAX(int Height[] , int pos) {

    int max_h = Height[0];

    if (pos == 0) return 0;

    for (int i=0 ; i<pos ; i++) {
        if (Height[i] > max_h) max_h = Height[i];
    }
    return max_h;
}

void solve(int N , int L) {


    int Height[N] , Request_Chair[L];
    int max_h , res;

    for (int i=0 ; i<N ; i++) {
        cin >> Height[i];
    }
    for (int i=0 ; i<L ; i++) {
        cin >> Request_Chair[i];
    }

    for (int i=0 ; i<L ; i++) {
        if (Request_Chair[i] == 1) res = 0;
        else {
            res = 0;
            max_h = MAX(Height , Request_Chair[i]-1);
            if (Height[Request_Chair[i]-1] <= max_h) {
                res = (max_h+1)-Height[Request_Chair[i]-1];
                Height[Request_Chair[i]-1] = res;
            }
        }
        cout << res << endl;
    }
    return;

}

int main(void) {

    int N , L;
    cin >> N >> L;
    solve(N,L);
    return 0;
}