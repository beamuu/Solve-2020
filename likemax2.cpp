#include <iostream>
#include <queue>
#include <map>
using namespace std;

typedef struct POST {
    int postName;
    int postLike;
    int timestamp;
    bool operator<( const POST & o) const {
        if (postLike != o.postLike) return postLike < o.postLike;
        else if (timestamp != o.timestamp) return timestamp < o.timestamp;
    }
} post;

int Array[100001];
int lastIndex=1;
priority_queue <post> heap;
map <int,int> m;

int main() {

    int n;
    int like,postName,timestamp=0;
    cin >> n;

    while (n--) {
        cin >> like >> postName;
        if (m[postName] == 0) {
            m[postName] = lastIndex;
            lastIndex++;
        }
        
        if (like) {
            Array[m[postName]] += 1;
        }
        else {
            Array[m[postName]] -= 1;
        }
        post newpost;
        newpost.postName = postName;
        newpost.postLike = Array[m[postName]];
        newpost.timestamp = timestamp;
        heap.push(newpost);
        while (1) {
            if (heap.top().postLike == Array[m[heap.top().postName]]) {
                cout << heap.top().postName << endl;
                break;
            }
            else {
                heap.pop();
            }
        }
        timestamp++;
    }
    return 0;
}
