#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {

    int m,num1;
    char command;
    cin >> m;

    list<int> l;
    list<int>::iterator IT;

    while (m--) {

        cin >> command >> num1;
        if (command == 'I') {
            l.push_front(num1);
        }
        else {
            if (l.size() < num1) {
                continue;
            }
            IT = l.begin();
            for (int i=1 ; i<num1 ; i++) {
                IT++;
            }
            l.erase(IT);
        }
    }
    
    for (IT = l.begin() ; IT != l.end() ; IT++) {
        cout << *IT << '\n';
    }
    return 0;

}