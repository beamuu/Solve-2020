#include <iostream>
#include <list>
using namespace std;

typedef struct ball { int name , color; } node; 
list <node> l;
list <node>::iterator it;
list <node>::iterator decoy;

int main() {

    // Declaration
    int n,m;
    int name=1 , color , front;
    cin >> n >> m;
    int *exist = (int *)malloc(sizeof(int)*(m+n+1));
    bool done=false;

    // Process
    while (n--) {
        cin >> color;
        node newnode;
        newnode.name = name;
        newnode.color = color;
        l.push_back(newnode);
        exist[name]=1;
        name++;
    }
    while (m--) {
        cin >> color >> front;
        if (!exist[front]) { name++ ; continue; }
        node newnode;
        newnode.name = name;
        newnode.color = color;
        for (it = l.begin() ; it != l.end() ; it++) {
            if (it->name == front) {

                if (it->color == color && (++it)->color == color) {
                    while (it->color != color) {
                        decoy = it;
                        l.erase(decoy);
                        it++;
                    }
                }

                else { it++ ; l.insert(it , newnode); }
                done = true;
            }
            if (done) { done=false ; break; }
        }
    }
    for (it=l.begin() ; it!=l.end() ; it++) { cout << it->name << '\n';}
    return 0;
}
