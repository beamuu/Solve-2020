#include <iostream>
#include <set>
using namespace std;

int main() 
{
    
    set<int> myset;
    set<int>::iterator it;
    int n,m,x;
    int left,right;
    cin >> n >> m;
    

    while (n--) {
        cin >> x;
        myset.insert(x);
    }
    while (m--) {
        cin >> x;
        if (*(--myset.end()) <= x) {
            cout << *(--myset.end()) << endl;
        }
        else {
            it = myset.lower_bound(x);
            if (x == *(it)) {
                cout << x << endl;
                continue;
            }
            left = *(--it);
            it++;
            right = *it;
            if (x-left < right-x) {
                cout << left << endl;
            } else {
                cout << right << endl;
            }
            
        }
    }

    return 0;
}


