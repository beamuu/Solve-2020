#include <iostream>
#include <vector>
#include <list>
#define INF 9999
using namespace std;

struct node
{
    int name;
    int w;
};

vector<node> g[100001];
list<int> q;

int d[100001];
int deg[100001];
int visited[100001];

void init(int n, int m)
{

    int from, to, w;
    node a;
    node b;

    for (int i = 0; i < m; i++)
    {
        cin >> from >> to >> w;

        d[from] = INF;
        d[to] = INF;

        node a = {to, w};
        deg[from]++;
        deg[to]++;
        g[from].push_back(a);
        node b = {from, w};
        g[to].push_back(b);
    }
}

void shortestPath(int src, int n)
{
    d[1] = 0;
    int current, next, min, min_node;
    node nextnode;
    int timeout = 30;
    q.push_back(src);
    while (!q.empty())
    {

        current = q.front();
        q.pop_front();
        visited[current] = 1;
        min = INF;
        //printf("src: %d\n",current);
        for (int i=0; i<deg[current]; i++)
        {
            
            nextnode = g[current][i];
            //printf("    - check node %d\n",nextnode.name);

            if (d[current]+nextnode.w < d[nextnode.name])
            {
                d[nextnode.name] = d[current] + nextnode.w;
                q.push_back(nextnode.name);
            }

            // if (!visited[nextnode.name])
            // {
            //     if (nextnode.w < min)
            //     {
            //         min_node = nextnode.name;
            //         min = nextnode.w;
            //     }
            // }
        }
        // if (min < INF) 
        // {
        //     //printf("    - choose node %d with weight %d\n", min_node , min);
        //     q.push_back(min_node);
        // }
    }
}

int main()
{

    int n, m;
    cin >> n >> m;
    init(n, m);
    shortestPath(1, n);
    printf("%d\n",d[n]);
    return 0;
}