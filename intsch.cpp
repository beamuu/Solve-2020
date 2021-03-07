#include <iostream>
#include <list>
using namespace std;


struct event { 
    int start; 
    int end;
    int duration;
    bool operator<( const event & o) const {
        if (end != o.end) return end < o.end;
    } 
};

list <event> l;

int main() {
    
    int n;
    int start,end;
    int period[2] = {0,0};
    int result=0;

    cin >> n;

    while (n--) {
        
        cin >> start >> end;
        event new_event = {start,end,end-start};
        l.push_back(new_event);
        
    }
    l.sort();
    for (list<event>::iterator i=l.begin() ; i!=l.end() ; i++) {
        //printf("%d %d %d\n",i->start,i->end,i->duration);
        if (i->start < period[1]) {
            continue;
        }
        else {
            result++;
            period[0] = i->start;
            period[1] = i->end;
        }
    }
    cout << result << endl;
    return 0;
}