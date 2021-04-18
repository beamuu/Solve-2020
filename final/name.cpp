#include <iostream>
using namespace std;

string name, sentence;

int nameLength;
int sentenceLength;

char firstChar;
int selected[100000];
int counted = 0;

int solve(int index, int target)
{
    // index always points to sentence
    // target always points to name
    int recursionState;
    if (target == nameLength)
        return 1;
    else if (index == sentenceLength)
        return 0;
    else if (sentence[index] == name[target] && !selected[index])
        recursionState = solve(index + 1, target + 1);
    else 
        recursionState = solve(index + 1 , target);
    if (recursionState) {
        selected[index] = 1;
        // cout << "mark at index " << index << endl;
    }
    return recursionState;
}

int main()
{
    cin >> name;
    cin >> sentence;

    firstChar = name[0];
    nameLength = name.size();
    sentenceLength = sentence.size();

    for (int i = 0; i < sentence.size(); i++)
    {
        if (!selected[i] && solve(i, 0))
            counted++;
    }
    cout << counted << endl;
    return 0;
}