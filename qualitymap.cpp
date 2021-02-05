#include <iostream>
using namespace std;

char map[30][30];
bool visited[30][30];
char water = '#';
char forest = '*';
char mineral = '$';

int count_forest  = 0;
int count_mineral = 0;
int all = 0;

int high=0;
int medium=0;

void DFS(int n , int m , int i , int j) {
    visited[i][j] = true;
    all++;
    //printf("At node:[%d][%d] , count_forest: %d , count_mineral: %d , all: %d\n" , i,j,count_forest,count_mineral,all);
    // Check each elements
    if (map[i][j] == forest) {
        count_forest++;
    }
    else if (map[i][j] == mineral) {
        count_mineral++;
    }
    // North
    if (i > 0 && map[i-1][j] != water) {
        if (!visited[i-1][j]) {
            DFS(n,m,i-1,j);
        }
    }
    // South
    if (i < n-1 && map[i+1][j] != water) {
        if (!visited[i+1][j]) {
            DFS(n,m,i+1,j);
        }
    }
    // East
    if (j < m-1 && map[i][j+1] != water) {
        if (!visited[i][j+1]) {
            DFS(n,m,i,j+1);
        }
    }
    // West
    if (j > 0 && map[i][j-1] != water) {
        if (!visited[i][j-1]) {
            DFS(n,m,i,j-1);
        }
    }
    
}

int main() {
    
    int n,m;
    cin >> n >> m;
    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<m ; j++) {
            scanf(" %c",&map[i][j]);
        }
    }

    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<m ; j++) {
            if (!visited[i][j] && map[i][j] != water) {
                DFS(n,m,i,j);
                if (count_forest && count_mineral) {
                    high+=all;
                }
                else if (count_forest || count_mineral) {
                    medium+=all;
                }
                //printf("Done DFS with=> high:%d medium:%d\n",high,medium);
                all = 0;
                count_forest  = 0;
                count_mineral = 0;
            }
        }
    }
    printf("%d %d\n" , high , medium );
    return 0;
}


