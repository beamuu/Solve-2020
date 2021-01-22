#include <iostream>
using namespace std;

int main(void) {
    
    int N , sum=0 , num , op=0;
    char sign='+';
    cin >> N;
    N = 2*N-1;

    while (N--) {
        if (op) {
            cin >> sign;
            op = !op;
            continue;
        }
        else {
            cin >> num;
        }
        if (sign == '+') {
            sum += num;
        }
        else {
            sum -= num;
        }
        op = !op;
    }
    cout << sum;
    return 0;
}