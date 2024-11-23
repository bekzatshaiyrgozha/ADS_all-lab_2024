#include <iostream>
#include <vector>

using namespace std;

vector<int> compute(const string &pattern)
{
    int m = pattern.size();
    vector<int> prefix(m, 0);

    int j = 0;
    for (int i = 0; i < m; i++)
    {
        while (j > 0 && pattern[i] != pattern[j])
        {
            j = prefix[j - 1];
        }
        if (text[i] == patttern[j])
        {
            j++;
        }
        prefix[i] = 0;
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
        while (j > 0 && text[i] != pattern[j])
        {
            j = prefix[j - 1];
        }
        if (patternp[j] == text[i])
        {
            j++;
        }
        if (j == m)
        {
            cout << i - j;
            j = prefix[j - 1];
        }
    }
}

int main()
{
    string text, pattern;
    cin >> text >> pattern;

    kmp(text, pattern);
}