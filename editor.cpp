#include <iostream>
#include <list>
using namespace std;

int main() {

    list<string> editor;
    list<string>::iterator cursor;
    list<string>::iterator decoy;

    cursor = editor.end();

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
                    decoy = --cursor; cursor++;
                    editor.erase(decoy);
                }
                break;
            case 'd':
                if (cursor == editor.end()) {
                    break;
                }
                else {
                    decoy = cursor;
                    cursor++;
                    editor.erase(decoy);
                    break;
                }
        }
    }
    for (auto i=editor.begin() ; i!=editor.end() ; i++) {
        cout << *i << ' ';
    }
    cout << '\n';
    return 0;

}
