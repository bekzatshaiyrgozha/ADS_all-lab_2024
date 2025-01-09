#include <iostream>
#include <vector>

using namespace std;

vector<int> compute(const string &pattern) 
{
    int m = pattern.size();
    vector<int> prefix(m, 0);
    int j = 0;

    for (int i = 1; i < m; i++) 
    {
        while (j > 0 && pattern[i] != pattern[j])
        {
            j = prefix[j - 1];
        }
        if (pattern[i] == pattern[j])
        {
            j++;
        }
        prefix[i] = j;
    }
    return prefix;
}

void kmp(const string &text, const string &pattern)
{
    int n = text.size();
    int m = pattern.size();
    vector<int> prefix = compute(pattern);

    int j = 0;

    for (int i = 0; i < n; i++)
    {
        while (j > 0 && pattern[j] != text[i])
        {
            j = prefix[j - 1];
        }
        if (pattern[j] == text[i])
        {
            j++;
        }
        if (j == m)
        {
            cout << "index " << i - j + 1 << endl;
            j = prefix[j - 1];
        }
    }
}

int main()
{
    string text, pattern;
    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pattern;
    kmp(text, pattern);
    return 0;
}
