#include <iostream>
#include <list>
#include <cmath>
using namespace std;

typedef struct NODE { int name,xpos,ypos; } node;
list <node> list_of_node;
list <int> queue;
list <node>::iterator it1;
list <node>::iterator it2;
int res=0;
int exit_status = 0;
// 0 = possible
// 1 = impossible

void BFS(int **dir , int *visited , int startNode , int endNode , int n) {
    int exit=false;
    int currentNode, currentLayer=1,nextLayer=0;
    queue.push_back(startNode);
    // printf("BFS searching for %d -> %d\n" , startNode , endNode);
    while (true) {

        if (queue.empty()) { exit_status = 1; break; }
        currentNode = queue.front();
        // printf("Visited node %d\n" , currentNode);
        queue.pop_front();
        // Mark as visited
        visited[currentNode] = 1;
        // Decreament layer.
        currentLayer--;
        // Find The available path(s)
        for (int i=0 ; i<n+2 ; i++) {

            if (currentNode != i && dir[currentNode][i] && !visited[i]) {
                if (i == endNode) {
                    exit = true;
                    break;
                }
                //printf("    Find path from %d to %d\n" , currentNode , i);
                queue.push_back(i);
                nextLayer++;
            }
        }
        //printf("Layer details ==== %d ==== %d ==== %d ====\n",currentLayer,nextLayer,res);
        // Solved.
        if (exit) {
            res++;
            break;
        }
        // Entire Layer discovered.
        if (currentLayer == 0) { currentLayer = nextLayer ; nextLayer = 0; res++; }

    }
    if (exit_status) {
        res = -1;
    }
    return;
}


int main() {

    // Declaration
    int n,r,name=1,nloop;
    int xpos , ypos;
    cin >> n >> r;

    // Mark as visited or unvisited.
    int *visited = (int *)malloc(sizeof(int)*(n+2));
    
    // Insert Start node
    node newnode;
    newnode.name = 0;
    newnode.xpos = 0;
    newnode.ypos = 0;
    list_of_node.push_back(newnode);

    // 2D Array Show Path of each node.
    int **dir = (int **)malloc(sizeof(int *)*(n+2));
    for (int i=0 ; i<n+2 ; i++) { dir[i] = (int *)malloc(sizeof(int)*(n+2)); }
    nloop = n;
    while (nloop--) {
        cin >> xpos >> ypos;
        node newnode;
        newnode.name = name;
        newnode.xpos = xpos;
        newnode.ypos = ypos;
        list_of_node.push_back(newnode);
        name++;
    }

    newnode.name = name;
    newnode.xpos = 100;
    newnode.ypos = 100;
    list_of_node.push_back(newnode);

    // Assign each of the path to all node;

    for (it1 = list_of_node.begin() ; it1 != list_of_node.end() ; it1++) {
        for (it2 = list_of_node.begin() ; it2 != list_of_node.end() ; it2++) {
            if ( pow(it1->xpos-it2->xpos,2)+pow(it1->ypos-it2->ypos,2) <= pow(r,2) ) {
                dir[it1->name][it2->name] = 1;
                dir[it2->name][it1->name] = 1;
            }
        }
    }
    /*
    for (int i=0 ; i<n+2 ; i++) {
        for (int j=0 ; j<n+2 ; j++) {
            cout << dir[i][j];
        }
        cout << '\n';
    }
    */

    // Process
    BFS(dir,visited,0,n+1,n);
    cout << res << endl;
    return 0;
    

}

