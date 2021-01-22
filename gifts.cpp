#include <iostream>
using namespace std;

int main(void) {
    
    int N , item , value=0;
    cin >> N;
    while (N--) {
        cin >> item;
        if (item > 0) value += item;
        cout << value << endl;
    }
    cout << value << endl;
    return 0;
}