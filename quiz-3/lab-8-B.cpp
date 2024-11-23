#include <iostream>

using namespace std;

const int d = 256;
const int q = 101;

void rabinKarp(const string &text, const string &pattern,vector<int> &index)
{
    int n = text.size();
    int m = pattern.size();

    vector<int>index;

    int h = 1;
    int p = 0;
    int t = 0;

    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }

    for (int i = 0; i < n - m; i++)
    {
        t = (t * d + text[i]) % q;
        p = (p * d + pattern[i]) % q;
    }

    for (int i = 0; i <= n - m; i++)
    {
        if (t == p)
        {
            bool match = true;
            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                index.push_back(i);
                
            }
        }
        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
    return index;
}

int main()
{
    string text1, text2, pattern;
    cin >> text1 >> text2 >> pattern;
    vector<int>index1;
    vector<int>index2;

    rabinKarp(text1, pattern,index1);
    rabinKarp(text2, pattern,index2);

}