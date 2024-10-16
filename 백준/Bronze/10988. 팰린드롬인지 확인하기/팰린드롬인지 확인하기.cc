#include <iostream>
#include <stack>

using namespace std;

stack<char> Stack;

int main()
{
    string s;
    cin >> s;

    for (char c : s)
    {
        Stack.push(c);
    }

    bool result = true;
    for (int i = 0; i < s.size() / 2; ++i)
    {
        if (s[i] != Stack.top()) result = false;
        Stack.pop();
    }

    cout << result;
}