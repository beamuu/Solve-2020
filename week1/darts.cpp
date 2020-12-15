#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    int N , score=0;
    int x , y;
    cin >> N;

    while (N--) {
        cin >> x >> y;
        if (sqrt(pow(x,2)+pow(y,2)) <= 2) {
            score += 5;
        }
        else if (sqrt(pow(x,2)+pow(y,2)) <= 4) {
            score += 4;
        }
        else if (sqrt(pow(x,2)+pow(y,2)) <= 6) {
            score += 3;
        }
        else if (sqrt(pow(x,2)+pow(y,2)) <= 8) {
            score += 2;
        }
        else if (sqrt(pow(x,2)+pow(y,2)) <= 10) {
            score += 1;
        }
    }
    cout << score << endl;
    return 0;
}