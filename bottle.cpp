#include <iostream>
#include <queue>
using namespace std;

typedef struct bottle { 
    int name, height; 
    bool operator<(const bottle & o) const {
        return height<o.height;
    }
} node;

int bottleBroke=0;
priority_queue <node> heap;

void destroy(int height , int *broke , int n , int time , int *timestamp) {
    while (!heap.empty() && heap.top().height > height) {
        if (broke[heap.top().name] && timestamp[heap.top().name] != time) { heap.pop() ; continue; }
        if (!broke[heap.top().name]) {
            //printf("%d breaks.\n" , heap.top().name);
            broke[heap.top().name]= 1;
            timestamp[heap.top().name] = time;
            bottleBroke++;
        }
        if (heap.top().name != n && !broke[heap.top().name+1]) {
            //printf("%d breaks.\n" , heap.top().name+1);
            bottleBroke++;
            broke[heap.top().name+1] = 1;
            timestamp[heap.top().name+1] = time;
        }
        if (heap.top().name != 1 && !broke[heap.top().name-1]) {
            //printf("%d breaks.\n" , heap.top().name-1);
            bottleBroke++;
            broke[heap.top().name-1] = 1;
            timestamp[heap.top().name-1] = time;
        }
        heap.pop();
    }
}

int main() {

    int n,m,nloop;
    int height , name=1 , time=1;
    cin >> n >> m;
    nloop = n;
    int *timestamp = (int *)malloc(sizeof(int)*(n+1));
    int *broke = (int *)malloc(sizeof(int)*(n+1));
    while (nloop--) {
        cin >> height;
        node newnode;
        newnode.name = name;
        newnode.height = height;
        heap.push(newnode);
        name++;
    }
    while (m--) {
        cin >> height;
        destroy(height,broke,n,time,timestamp);
        cout << bottleBroke << endl;
        bottleBroke=0;
        time++;
    }
    return 0;
}
