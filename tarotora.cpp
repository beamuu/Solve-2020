#include <iostream>
using namespace std;

int a[100000];
int b[100000];
int mem[100000];

int N, K;

void init()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i] >> b[i];
    }
}

int solve(int n, int k, int c1, int c2)
{
    // c1 : Taro count (a) , c2 : Tora count (b)
    int result;
    if (n > N)
        return 0;
    if (abs(c1 - c2) == k)
    {
        if (c1 < c2)
            return a[n] + solve(n + 1, k, c1 + 1, c2);
        else
            return b[n] + solve(n + 1, k, c1, c2 + 1);
    }
    if (mem[n])
        return mem[n];

    result = min(
        a[n] + solve(n + 1, k, c1 + 1, c2),
        b[n] + solve(n + 1, k, c1, c2 + 1));
    mem[n] = result;
    return result;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        init();
        cout << solve(0, K, 0, 0) << endl;
        for (int i = 0; i < 100000; i++)
        {
            mem[i] = 0;
        }
    }
    return 0;
}
