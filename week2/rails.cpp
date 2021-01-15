#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n,train;
    vector<int> Stack;
    vector<int> sequence;
    vector<int> lib;
    vector<int>::iterator res_pt;
    vector<int>::iterator main_pt;

    while (1) {

        cin >> n;
        if (!n) {
            break;
        }

        for (int i=0 ; i<n ; i++) {
            cin >> train;
            if (!train) {
                break;
            }
            sequence.push_back(train);
            lib.push_back(i+1);
        }
        res_pt = sequence.begin();
        main_pt = lib.begin();
        while (1) {

            if (Stack.size() > 0 && *(--Stack.end()) == *res_pt) {

                res_pt++;
                Stack.pop_back();
            }
            else if (find(Stack.begin(),Stack.end(),*res_pt) == Stack.end()) {

                Stack.push_back(
                    *(lib.begin())
                );
                main_pt++;

                

            }
        }

    }



    return 0;
}