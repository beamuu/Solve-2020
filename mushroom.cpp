#include <iostream>
#include <queue>
using namespace std;

priority_queue <int> heap;
int mushroom_left = 0;

int main() {
    
    int n,l,h;
    scanf("%d %d %d" , &n , &l , &h);

    int distance , number;
    float light_x , light_y , dead_distance;
    while (n--) {
        scanf("%d" , &number);

        if (number != 0) {
            while (number--) {
                scanf("%d" , &distance);
                heap.push(distance); mushroom_left++;
            }
        }
        scanf("%f %f" , &light_x , &light_y);
        if (heap.empty()) { printf("%d\n" , mushroom_left) ; continue; }
        dead_distance = light_x*h/light_y;
        while (heap.top() >= l+dead_distance) {
            heap.pop(); mushroom_left--;
        }
        printf("%d\n", mushroom_left);
    }
    return 0;
}
