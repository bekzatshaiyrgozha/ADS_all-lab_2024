#include <iostream>
#include <vector>
using namespace std;

vector<int> computePrefix(const string &pattern)
{
    int m = pattern.size();
    vector<int> lps(m, 0);
    int j = 0;
    for (int i = 1; i < m; i++)
    {
        while (j > 0 && pattern[i] != pattern[j])
        {
            j = lps[j - 1];
        }
        if (pattern[i] == pattern[j])
        {
            j++;
            lps[i] = j;
        }
        else
        {
            lps[i] = 0;
        }
    }
    return lps;
}

void KMF_search(const string &text, const string &pattern)
{
    int n = text.size();
    int m = pattern.size();
    vector<int> lps = computePrefix(pattern);
    int counter = 0;

    int i = 0;
    int j = 0;

    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << "index:" << i - j << " ";
            cout << endl;

            counter++;
            j = lps[j - 1];
        }
        else if (pattern[j] != text[i])
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
    cout << endl;
    cout << "couter:" << counter;
}

int main()
{
    string text = "ABABABABCKDSABAB";
    string pattern = "ABA";
    KMF_search(text, pattern);
}