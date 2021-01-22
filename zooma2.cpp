#include <iostream>
#include <list>
using namespace std;

int main() {

    list <int> l;
    list <int>::iterator it;
    l.push_back(10);
    l.push_back(100);
    l.push_back(1000);
    l.push_back(10000);

    it = l.begin();
    it++;
    cout << *it << endl;
    l.remove(100);
    cout << *it << endl;
    it++;
    cout << *it << endl;
    for (it = l.begin() ; it!=l.end() ; it++) cout << *it << ' ';
    return 0;
}
