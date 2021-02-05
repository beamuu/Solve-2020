#include <iostream>
#include <vector>
#include <list>
using namespace std;




struct node {int name,dist;};
list <node> q;
vector <int> graphr [50001];
vector <int> graphb [50001];
int degreer [50001];
int degreeb [50001];
int visitedb[50001];
int visitedr[50001];
int res = 1000000;




void init(int m) {

    int a , b , c;
    while (m--) {
        cin >> a >> b >> c;
        if (c == 0) {
            graphb[a].push_back(b);
            graphb[b].push_back(a);
            graphr[a].push_back(b);
            graphr[b].push_back(a);
            degreer[a]++;
            degreer[b]++;
            degreeb[a]++;
            degreeb[b]++;
        }
        else if (c == 1) {
            graphr[a].push_back(b);
            graphr[b].push_back(a);
            degreer[a]++;
            degreer[b]++;
        }
        else if (c == 2) {
            graphb[a].push_back(b);
            graphb[b].push_back(a);
            degreeb[a]++;
            degreeb[b]++;
        }
        
    
    }
}

void BFSR(int s , int t) {
    node startnode;
    startnode.name = s;
    startnode.dist = 0;
    q.push_back(startnode);
    node current,next;
    while (!q.empty()) {
        current = q.front();
        q.pop_front();
        if (current.name == t) {
            if (current.dist < res) {
                res = current.dist;
                return;
            }
        }
        visitedr[current.name] = 1;
        for (int i=0 ; i<degreer[current.name] ; i++) {
            next.name = graphr[current.name][i];
            next.dist = current.dist+1;
            if (!visitedr[next.name]) {
                q.push_back(next);
            }
        }        
    }
}
// ========================================
void BFSB(int s , int t) {
    node startnode;
    startnode.name = s;
    startnode.dist = 0;
    q.push_back(startnode);
    node current,next;
    while (!q.empty()) {
        current = q.front();
        q.pop_front();
        if (current.name == t) {
            if (current.dist < res) {
                res = current.dist;
                return;
            }
        }
        visitedb[current.name] = 1;
        for (int i=0 ; i<degreeb[current.name] ; i++) {
            next.name = graphb[current.name][i];
            next.dist = current.dist+1;
            if (!visitedb[next.name]) {
                q.push_back(next);
            }
        }        
    }
}

int main() {
    
    int n , m , s , t;
    cin >> n >> m >> s >> t;
    
    init(m);
    BFSR(s,t);
    q.clear();
    //printf("=======================================================\n");
    BFSB(s,t);
/*
    for (int i=0 ; i<10; i++) {
        printf("[%d] -> " , i);
        for (int j=0 ; j<degree[i] ; j++) {
            printf("%d(%d) ",graph[i][j].name , graph[i][j].color);
        }
        printf("\n");
    }
*/

    cout << res << endl;
    
}