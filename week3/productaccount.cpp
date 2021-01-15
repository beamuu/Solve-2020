#include <iostream>
#include <map>
using namespace std;

map <int , int> product;

void process(int command , int productName) {

    int amount;
    if (command == 1) {
        cin >> amount;
        product[productName] += amount;
    }
    else if (command == 2) {
        cout << product[productName] << endl;
    }
    else {
        cin >> amount;
        if (product[productName] >= amount) {
            cout << amount << endl;
            product[productName] -= amount;
        }
        else {
            cout << product[productName] << endl;
            product[productName] = 0;
        }
    }
    return;
}


int main() {

    int n , command , productName;
    cin >> n;

    while (n--) {
        cin >> command >> productName;
        process(command , productName);
    }

    return 0;
}
