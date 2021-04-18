#include <iostream>
using namespace std;

int sequence[100000];
int LIS[100000];
int N_GLOBAL;
int MAX_LIS=0;

void init(int n)
{
    for (int i = 0; i < n; i++) 
    {
        cin >> sequence[i];
        LIS[i] = 1;
    }
}

void solve() 
{
    for (int i=0 ; i<N_GLOBAL ; i++)
    {  
        for (int j=0 ; j<i ; j++)
        {
            if (sequence[i] > sequence[j] && LIS[j]+1 > LIS[i]) 
            {
                LIS[i] = LIS[j]+1;
            }
        }
        if (LIS[i] > MAX_LIS)
            MAX_LIS = LIS[i];
    }
}
void show() 
{
    int valueOfLIS=1;
    cout << MAX_LIS << endl;
    for (int i=0 ; i<N_GLOBAL ; i++)
    {
        if (LIS[i] == valueOfLIS)
        {
            cout << sequence[i] << " ";
            valueOfLIS++;
        }
    }
    cout << endl;
}
// void show2() {

//     cout << "LIS: ";
//     for (int i=0 ; i<N_GLOBAL ; i++) {
//         cout << LIS[i] << " ";
//     }
//     cout << endl;
//     cout << "NUM: ";
//     for (int i=0 ; i<N_GLOBAL ; i++) {
//         cout << sequence[i] << " ";
//     }
//     cout << endl;
// }

int main()
{
    int n;
    cin >> n;
    N_GLOBAL = n;
    init(n);
    solve();
    show();
    return 0;
}