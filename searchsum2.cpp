#include <iostream>
#include <queue>
using namespace std;

priority_queue <int , vector<int> , greater<int> > heap;
priority_queue <int , vector<int> , greater<int> > heap_cpy;
int main() {
    int n , k , bookPrice , money , count=0;
    cin >> n >> k;
    
    while (n--) {
        cin >> bookPrice;
        heap.push(bookPrice);
    }
    while (k--) {
        cin >> money;
        heap_cpy = heap;
        while (1) {
            if (money == 0) { count++ ; break; }
            if (money-heap_cpy.top() < 0) break;
            money -= heap_cpy.top();
            heap_cpy.pop();
            count++;
        }
        printf("%d\n",count);
        count =0;
    }
    return 0;
}
