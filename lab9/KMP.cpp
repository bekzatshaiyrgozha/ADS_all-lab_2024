#include <iostream>
#include <vector>
using namespace std;

vector<int> computePrefixFunction(const string &pattern)
{
    int m = pattern.size();
    vector<int> lps(m, 0);
    int j = 0;

    for (int i = 1; i < m; i++)
    {
        while (j > 0 && pattern[i] != pattern[j]) // if not equalse,we write 0
        {
            j = lps[j - 1];
        }
        if (pattern[i] == pattern[j]) // if equalse write index
        {
            j++;
            lps[i] = j;
        }
        else
        {
            lps[i] = 0; // else write 0
        }
    }
    return lps;
}

void KMP_search(const string &text, const string &pattern)
{
    int n = text.size();
    int m = pattern.size();
    vector<int> lps = computePrefixFunction(pattern);

    int i = 0; // index of text
    int j = 0; // index of pattern

    while (i < n)
    { // between 0 and size of text
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << "find patten index:" << i - j;
            j = lps[j - 1];
        }
        else if (i < n && text[i] != pattern[j])
        {
            if (j > 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

int main()
{
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    KMP_search(text, pattern);
}