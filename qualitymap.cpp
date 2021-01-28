#include <iostream>
using namespace std;

int xpos,ypos;

void move(string *map , int **mark) {
    mark[xpos][ypos] = 1;
    // North
    if (xpos != 0 && !mark[xpos][ypos-1]) {
        return north
    }
    // South
    // East
    // West
}

int main() {
    
    int n,m;
    cin >> n >> m;
    string map[n];
    int **mark = (int **)malloc(sizeof(int *)*n);
    for (int i=0 ; i<n ; i++) {
        mark[i] = (int *)malloc(sizeof(int)*m);
    }
    
    for (int i=0 ; i<n ; i++) {
        cin >> map[i];
    }
    /*
    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<m ; j++) {
            cout << mark[i][j];
        }
        cout << endl;
    }
    */
    while (1) {
        move()
    }


    return 0;
}
