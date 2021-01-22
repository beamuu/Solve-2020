#include <iostream>
#include <list>
using namespace std;

list <int> stack;
list <int> a;
list <int> objective;
list <int>::iterator pt;
void solve(int n) {
    
    for (int i=1 ; i<=n ; i++) a.push_back(i);

    int train,exit=0,result;
    int arriveTrain;
    while (true) {

        result = 0;
        for (int i=0 ; i<n ; i++) {
            cin >> train;
            if (train == 0) {
                exit = 1;
                break;
            }
            objective.push_back(train);
        }
        if (exit) break;

        pt = objective.begin();
        while (true) {
            
            if (pt == objective.end()) {
                result = 1;
                break;
            }
            if (a.size() == 0 && pt != objective.end()) {
                
                if (*(stack.begin()) == *pt) {
                    pt++;
                    stack.pop_front();
                    continue;
                }
                else {
                    break;
                }
            }

            arriveTrain = *(a.begin());
            stack.push_front(arriveTrain);
            a.pop_front();

            if (*(stack.begin()) == *pt) {
                pt++;
                stack.pop_front();
            }
            
        }
        if (result) cout << "yes" << endl;
        else cout << "no" << endl;
        objective.clear();
        stack.clear();
        
    }
    return;
}


int main() {
    
    int n;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        else {
            solve(n);
            a.clear();
        }
        cout << endl;
    }
}
