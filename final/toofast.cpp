#include <iostream>
#include <vector>
// #include <limits.h>
#define _MAX 999999
using namespace std;


typedef struct edge_structure { int from,destination,time, highway; } edge;

int n,m;

// Stores edges
vector<edge> e[1001];

// Stores edge's degree
int deg[1001];

// For memoization
int mem[1001][2];


void init() {

    int from , to , time , highway;
    edge edge_value;
    for (int i=0 ; i<m ; i++) {
        cin >> from >> to >> time >> highway;
        deg[from]++;

        edge_value.from = from;
        edge_value.destination = to;
        edge_value.time = time;
        edge_value.highway = highway;

        e[from].push_back(edge_value);
    }
}

int solve(int current , int highwayAvailable) {
    
    int recursionResult;
    int leastTimeOption = _MAX;
    edge next;

    if (current == n)
        return 0;
    
    if (mem[current][highwayAvailable])
        return mem[current][highwayAvailable];

    for (int v=0 ; v<deg[current] ; v++) {
        next = e[current][v];

        // Case: Highway found and still have a ticket.
        if (next.highway && highwayAvailable)
            recursionResult =  next.time + solve(next.destination , 0);

        // Case: Highway found but no ticket left.
        else if (next.highway) 
            continue;

        // Case: Normal road found.
        else
            recursionResult = next.time + solve(next.destination , highwayAvailable);

        // Update leastTimeOption if the duration id less than before.
        if (recursionResult < leastTimeOption)
            leastTimeOption = recursionResult;
    }
    mem[current][highwayAvailable] = leastTimeOption;
    return leastTimeOption;
}


int main(void) {

    int result;
    cin >> n >> m;
    init();
    result = solve(1,1);
    cout << (result == _MAX ? -1 : result) << endl;
    return 0;
}