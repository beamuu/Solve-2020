#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int n,a,b,r,x,y;
    cin >> n >> a >> b >> r;
    int count=0;
    while (n--) {
        cin >> x >> y;
        if ( pow(a-x,2)+pow(b-y,2) <= pow(r,2) ) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
