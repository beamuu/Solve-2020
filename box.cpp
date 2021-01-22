#include <iostream>
using namespace std;

string map[30];
int result = 0;
int mapBorderX , mapBorderY;

int Move(int x, int y, int dir) {

    // check if
    if (result) {
        return 1;
    }
    if (x == 0) {
        return 1;
    }
    if (x == mapBorderX || y == mapBorderY) {
        return 0;
    }   
    if (map[x][y] == '#' || map[x-1][y] == '#' || map[x][y+1] == '#' || map[x-1][y+1] == '#') {
       return 0; 
    }
    // try north , 
    if (dir != 2) {
        result = result || Move(x-1,y,0);
    }
    // try south ,
    if (dir != 0) {
        result = result || Move(x+1,y,2);
    }
    // try east
    if (dir != 3) {
        result = result || Move(x,y+1,1);
    }
    // try west
    if (dir != 1) {
        result = result || Move(x,y-1,3);
    }
    return result;

}

int main() {

    int n,m;
    cin >> n >> m;

    mapBorderX = n;
    mapBorderY = m;

    for (int i=0 ; i<n ; i++) {
        cin >> map[i];
    }

    for (int j=0 ; j<m ; j++) {
        Move(n-1,j,0);
    }
    if (result) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}


