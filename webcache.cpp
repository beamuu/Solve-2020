#include <iostream>
#include <list>
#include <map>
using namespace std;

list<int> l;
map<int,int> m;

int main() {
    
    int n,mm,request,misses=0;
    cin >> n >> mm;

    while (mm--) {
        cin >> request;
        if (m[request] == 0) {
            // misses
            misses++;
            m[request] = 1;
            if (l.size() == n) {
                m[*(l.begin())] = 0;
                l.pop_front();
            }
            l.push_back(request);
        }
    }
    cout << misses << endl;
    return 0;
}
