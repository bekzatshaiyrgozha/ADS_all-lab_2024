#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> Stack;
    for (int i = 0; i < 5; i++)
    {
        int k;
        cin >> k;
        Stack.push(k);
    }

    cout << Stack.size() << endl;
    cout << Stack.empty() << endl;
    cout << Stack.pop();
}