#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    //1 == white 2 == black;
    int h1,h2,b1,b2,x,y;
    
    cin >> h1 >> h2 >> b1 >> b2;
    cin >> x >> y;

    int count = 0;

    //unicolor == x
    //bicolor == y
    int max_white = min(h1,b2);
    int max_black = min(h2,b2);

    int bicolor_white_head;
    int bicolor_black_head;
    
    if (max_white > max_black) {
        // choose white first.
        if (max_white > x) {
            h1 -= x;
            b1 -= x;
            count += x;
        }
        else {
            h1 -= max_white;
            b1 -= max_white;
            x -= max_white;
            count += max_white;

            if (max_black > x) {
                h2 -= x;
                b2 -= x;
                count += x;
            }
            else {
                h2 -= max_black;
                b2 -= max_black;
                count += max_black;
            }

        }
    }
    else {
        // choose black first.
        if (max_black > x) {
            h2 -= x;
            b2 -= x;
            count += x;
        }
        else {
            h2-= max_black;
            b2 -= max_black;
            x -= max_black;
            count += max_black;

            if (max_white > x) {
                h1 -= x;
                b1 -= x;
                count += x;
            }
            else {
                h1 -= max_white;
                b1 -= max_white;
                count += max_white;
            }
        }
    }

    bicolor_white_head  = min(h1,b2);
    bicolor_black_head = min(h2,b1);
    
    if (bicolor_white_head > bicolor_black_head) {
        // choose white first.
        if (bicolor_white_head > y) {
            count += y;
        }
        else {
            count += bicolor_white_head;
            y -= bicolor_white_head;

            if (bicolor_black_head > y) {
                count += y;
            }
            else {
                count += bicolor_black_head;
            }
        }
    }
    else {
        // choose black first.
        if (bicolor_black_head > y) {
            count += y;
        }
        else {
            count += bicolor_black_head;
            y -= bicolor_black_head;

            if (bicolor_white_head > y) {
                count += y;
            }
            else {
                count += bicolor_white_head;
            }
        }
    }
    cout << count << "\n";
    return 0;
}