#include <iostream>
using namespace std;

int main() {

    int n,m;
    cin >> n >> m;
    int nloop = n , mloop = m;
    int *array = (int *)malloc(sizeof(int)*(n+m+1));
    int color,preBall,postBall,ballNumber=1;

    // for looping in array
    int current=1;

    while (nloop--) {
        cin >> color;
        array[ballNumber] = ballNumber+1;
        ballNumber++;
    }
    // last one should not be followed
    array[ballNumber-1] = 0;
    while (mloop--) {
        cin >> color >> preBall;
        postBall = array[preBall];
        array[preBall] = ballNumber;
        array[ballNumber] = postBall;
        ballNumber++;
    }
    /*
    for (int i=0 ; i<n+m+1 ; i++) {
        cout << array[i] << ' ' ;
    }
    cout << endl;
    */
    
    while (current) {
        cout << current << endl;
        current = array[current];
    }
    return 0;
}
