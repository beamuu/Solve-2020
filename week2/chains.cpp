#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void show(list<int> List) {
    list<int>::iterator pt;
    for (pt=List.begin() ; pt!=List.end() ; pt++) {
        cout << *pt << " ";
    }
    cout << endl;
}

int main() {

    int l,n;
    int length;
    int num=1;
    char command;
    int value;
    int count=0;

    cin >> l >> n;
    list<int> component[l];
    list<int>::iterator position;
    list<int>::iterator compare;
    for (int i=0 ; i<l ; i++) {
        cin >> length;
        count += length;
        for (int k=0; k<length ; k++) {
            component[i].push_back(num);
            num++;
        }
    return 0;
}