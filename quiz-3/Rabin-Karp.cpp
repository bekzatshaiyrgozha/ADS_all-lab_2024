#include <iostream>

using namespace std;

const int d = 256;
const int q = 101;

void rabinKarp(const string &text, const string &pattern)
{
    int n = text.size();
    int m = pattern.size();
    int h = 1;

    int p = 0;
    int t = 0;

    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }

    for (int i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (int i = 0; i < n - m; i++)
    {
        if (p == t)
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
                cout << "find index:" << i << " ";
            }
        }
        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}

int main()
{
    string text = "АБРАКАДАБРА";
    string pattern = "РА";

    rabinKarp(text, pattern);
}