#include <iostream>
using namespace std;

int main() {
    
    int n,k;
    cin >> n >> k;
    
    int lib[n];
    int count=0;
    int input;
    for (int i=0 ; i<n ; i++) {
        cin >> lib[i];
    }

    while (k--) {
        cin >> input;
        for (int i=0 ; i<n ; i++) {
            if (input-lib[i] < 0) {
                cout << count << endl;
                break;
            }
            else {
                input -= lib[i];
                count++;
            }
        }
        count = 0;
    }
    return 0;


}
