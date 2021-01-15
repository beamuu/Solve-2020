#include <iostream>
#include <list>
using namespace std;

int main() {

    list<string> editor;
    list<string>::iterator cursor;
    list<string>::iterator fake;
    cursor = editor.begin();

    char command;
    string text;

    int n;
    cin >> n;

    while (n--) {
        cin >> command;
        switch(command) {
            case 'l':
                if (cursor != editor.begin()) {
                    cursor--;
                }
                break;
            case 'r':
                if (cursor != editor.end()) {
                    cursor++;
                }
                break;
            case 'i':
                cin >> text;
                editor.insert(cursor , text);
                break;
            case 'b':
                if (cursor != editor.begin()) {
                    fake = --cursor;
                    editor.erase(fake);
                }
                break;
            case 'd':
                if (cursor == editor.end()) {
                    break;
                }
                else {
                    fake = cursor;
                    cursor++;
                    editor.erase(fake);
                    break;
                }
        }
        /*
        for (auto i=editor.begin() ; i!=editor.end(); i++) {   
            cout << *i << ' ';
        }
        */
    }
    return 0;

}
