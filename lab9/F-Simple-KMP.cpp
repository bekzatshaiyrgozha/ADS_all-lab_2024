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
    vector<int> index;

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
            index.push_back(i - j + 1);

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

    cout << counter;
    cout << endl;
    for (int i = 0; i < index.size(); i++)
    {
        cout << index[i] << " ";
    }
}

int main()
{
    string text;
    string pattern;
    cin >> text >> pattern;

    KMF_search(text, pattern);
}