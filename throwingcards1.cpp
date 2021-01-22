#include <iostream>
#include <list>
using namespace std;

int main() {

    int n,tmp;
    list<int> Deck;
    list<int>::iterator pt;

    while (1) {

        cin >> n;
        if (n == 0) {
            break;
        }
        for (int i=1 ; i<=n ; i++) {
            Deck.push_back(i);
        }
        cout << "Discarded cards: ";
        while (Deck.size() != 2) {
            
            cout << *(Deck.begin()) << ", ";
            Deck.pop_front();
            tmp = *(Deck.begin());
            Deck.pop_front();
            Deck.push_back(tmp);
        }
        cout << *(Deck.begin()) << endl;
        Deck.pop_front();
        cout << "Remaining Card: " << *(Deck.begin()) << endl;
        Deck.clear();

    }

    return 0;
}
