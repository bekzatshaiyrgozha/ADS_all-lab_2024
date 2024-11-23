#include <iostream>
using namespace std;

const int d = 256;
const int q = 101;

void rabinKarp(const string &text, const string &pattern)
{
    int n = text.size();
    int m = pattern.size();
    int h = 1;
    int t = 0;
    int p = 0;

    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }

    for (int i = 0; i < m; i++)
    {
        p = (p * d + pattern[i]) % q;
        t = (t * d + text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            bool match = true;
            for (int j = 0; j < m; j++)
            {
                if (pattern[j] != text[i + j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                cout << "index " << i << endl;
            }
        }
        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
        }
        if (t < 0)
        {
            t = t + q;
        }
    }
}

int main()
{
    string text, pattern;
    cin >> text >> pattern;

    rabinKarp(text, pattern);
}