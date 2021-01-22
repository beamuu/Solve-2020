// NOT SEND !!!
#include <iostream>
#include <cmath>
using namespace std;

void Rotate(int *dir , int suppose_dir) {
    // Rotate right
    while (*dir%4 != suppose_dir) {
        cout << 'R';
        *dir += 1;
    }
}



int main(void) {

    string command;
    cin >> command;

    int dir=0;

    for (int i=0 ; i<command.length() ; i++) {
        switch (command[i]) {
            case 'N':
                Rotate(&dir , 0);
                cout << 'F';
                break;
            case 'S':
                Rotate(&dir , 2);
                cout << 'F';
                break;
            case 'E':
                Rotate(&dir , 1);
                cout << 'F';
                break;
            case 'W':
                Rotate(&dir , 3);
                cout << 'F';
                break;
            case 'Z':
                dir = 0;
                cout << 'Z';
                break;
        }
    }
    return 0;
}