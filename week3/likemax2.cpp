#include <iostream>
#include <map>
using namespace std;

map <int,int> status;
int maxLike=0;
int maxStatus;
int main() {
    
    int n , statusName , like;
    cin >> n;

    while (n--) {
        cin >> like >> statusName;
        if (like) {
            status[statusName] += 1;
        }
        else {
            status[statusName] -= 1;
        }

        if (status[statusName] >= maxLike) {
            maxLike = status[statusName];
            maxStatus = statusName;
            cout << statusName << endl;
        }
        else {
            cout << maxStatus << endl;
        }
    }
}
