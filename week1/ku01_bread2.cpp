#include <iostream>
using namespace std;

int main(void) {

    int w,h,m,n, x1,y1,x2,y2;
    int max1,max2,area;
    cin >> w >> h >> m >> n;

    int mpos[m+2];
    int npos[n+2];

    mpos[0] = 0;
    npos[0] = 0;
    mpos[m+1] = w;
    npos[n+1] = h;

    for (int i=1 ; i<m+1 ; i++) {
        cin >> mpos[i];
    }
    for (int i=1 ; i<n+1 ; i++) {
        cin >> npos[i];
    }

    x1 = mpos[0];
    for (int i=1 ; i<m+2 ; i++) {

        y1 = npos[0];
        x2 = mpos[i];

        for (int j=1 ; j<n+2 ; j++) {

            y2 = npos[j];
            area = (y2-y1)*(x2-x1);

            if (area > max1) {
                max2 = max1;
                max1 = area;
            }
            else if (area > max2) {
                max2 = area;
            }

            y1 = y2;
            

        }
        x1 = x2;
    }
    cout << max1 << ' ' << max2 << endl;
    return 0;
}

