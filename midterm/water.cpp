#include <iostream>
using namespace std;

int main() {
    
    int n ; cin >> n;

    int today,yesterday=0,sum=0;
    while (n--) {
        cin >> today;
        if (yesterday-today > 10 && yesterday-today > 70) {
            sum += 700;
        }
        else if (yesterday-today > 10) {
            sum += (yesterday-today)*10;
        }
        yesterday = today;
    }
    printf("%d\n" , sum);
    return 0;
}