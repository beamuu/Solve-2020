#include <iostream>
#include <vector>
#include <list>
using namespace std;

const int MAX_N = 100001;

vector<int> adj[MAX_N];
list<int> queue;

int visited[MAX_N];
int discovered[MAX_N];
int degree[MAX_N];
int island=1;
int ind=0;

void BFS(int start) {
    
    int current , node , maximum_loops = MAX_N;
    // Prepare to start BFS.
    queue.push_back(start);
    //            
    while (!queue.empty()) {

        current = queue.front();
        queue.pop_front();
        visited[current] = 1;
        discovered[current] = island;
        for (int i=0 ; i<degree[current] ; i++) {
            node = adj[current][i];
            if (!visited[node]) {
                queue.push_back(node);
            }
        }
        
    }
    return;

}
int main() {
    
    int n , m , k , start , destination;
    scanf("%d %d %d" , &n , &m , &k);

    while (m--) {

        scanf("%d %d" , &start , &destination);

        adj[start].push_back(destination);
        adj[destination].push_back(start);

        degree[start]++;
        degree[destination]++;

    }
    for (int i=1 ; i<MAX_N ; i++) {
        if (!discovered[i]) {
            BFS(i);
            island++;
        }
    }
    while (k--) {
        scanf("%d %d" , &start , &destination);
        if (discovered[start] == discovered[destination]) {
            printf("1\n");
        }
        else {
            printf("0\n");
        }
    }
    return 0;
}