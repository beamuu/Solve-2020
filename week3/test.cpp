#include <iostream>
#include <list>
using namespace std;

list <int> test[100];
list <int>::iterator it;
int main() {
    test[1].push_back(100);
    test[2].push_back(1000);
    for (int i=0 ; i<10 ; i++) {
        for (auto it=test[i].begin() ; it!=test[i].end() ; it++) {
            cout << *it << endl;
        }
    }
}
