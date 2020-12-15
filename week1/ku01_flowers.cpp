#include <iostream>
using namespace std;

int Plant(int L , int N) {
    
    int num = 0 , Add = 1 , res = 0;
    while (1) {

        if (num >= N) {
            return res;
        }
        for (int i=0 ; i<L ; i++) {
            num += Add;
            Add++;
        }
        res++;
    }
}


int main(void) {

    int L , N;
    cin >> L >> N;
    cout << Plant(L,N) << endl;
    return 0;
}
