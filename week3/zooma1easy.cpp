#include <iostream>
#include <list>
#include <utility>
#include <algorithm>
using namespace std;

list< pair<int,int> > l;
list< pair<int,int> >::iterator it;


void searchFor(int ballName) {
    for (auto i=l.begin() ; i!=l.end() ; i++) {
        if (i->first == ballName) {
            it = i;
            return;
        }
    }
}

void print(const pair<int,int> &ballPair) {
    cout << ballPair.first << endl;
}


int main() {

    int n,m,color,ball;
    cin >> n >> m;
    for (int i=1 ; i<=n ; i++) {
        cin >> color;
        l.push_back( make_pair(i,color) );
    }

    for (int i=1 ; i<=m ; i++) {
        cin >> color >> ball;
        searchFor(ball);
        l.insert(++it,make_pair(n+i,color));
    }
    for_each(l.begin() , l.end() , print);
    return 0;
}

