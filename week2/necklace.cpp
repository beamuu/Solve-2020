#include <iostream>
using namespace std;

int lib[300001];

void Traverse(int num1 , int num2);

void Put(int num1 , int num2) {

    int tmp;
    if (!lib[num2]) {
        lib[num2] = num1;
    }
    else {
        tmp = lib[num2];
        lib[num2] = num1;
        Traverse(tmp,num1);
    }
}

void Traverse(int num1 , int num2) {
    if (lib[num2]) {
        Traverse(num1,lib[num2]);
    }
    else {
        lib[num2] = num1;
    }
}

void Show(int num2) {
    cout << num2 << " ";
    if (lib[num2]) {
        Show(lib[num2]);
    }
    else {
        cout << "\n";
    }
}

int findStart(int num , int *mark , int n) {
    for (int i=1 ; i<n+1; i++) {
        mark[lib[i]] = 1;
    }   
    for (int i=1 ; i<n+1 ; i++) {
        if (mark[i] == 0) {
            return i;
        }
    }
    return -1;
}

int main() {;
    
    int n,t,num1,num2;
    cin >> n;
    int mark[n+1];
    for (int i=0 ; i<n+1 ; i++) {
        mark[i] = 0;
    }
    t = n-1;
    while (t--) {
        cin >> num1 >> num2;
        Put(num1,num2);
    }
    Show(findStart(num2,mark,n));
    return 0;
}
