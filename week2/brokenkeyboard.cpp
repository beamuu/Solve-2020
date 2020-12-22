#include <iostream>
#include <stack>
using namespace std;

int main() {
    

    string mystring[100000];

    while (1) {

        cin >> mystring;
        if (mystring[0] == EOF) {
            break;
        }
        cout << mystring << " =="<< mystring.length()  << endl;
    }
    return 0;
}
