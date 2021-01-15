#include <iostream>
#include <list>
#include <string.h>
using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int start=0,len;
    char mystring[100100];
    list<char> output;
    list<char>::iterator pt;
    pt = output.begin();
    int a = 3;

    while (scanf(" %s",mystring) != EOF) {
        len = strlen(mystring);
        for (int i=0 ; i<len; i++) {
            if (mystring[i] == '[') {
                pt = output.begin();
                continue;
            }
            else if (mystring[i] == ']') {
                pt = output.end();
                continue;
            }
            else {
                output.insert(pt,mystring[i]);
            }
        }
        for (pt=output.begin() ; pt!=output.end() ; pt++) {
            printf("%c",*pt);
        }
        printf("\n");
        output.clear();
    }
    return 0;
}
