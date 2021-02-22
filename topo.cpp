#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector <int> graph[100001];
list   <int> queue;
list   <int> result;
list   <int>:: iterator it;

int visited [100001];
int degIn   [100001];
int degOut  [100001];

int nodes;



void ShowResult() {
    for (it = result.begin() ; it != result.end() ; it++) {
        cout << *it << endl;
    }
    return;
}


void makeGraph(int from , int to) {
    // create edge.
    graph[from].push_back(to);
    degOut[from]++;
    degIn[to]++;
    return;
}


void init(int n, int m) {
    // get edges input 
    int from , to;
    while (m--) {
        cin >> from >> to;
        makeGraph(from ,to);
    }
    return;
}


void BFS_INIT() {
    // push degIn = 0 in queue for starting BFS
    for (int i=1 ; i<nodes ; i++) {
        if (degIn[i] == 0) {
            queue.push_back(i);
        }
    }
    return;
}

bool BFS() {
    // BFS check for topological sort.
    int current,next;
    int loopStatus=0;
    while (!queue.empty()) {

        loopStatus = 1;

        current = queue.front();
        queue.pop_front();

        if (!visited[current]) result.push_back(current);
        visited[current] = 1;
        //printf("do: %d",current);
        
        for (int i=0 ; i< degOut[current] ; i++) {
            next = graph[current][i];
            if (degIn[next] == 0) {
                return false;
            }
            queue.push_back(next);
            degIn[next]--;
        }
        
    }
    if (loopStatus) return true;
    else return false;
}


int main() {
    int n,m;
    bool topo;
    cin >> n >> m;
    nodes = n+1;
    init(n,m);
    BFS_INIT();
    topo = BFS();
    if (topo) ShowResult();
    else cout << "no" << endl;
    return 0;
}