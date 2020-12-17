#include <iostream>
#include <cmath>
using namespace std;

int Count(string command , char dir) {
    int counted=0;
    for (int i=0 ; i<command.length() ; i++) {
        if (command[i] == dir) {
            counted++;
        }
    }
    return counted;
} 

int main(void) {

    string command;
    int loss,n,s,e,w,dist;
    int *x , *y , *not_choose_x ,*not_choose_y;

    cin >> command;
    cin >> loss;

    n = Count(command,'N');
    s = Count(command,'S');
    e = Count(command,'E');
    w = Count(command,'W');

    if (n > s) {
        y = &n;
        not_choose_y = &s;
    }
    else {
        y = &s;
        not_choose_y = &n;
    }
    if (e > s) {
        x = &e;
        not_choose_x = &w;
    }
    else {
        x = &w;
        not_choose_x = &e;
    }

    while (loss--) {
        if (*not_choose_x)      
            *not_choose_x -= 1;
        else if (*not_choose_y) 
            *not_choose_y -= 1;
        else if (*x)            
            *x -= 1;
        else
            *y -= 1;
    }
    dist = (
        (*x)-(*not_choose_x) +
        (*y)-(*not_choose_y)
    );

    cout << 2*dist << '\n';
    return 0;
    
}