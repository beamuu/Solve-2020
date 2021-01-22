#include <iostream>
using namespace std;

void solve(int w , int h , int m , int n) {

    int x[m];
    int y[n];
    int res1=0 , res2=0;

    int x1=0 , x2;
    int y1=0 , y2;

    for (int i=0 ; i<m ; i++) {
        cin >> x[i];
    }

    for (int i=0 ; i<n ; i++) {
        cin >> y[i];
    }
    // normal loop
    for (int i=0 ; i<m ; i++) {
        x2 = x[i];
        for (int j=0 ; j<n ; j++) {
            y2 = y[j];
            if ( (x2-x1)*(y2-y1) > res1) {
                res2 = res1;
                res1 = (x2-x1)*(y2-y1);
            }
            else if ((x2-x1)*(y2-y1) > res2) {
                res2 = (x2-x1)*(y2-y1);
            }
            y1 = y2;
        }
        x1 = x2;
    }

    // right-border
    x2 = w;
    x1 = x[m-1];
    y1 = 0;
    for (int j=0 ; j<n ; j++) {
        y2 = y[j];
        if ( (x2-x1)*(y2-y1) > res1) {
                res2 = res1;
                res1 = (x2-x1)*(y2-y1);
            }
            else if ((x2-x1)*(y2-y1) > res2) {
                res2 = (x2-x1)*(y2-y1);
            }
        y1 = y2;
    }

    // top-border
    y2 = h;
    y1 = y[n-1];
    x1 = 0;
    for (int i=0 ; i<m ; i++) {
        x2 = x[i];
        if ( (x2-x1)*(y2-y1) > res1) {
                res2 = res1;
                res1 = (x2-x1)*(y2-y1);
            }
            else if ((x2-x1)*(y2-y1) > res2) {
                res2 = (x2-x1)*(y2-y1);
            }
        x1 = x2;
    }

    cout << res1 << " " << res2;

    return;
}

int main(void) {

    int w,h,m,n;
    cin >> w >> h >> m >> n;

    solve(w,h,m,n);
    return 0;
}