#include <iostream>
#include <list>
using namespace std;

int main() {

    int n,index,tmp;
    char command[2];
    cin >> n;

    list<int> tube;
    list<int>::iterator p; 

    while (n--) {
        
        cin >> command;
        if (command[0] == 'l' && command[1] == 'i') {
            cin >> index;
            tube.push_front(index);
        }
        else if (command[0] == 'r' && command[1] == 'i') {
            cin >> index;
            tube.push_back(index);
        }
        else if (command[0] == 'l' && command[1] == 'r') {
            tmp = *(tube.begin());
            tube.push_back(tmp);
            tube.pop_front();
        }
        else if (command[0] == 'r' && command[1] == 'r') {
            p = tube.end();
            p--;
            tmp = *p;
            tube.push_front(tmp);
            tube.pop_back();
        }
    }
    
    for (p=tube.begin() ; p!=tube.end(); p++) {
        cout << *p << '\n';
    }
    return 0;
}