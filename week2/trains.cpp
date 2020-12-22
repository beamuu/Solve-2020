#include <iostream>
#include <list>
using namespace std;


list <int> lib[100000];
int main() {

    char command;
    int t,num1,num2;

    list<int>::iterator it;
    cin >> t;
    while (t--) {

        cin >> command >> num1 >> num2;
        if (command == 'N') {
            lib[num2-1].push_back(num1);
        }
        else {
            it = lib[num2-1].end();
            lib[num2-1].splice(it,lib[num1-1]);
        }

    }
    for (int i=0 ; i<100000 ; i++) {
        for (it=lib[i].begin() ; it!=lib[i].end() ; it++) {
            cout << *it << "\n";
        }
    }
    return 0;
}