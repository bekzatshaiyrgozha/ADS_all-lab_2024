#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long computeHash(const string &text, int base, int mod)
{
    long long hash = 0;
    for (int i = 0; i < text.size(); i++)
    {
        hash = (hash * base + text[i]) % mod;
    }
    return hash;
}

vector<int> rabbinKarp(const string &text, const string &pattern)
{
    int textlenght = text.length();
    int patternLenght = pattern.length();
    int base = 256;
    int mod = 1e9 + 7;

    long long textHash = computeHash(text.substr(0, patternLenght), base, mod);
    long long patternHash = computeHash(pattern, base, mod);

    vector<int> result;

    long long basePower = 1;
    for (int i = 0; i < patternLenght; i++)
    {
        basePower = (basePower * base) % mod;
    }

    for (int i = 0; i <= textlenght - patternLenght; i++)
    {
        if (textHash == patternHash)
        {
            if (text.substr(i, patternLenght) == pattern)
            {
                result.push_back(i);
            }
        }

        if (i + patternLenght < textlenght)
        {
            textHash = (textHash - text[i] * basePower) * base + text[i + patternLenght];
            textHash = (textHash + mod) % mod;
        }
    }
    return result;
}

int main()
{
    string text = "qwerty";
    string pattern = "qw";

    vector<int> result = rabbinKarp(text, pattern);

    if (!result.empty())
    {
        cout << "Pattern found at positions: ";
        for (int index : result)
        {
            cout << index << " ";
        }
    }
    else
    {
        cout << "Pattern not found.";
    }

    return 0;
}
