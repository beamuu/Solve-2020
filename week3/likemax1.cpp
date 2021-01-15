#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map <int,int> m;
int maxLike=0;
int maxPost;

int main() {
    
    int n , post;
    cin >> n;

    while (n--) {
        cin >> post;
        m[post] += 1;
        if (m[post] >= maxLike) {
            cout << post << endl;
            maxLike = m[post];
            maxPost = post;
        }
        else {
            cout << maxPost << endl;
        }

    }
    return 0; 

}
