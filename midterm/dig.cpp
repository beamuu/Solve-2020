#include <iostream>
#include <list>
using namespace std;


typedef struct NODE {int x,y,condition,token,count;} node;
list <node> queue;
int xlimit,ylimit;
int res=10000000;
void BFS(char **map , int xstart , int ystart , int xend , int yend , int **visited) {

    char wall_stone = '#';
    char wall_dirt  = '*';
    char path       = '.';

    node newnode;
    newnode.x = xstart;
    newnode.y = ystart;
    newnode.condition = 1; 
    newnode.token = 1; 
    newnode.count = 0;
    queue.push_back(newnode);

    int x,y;
    node current;

    while (!queue.empty()) {
        current = queue.front();
        x = current.x;
        y = current.y;
        visited[x][y] = 1;
        queue.pop_front();

        if (x == xend && y == yend) {
            if (current.count < res) {
                res = current.count;
                continue;
            }
        }

        // NORTH
        if (x > 0 && map[x-1][y] != wall_stone && map[x-1][y] != wall_dirt && !visited[x-1][y] && current.condition != 2) {
            newnode.x = x-1;
            newnode.y = y;
            newnode.condition = 0;
            newnode.token = current.token;
            newnode.count = current.count+1;
            queue.push_back(newnode);
        }
        // SOUTH
        if (x < xlimit-1 && map[x+1][y] != wall_stone && map[x+1][y] != wall_dirt && !visited[x+1][y] && current.condition != 2) {
            newnode.x = x+1;
            newnode.y = y;
            newnode.condition = 0;
            newnode.token = current.token;
            newnode.count = current.count+1;
            queue.push_back(newnode);
        }
        // WEST
        if (y > 0 && map[x][y-1] != wall_stone && map[x][y-1] != wall_dirt && !visited[x][y-1] && current.condition != 1) {
            newnode.x = x;
            newnode.y = y-1;
            newnode.condition = 0;
            newnode.token = current.token;
            newnode.count = current.count+1;
            queue.push_back(newnode);
        }
        // EAST
        if (x < xlimit-1 && map[x][y+1] != wall_stone && map[x][y+1] != wall_dirt && !visited[x][y+1] && current.condition != 1) {
            newnode.x = x;
            newnode.y = y+1;
            newnode.condition = 0;
            newnode.token = current.token;
            newnode.count = current.count+1;
            queue.push_back(newnode);
        }

        if (current.token) {
            // DIG NORTH (condition 1)
            if (x > 1 && map[x-2][y] == path && map[x-1][y] == wall_dirt && !visited[x-2][y]) {
                newnode.x = x-1;
                newnode.y = y;
                newnode.condition = 1;
                newnode.token = current.token-1;
                newnode.count = current.count+1;
                queue.push_back(newnode);
            }
            // DIG SOUTH (condition 1)
            if (x < xlimit-2 && map[x+2][y] == path && map[x+1][y] == wall_dirt && !visited[x+2][y]) {
                newnode.x = x+1;
                newnode.y = y;
                newnode.condition = 1;
                newnode.token = current.token-1;
                newnode.count = current.count+1;
                queue.push_back(newnode);
            }
            // DIG WEST (condition 2)
            if (y > 1 && map[x][y-2] == path && map[x][y-1] == wall_dirt && !visited[x][y-2]) {
                newnode.x = x;
                newnode.y = y-1;
                newnode.condition = 2;
                newnode.token = current.token-1;
                newnode.count = current.count+1;
                queue.push_back(newnode);
            }
            // DIG WEST (condition 2)
            if (y < ylimit-2 && map[x][y+2] == path && map[x][y+1] == wall_dirt && !visited[x][y+2]) {
                newnode.x = x;
                newnode.y = y+1;
                newnode.condition = 2;
                newnode.token = current.token-1;
                newnode.count = current.count+1;
                queue.push_back(newnode);
            }
        }
    }

    

}

int main () {

    int n,m;
    int xstart , ystart , xend , yend;
    cin >> n >> m;
    cin >> xstart >> ystart >> xend >> yend;

    xlimit = n;
    ylimit = m;

    //string *map   = (string *)malloc(n * sizeof(string));

    char **map = (char **)malloc(n * sizeof(char *));
    int **visited = (int **)malloc(n * sizeof(int *));

    for (int i=0 ; i<n ; i++) {
        visited[i] = (int *)malloc(m * sizeof(int));
        map[i]     = (char *)malloc(m * sizeof(char));
    }

    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<m ; j++) {
            scanf("%c",&map[i][j]);
        }
    }

    
    BFS(map , xstart-1 , ystart-1 , xend-1 , yend-1 , visited);
    if (res == 10000000) cout << -1 << endl;
    else cout << res << endl;
    
    return 0;
}