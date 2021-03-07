#include <iostream>
#include <list>
using namespace std;

struct work { 
    int duration; 
    int due_date;
    bool operator<( const work & o) const {
        if (due_date != o.due_date) return due_date < o.due_date;
    } 
};

list <work> l;

int main() {

    int n;
    int duration , due_date , date=0 , max=0;
    int paid;

    cin >> n;

    while (n--) {

        cin >> due_date >> duration;
        work newwork = {duration , due_date};
        l.push_back(newwork);

    }
    l.sort();
    for (auto i=l.begin() ; i!=l.end() ; i++) {

        date += i->duration;
        if (date-(i->due_date)-10 > 0) {
            paid = (date-i->due_date-10) * 1000;
            if (paid > max) {
                max = paid;
            }
        }
    }
    cout << max << endl;
    return 0;
}