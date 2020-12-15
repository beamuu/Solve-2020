
// NOT SEND YET !!!!!!!!!!!!!!!!

#include <iostream>
using namespace std;


int main(void) {
    
    int L,N;
    cin >> L >> N;
    
    int start , end;
    int *road = (int *)calloc(L*2 , sizeof(int));
    int max = 0;

    while (N--) {
        cin >> start >> end;
        //start--; end --;

        for (int i=2*start+1 ; i<2*end ; i++) {
            road[i]++;
            if (road[i] > max) {
                max = road[i];
            }
        }
    }
    cout << max << endl;
    return 0;
}