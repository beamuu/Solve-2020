#include <iostream>
#include <list>
using namespace std;

int brokenBottle=0;
list <int> mark;
void destroy(int *array , int n , int height) {
    for (int i=0 ; i<n ; i++) {
        if (array[i] > height) {
            if (array[i] != 0) {
                array[i] = 0;
                brokenBottle++;
            }
            if (array[i-1] != 0 && i > 0) {
                array[i-1] = 0;
                brokenBottle++;
            }
            if (array[i+1] != 0 && i < n-1 && n != 1) {
                array[i+1] = 0;
                brokenBottle++;
            }
        }
    }
}

int main() {
    
    int n,m,height;
    cin >> n >> m;
    
    int *array = (int *)malloc(sizeof(int)*n);
    
    for (int i=0 ; i<n ; i++) {
        cin >> height;
        array[i] = height;
    }

    while (m--) {
        cin >> height;
        destroy(array , n , height);
        cout << brokenBottle << endl;
        brokenBottle=0;
    }
    return 0;
}
