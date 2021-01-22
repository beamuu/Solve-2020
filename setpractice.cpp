#include <iostream>
#include <set>
using namespace std;

set <int> s; 
set <int>::iterator it;

int main() {
    
    int n , m , number , pre , post;
    cin >> n >> m;
    while (n--) {
        cin >> number;
        s.insert(number);
    }
    while (m--) {
        cin >> number;
        it = s.lower_bound(number);
        if (it == s.end()) {
            cout << *(--it) << endl;
        }
        else if (*it == number) {
            cout << number << endl;
        }
        else {
            pre = *(--it); it++;
            post = *(it);
            if (number-pre <= post-number) {
                cout << pre << endl;
            }
            else {
                cout << post << endl;
            }
        }
    }
    return 0;
}
