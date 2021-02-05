#include <iostream>
#include <list>

using namespace std;
typedef struct NODE {int x,y;} node;
list <node> q;
list <node> door_await;
int limit;
int door_left=0;
bool found = false;

void Clear(int **m , int n) {
    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<n ; j++) {
            m[i][j] = 0;
        }
    }
}

void BFS(string *maze , int **visited , int xstart , int ystart , int xend , int yend) {
    
    char door = 'O';
    char wall = '#';
    char path = '.';
    int key = 1;
    int try_door = 0;

    node current;
    node newnode; newnode.x = xstart ; newnode.y = ystart;
    q.push_back(newnode);
    
    while (true) {

        if (q.empty()) {
            if (door_await.empty()) { break; }
            else {
                //printf("Door added->");
                try_door = 1;
                q.push_back(door_await.front());
                door_await.pop_front();
            }
        }

        current = q.front();
        q.pop_front();
        visited[current.x][current.y] = 1;
        //printf("pos: %d %d\n" , current.x , current.y);
        if (current.x == xend && current.y == yend) {
            found = true;
            break;
        }

        // North
        if (current.x > 0 && maze[current.x-1][current.y] != wall && !visited[current.x-1][current.y]) {
            //printf("north  (%c)" , maze[current.x-1][current.y]);
            if (maze[current.x-1][current.y] == door) {
                if (try_door) {
                    continue;
                }
                //printf("(door)");
                newnode.x = current.x-1 ; newnode.y = current.y;
                door_await.push_back(newnode);
            }
            else {
                newnode.x = current.x-1 ; newnode.y = current.y;
                q.push_back(newnode);
            }
            //printf("\n");
        }

        // South
        if (current.x < limit-1  && maze[current.x+1][current.y] != wall && !visited[current.x+1][current.y]) {
            //printf("south  (%c)" , maze[current.x+1][current.y]);
            if (maze[current.x+1][current.y] == door) {
                if (try_door) {
                    continue;
                }
                //printf("(door)");
                newnode.x = current.x+1 ; newnode.y = current.y;
                door_await.push_back(newnode);
            }
            else {
                newnode.x = current.x+1 ; newnode.y = current.y;
                q.push_back(newnode);
            }
            //printf("\n");
        }

        // West
        if (current.y > 0 && maze[current.x][current.y-1] != wall && !visited[current.x][current.y-1]) {
            //printf("west  (%c)" , maze[current.x][current.y-1]);
            if (maze[current.x][current.y-1] == door) {
                if (try_door) {
                    continue;
                }
                //printf("(door)");
                newnode.x = current.x ; newnode.y = current.y-1;
                door_await.push_back(newnode);
            }
            else {
                newnode.x = current.x ; newnode.y = current.y-1;
                q.push_back(newnode);
            }
            //printf("\n");
        }

        // East
        if (current.y < limit-1 && maze[current.x][current.y+1] != wall && !visited[current.x][current.y+1]) {
            //printf("east  (%c)" , maze[current.x][current.y+1]);
            if (maze[current.x][current.y+1] == door) {
                if (try_door) {
                    continue;
                }
                //printf("(door)");
                newnode.x = current.x+1 ; newnode.y = current.y+1;
                door_await.push_back(newnode);
            }
            else {
                newnode.x = current.x ; newnode.y = current.y+1;
                q.push_back(newnode);
            }
            //printf("\n");
        }
        //printf("\n");
    }
}

int main() {
    
    int n,kk,r,c,a,b;
    cin >> n >> kk;
    limit = n;
    string *maze = (string *)malloc(n * sizeof(string));
    int **visited = (int **)malloc(n * sizeof(int *));
    for (int i=0 ; i < n ; i++) {
        visited[i] = (int *)malloc(n* sizeof(int));
    }

    for (int i=0 ; i<n ; i++) {
        cin >> maze[i];
    }
    while (kk--) {
        cin >> r >> c >> a >> b;
        BFS(maze , visited , r-1 , c-1 , a-1 , b-1);
        if (found) cout << "yes" << endl;
        else cout << "no" << endl;
        found = false;
        q.clear(); 
        door_await.clear();
        
        Clear(visited,n);
    }
    return 0;
}