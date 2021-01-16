#include <iostream>
#include <set>
#include <map>
using namespace std;
set <int> cummulativePrice;
set <int>::iterator it;
map <int,int> priceHash;

int main() {

    int n,k;
    cin >> n >> k;

    int bookPrice , sum=0 , bookNumber=1 , money , totalPrice;

    while (n--) {
        cin >> bookPrice;
        sum += bookPrice;
        cummulativePrice.insert(sum);
        priceHash[sum] = bookNumber;

        bookNumber++;

    }

    while (k--) {
        cin >>  money;
        it = cummulativePrice.lower_bound(money);
        if (it == cummulativePrice.begin() && money < *it) {
            cout << 0 << endl;
            continue;
        }
        if (*it == money) {
            totalPrice = money;
        }
        else {
            it--;
            totalPrice = *it;
        }
        cout << priceHash[totalPrice] << endl;
    }
    return 0;
}
