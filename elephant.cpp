#include <iostream>
using namespace std;

int sequence[100000];
int mem[100000];
int res;
int global_n;

int solve(int k)
{
    //cout << "recurse at " << k << endl;
    int res;
    
    if (k >= global_n)
        return 0;
    if (mem[k])
        return mem[k];
    else
    {
        if (k < 2) 
        {
            res = solve(k+1);
        }
        else {
            res = max( solve(k + 1) , sequence[k] + solve(k + 3));
            mem[k] = res;
        }
        return res;
    }
}

int main()
{
    int n;
    cin >> n;
    global_n = n;
    int point;
    for (int i = 0; i < n; i++)
        cin >> sequence[i];
    res = solve(0);
    cout << res << endl;
    return 0;
}
