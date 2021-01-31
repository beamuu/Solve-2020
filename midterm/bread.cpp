#include <iostream>
#include <map>
#include <queue>

using namespace std;

map <int,int> map_cost;
map <int,int> map_amount;
const int INF = 100006;


int final_price,final_store;

void update(int challengerPrice , int storeName) {
    if (challengerPrice < final_price) {
        final_price = challengerPrice;
        final_store = storeName;
    }
}

int main() {

    int n,q;
    cin >> n >> q;

    int address , cost , amount , left , right , amount_left , amount_right;
    while (n--) {
        cin >> address >> cost >> amount;
        map_cost[address] = cost;
        map_amount[address] = amount;
    }
    while (q--) {
        cin >> address;
        final_price = INF;
        final_store = -1;
        for (int i=0 ; i<=5 ; i++) {

            left = map_cost[address-i];
            amount_left = map_amount[address-i];

            right = map_cost[address+i];
            amount_right = map_amount[address+i];


            //printf("searching at [%d] << %d >> [%d]\n" , address-i , address , address+i);
            //printf("searching at $%d << %d >> $%d\n" , left , address , right);
            if (left == 0 && right == 0) {
                continue;
            }
            if (amount_left && amount_right) {
                if (left < right) {update(left,address-i);}
                else {update(right,address+i);}            
            }
            else if (amount_left && !amount_right) {
                update(left,address-i);
            }
            else if (!amount_left && amount_right) {
                update(right,address+i);
            }

        }
        if (final_price == INF) {cout << 0 << endl;}
        else {cout << final_price << endl;}
        map_amount[final_store]--;
        //printf("==============================================================\n");

    }
    return 0;
}