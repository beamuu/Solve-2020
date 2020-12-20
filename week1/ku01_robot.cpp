#include <iostream>
#include <algorithm>
using namespace std;

int Same(int h1 , int h2 , int b1 , int b2) {

    int white = min(h1,b1);
    int black = min(h2,b2);
    return white+black;
}

int Bicolor(int h1 , int h2 , int b1, int b2) {

    int white_head = min(h1,b2);
    int black_head = min(h2,b1);
    return white_head + black_head;
}

int GameOver(int h1 , int h2 , int b1, int b2) {
    
    int white = min(h1,b1);
    int black = min(h2,b2);
    if (!white && !black) {
        return 1;
    }
    return 0;
}

int GameOver2(int h1 , int h2 , int b1, int b2) {
    
    int white = min(h1,b2);
    int black = min(h2,b1);
    if (!white && !black) {
        return 1;
    }
    return 0;
}

int CanDo(int x , int y) {
    if (x == 0 || y == 0) return 0;
    return 1;
}


int main(void) {

    int H1,H2,B1,B2,X,Y;
    int h1,h2,b1,b2,x,y,res=0,count=0,bicolor;
    int same;
    cin >> H1 >> H2 >> B1 >> B2;
    cin >> X >> Y;

    x = X;
    y = Y;
    
    int white=1;
    h1 = H1;
    h2 = H2;
    b1 = B1;
    b2 = B2;
    while (1) {
        if (count == x || GameOver(h1,h2,b1,b2)) {
            break;
        }
        if (white && CanDo(h1,b1)) {
            h1 -= 1;
            b1 -= 1;
        }
        else if (!white && CanDo(h2,b2)) {
            h2 -= 1;
            b2 -= 1;
        }
        else {
            white = !white;
            continue;
        }
        white = !white;
        count++;
        bicolor = Bicolor(h1,h2,b1,b2);
        if (bicolor > y) {
            bicolor = y;
        }
        //cout << "SAME: " <<count << "+" << bicolor << "\n";
        if (count+bicolor > res) {
            res = count + bicolor;
        }
    }
    count = 0;
    white = 1;
    h1 = H1;
    h2 = H2;
    b1 = B1;
    b2 = B2;
    while (1) {
        if (count == y || GameOver2(h1,h2,b1,b2)) {
            break;
        }
        if (white && CanDo(h1,b2)) {
            h1 -= 1;
            b2 -= 1;
        }
        else if (!white && CanDo(h2,b1)) {
            h2 -= 1;
            b1 -= 1;
        }
        else {
            white = !white;
            continue;
        }
        white = !white;
        count++;
        same = Same(h1,h2,b1,b2);
        if (same > x) {
            same = x;
        }
        //cout << "BI: " << count << "+" << bicolor << "\n";
        if (count+same > res) {
            res = count+same;
        }

    }
    std::cout << res << "\n";
    return 0;
}