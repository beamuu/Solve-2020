#include <iostream>
#include <vector>
#include <list>
using namespace std;

const int MAX_N = 100001;

vector<int> adj[MAX_N];
list<int> queue;

int visited[MAX_N];
int degree[MAX_N];
int timestamp=0;

int input() {
    
    int n , m , k , start , destination;
    cin >> n >> m >> k;

    while (m--) {

        cin >> start >> destination;

        adj[start].push_back(destination);
        adj[destination].push_back(start);

        degree[start]++;
        degree[destination]++;

    }
    return k;
}

int BFS(int start , int destination) {

    int current , node , maximum_loops = MAX_N;
    // Prepare to start BFS.
    timestamp++;
    queue.push_back(start);
    //                  
    while (!queue.empty() && maximum_loops--) {

        current = queue.front();
        queue.pop_front();

        if (current == destination) {
            return 1;
        }

        visited[current] = timestamp;

        for (int i=0 ; i<degree[current] ; i++) {

            node = adj[current][i];
            if (visited[node] != timestamp) {
                queue.push_back(node);
            }

        }
        
    }
    return 0;
}

int main() {

    int start , destination , result;
    int k = input();

    while (k--) {
        cin >> start >> destination;
        result = BFS(start , destination);
        cout << result << endl;
        queue.clear();
    }
    return 0;
}