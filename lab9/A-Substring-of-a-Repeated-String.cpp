#include <iostream>
#include <vector>
using namespace std;

vector<int> computeLPS(const string &pattern)
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

bool KMP_search(const string &text, const string &pattern)
{
    int n = text.size();
    int m = pattern.size();
    vector<int> lps = computeLPS(pattern); 

    int i = 0, j = 0;

    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            return true; 
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
    return false;
}

int minRepeatsToContainSubstring(const string &A, const string &B)
{
    int lenA = A.size();
    int lenB = B.size();

    if (KMP_search(A, B))
    {
        return 1;
    }

    string extendedA = A;
    int repeatCount = 1;

    while (extendedA.size() < lenB)
    {
        extendedA += A;
        repeatCount++;
    }

    if (KMP_search(extendedA, B))
    {
        return repeatCount;
    }

    return -1;
}

int main()
{
    string A, B;
    cin >> A >> B;

    cout << minRepeatsToContainSubstring(A, B);

}
