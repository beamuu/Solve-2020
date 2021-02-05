#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector <int> graph[100001];
list   <int> queue;

int degree  [100001];
int color   [100001];
int visited [100001];
int startNode;

void init() {
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    while (m--) {
        scanf ("%d %d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);

        degree[u]++;
        degree[v]++;
    }
    startNode = u;
}

void clearAll() {
    queue.clear();
    for (int i=0 ; i<100001 ; i++) {
        graph[i].clear();
        degree[i] = 0;
        color[i] = 0;
        visited[i] = 0;
    }
}

bool bipartite() {
    
    int current,next;
    bool markcolor = false;
    color[startNode] = 1;
    queue.push_back(startNode);
    while (!queue.empty()) {
        current = queue.front();
        queue.pop_front();
        visited[current] = 1;
        

        for (int i=0 ; i<degree[current] ; i++) {
            next = graph[current][i];

            if (!color[next]) {
                if (markcolor)      {color[next] = 1;}
                else                {color[next] = 2;}
            }
            if (visited[next] && color[next] == color[current]) {
                // printf("Found node (%d) -> (%d) with color (%d)(%d)\n" ,  current , next , color[current] , color[next]);
                return false;
            }
            
            
            
            if (visited[next] && color[next] == color[current]) {
                // printf("Found node (%d) -> (%d) with color (%d)(%d)\n" ,  current , next , color[current] , color[next]);
                return false;
            }
            if (!visited[next]) {
                queue.push_back(next);
            }
            markcolor = !markcolor;
        }
        
        
    }
    return true;
}

int main () {

    int g,n,m,u,v;
    bool result;
    cin >> g;

    while (g--) {
        init();
        result = bipartite();
        if (result) printf("yes\n");
        else printf("no\n");

        clearAll();

    }
}