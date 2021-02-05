#include <iostream>
#include <vector>
#include <list>
#include <cmath>

using namespace std;

struct node {int name,x,y;};

list <int> queue;
vector <int> graph[1002];
node nds[1002];
int deg[1002];
int dist[1002];
int visited[1002];

node createNode(int name , int x , int y) {
    node newnode; newnode.name = name; newnode.x = x; newnode.y = y;
    return newnode;
}

bool compare(int x1, int y1 , int x2 , int y2 , int radius) {
    int sq_of_x = (x1-x2)*(x1-x2);
    int sq_of_y = (y1-y2)*(y1-y2);
    //printf("%d [%d %d %d %d]=====[] %d\n" , sq_of_x + sq_of_y ,x1 , y1 , x2 , y2, radius*radius);
    if (sq_of_x + sq_of_y <= radius*radius) return true;
    return false;
}

void init(int nodes, int r) {

    int x , y , name=1;
    
    nds[0] = createNode(0,0,0);
    while (nodes--) {
        cin >> x >> y;


        nds[name] = createNode(name,x,y);
        for (int i=0 ; i<name ; i++) {
            //printf("name: (%d) =>?? (%d)" , name , i);
            if (compare(x,y,nds[i].x,nds[i].y,r)) {
                graph[name].push_back(nds[i].name);
                graph[nds[i].name].push_back(name);
                
                deg[name]++;
                deg[nds[i].name]++;
            }
        }
        name++;
    }
    nds[name] = createNode(name,100,100);
    for (int i=0 ; i<name ; i++) {
        //printf("name: (%d) =>?? (%d)" , name , i);
        if (compare(100,100,nds[i].x,nds[i].y,r)) {
            graph[name].push_back(nds[i].name);
            graph[nds[i].name].push_back(name);
                
            deg[name]++;
            deg[nds[i].name]++;
        }
    }
}

void BFS() {
    int current , next , layer;
    queue.push_back(0);
    
    while (!queue.empty()) {
        current = queue.front();
        queue.pop_front();
        visited[current] = 1;
        layer = dist[current];
        //printf("node: %d\n" , current);
        for (int i=0 ; i<deg[current] ; i++) {
            next = graph[current][i];
            if (!dist[next] && !visited[next]) {
                dist[next] = layer+1;
                queue.push_back(next);
            }
            
        }   
    }
}

int main () {

    int n , r;
    cin >> n >> r;
    init(n,r);
    BFS();
    if (!dist[n+1]) {
      printf(-1);
    } else printf("%d\n",dist[n+1]);

    return 0;
}