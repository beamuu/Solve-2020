#include <iostream>
using namespace std;

int count(int arr[]) {
    int count=0;
    for (int i=0 ; i<arr.length() ; i++) {
        if (arr[i]) count++;
    }
    return count;
}

int main() {

    int n , m;
    int a , b;
    int start,pos,destination;
    cin >> n >> m;
    int array[n+1][n+1];
    int *mark = (int *)malloc(sizeof(int)*(n+1));
    // reset to 0
    for (int i=0 ; i<n ; i++) { 
        for (int j=0 ; j<n ; j++) {
            array[i][j] = 0;
        }
    }

    while (m--) {
        cin >> a >> b;
        array[a][b] = 1;    array[b][a] = 1;
    }

    for (int i=0 ; i<n+1 ; i++) {
        if (count(array[i]) == 1) {
            start = i;
            break;
        }
    }
    pos = start;
    mark[start] = 1;
    while (1) {
        for (i=0 ; i<n+1 ; i++) {
            if (array[pos][i] == 1) {
                pos = i;
            }
        } 
    }

    return 0;

}
