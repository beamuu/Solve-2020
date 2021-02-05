#include <iostream>
using namespace std;

int day[1001];
int all=0;
int today=0;

void input() {
    int patients,p,d;
    cin >> patients;
    
    while (patients--) {
        cin >> p >> d;
        //printf("add: %d to day %d\n" , p , d);
        day[d+today] += p;
        all += p;
    }
}

int main() {

    int n;
    cin >> n;
    while (n--) {
        input();
        all -= day[today];
        cout << all << endl;
        today++;
    }
    return 0;
}