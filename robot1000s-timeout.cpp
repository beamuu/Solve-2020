// NOT SEND !!

#include <iostream>
#include <cmath>
using  namespace std;

int max_dist;

int MOVE(int pos , char dir , char axis) {
    
    switch(dir) {
        case 'N':
            if (axis == 'y')    return pos+1;
            break;
        case 'E':
            if (axis == 'x')    return pos+1;
            break;
        case 'S':
            if (axis == 'y')    return pos-1;
            break;
        case 'W':
            if (axis == 'x')    return pos-1;
            break;
    }
    return pos;
}

void PATH(string command , int i ,int loss , int max_Loss , int pos_x , int pos_y) {

    if (i == command.length()) {
        if (abs(pos_x) + abs(pos_y) > max_dist && loss == max_Loss) {
            max_dist = abs(pos_x)+abs(pos_y);
        }
        return;
    }
    if (loss == max_Loss) {
        return PATH(command , i+1 , loss , max_Loss , MOVE(pos_x , command[i] , 'x') , MOVE(pos_y , command[i] , 'y'));
    }

    else if (loss < max_Loss) {
        
        PATH(command , i+1 , loss , max_Loss , MOVE(pos_x , command[i] , 'x') , MOVE(pos_y , command[i] , 'y'));
        PATH(command , i+1 , loss+1 ,max_Loss , pos_x , pos_y);
        return;
    }

}

int main(void) {

    string command; 
    cin >> command;

    int Loss;
    cin >> Loss;
    PATH(
        command , 0 , 0 , Loss , 0 , 0
    );
    cout << 2*max_dist << endl;
    return 0;

}