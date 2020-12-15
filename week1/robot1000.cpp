#include <iostream>
using namespace std;

int main(void) {

    string command;
    int x=0,y=0;
    cin >> command;

    for (int i=0 ; i<command.length() ; i++) {
        switch(command[i]) {
            case 'N':
                y++;
                break;
            case 'S':
                y--;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
            case 'Z':
                x=0;
                y=0;
                break;
        }
    }
    cout << x << ' ' << y << '\n';
    return 0;
}