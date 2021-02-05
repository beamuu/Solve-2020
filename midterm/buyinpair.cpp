#include <iostream>
#include <set>
using namespace std;

set <long long> myset;
set <long long>::iterator it;
long long result=0;
int main () {

        long long n,a,b,nloop; 
        cin >> n >> a >> b;
        nloop = n;
        long long price;
        while (nloop--) {
            cin >> price;

            if (nloop == n-1) {myset.insert(price) ; continue; }
            

            if (price > b) { continue; }
            else if (price > a) { it = myset.begin(); }
            else { it = myset.lower_bound(a-price); }

            //printf("start at %lld\n",*it);
            while (*it+price <= b && it != myset.end()) {
                //printf(">> %lld + %lld (limit:%lld)\n" , *it , price , b);
                result++;
                it++;
            }
            myset.insert(price);
        }
        cout << result << endl;
        return 0;
}