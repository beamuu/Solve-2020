#include<bits/stdc++.h>

using namespace std;

int parent[100100];

typedef struct edge
{

    int from;
    int to;
    int w;

    bool operator<(const edge &o) const
    {
        if (w != o.w)
            return w > o.w;
        return from < o.from;
    }
}edge;

priority_queue <edge> s;

int sum_weight=0;
int c=0;


int _find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = _find(parent[x]);
}

void _union(int a, int b)
{
    parent[_find(b)] = _find(a);
}

void init(int n, int m)
{
    int a, b, w;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        edge e = {a, b, w};
        s.push(e);
    }
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }
}
void mst(int n)
{
    edge e;
    while (!s.empty())
    {
        e = s.top();
        s.pop();
        //printf("%d %d %d\n",e.to,e.from,e.w);
        if (_find(e.to) == _find(e.from))
        {
            continue;
        }
        else
        {
            _union(e.to,e.from);
        }
        sum_weight += e.w;
    }
}

int main()
{

    int n, m;
    cin >> n >> m;

    init(n, m);

    mst(n);
    cout << sum_weight << endl;
    return 0;
}