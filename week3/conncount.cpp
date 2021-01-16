#include <iostream>
#include <set>
#include <list>
using namespace std;

list <int> path[100001];
list <int>::iterator it;
set <int> s;
int graph=0;
int *mark = (int *)malloc(sizeof(int)*100001);


void solve(int current) {
    
    // cout << "loop in to: " << current << endl;
    s.erase(current);
    mark[current] = 1;
    if (path[current].size() == 0) return;
    for (auto i=path[current].begin() ; i!=path[current].end() ; i++) {
        // cout << *it << endl;
        if (!mark[*i]) solve(*i);
    }
    return;
}

int main() {
    
    int n,m;
    int node1,node2;
    int current=1;
    cin >> n >> m;
    for (int i=1 ; i<=n ; i++) {
        s.insert(i);
    }
    while (m--) {   
        cin >> node1 >> node2;
        path[node1].push_back(node2);
        path[node2].push_back(node1);
    }

    while (s.size() != 0) {
        solve(current);
        graph++;
        current = *(s.begin());
    }
    cout << graph << endl;
    return 0;


}
