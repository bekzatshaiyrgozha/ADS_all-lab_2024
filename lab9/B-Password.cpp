#include <iostream>
#include <vector>
using namespace std;

vector<int> computePrfix(const string &pattern)
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

void search_KMP(const string &password, const int number, const string &text)
{
    int n = text.size();
    int m = password.size();
    int counter = 0;
    vector<int> lps = computePrfix(password);

    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (password[j] == text[i])
        {
            j++;
            i++;
        }
        if (j == m)
        {
            counter++;
            j = lps[j - 1];
        }
        else if (password[j] != text[i])
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
    if (counter >= number)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}
int main()
{
    string password;
    cin >> password;
    int number;
    cin >> number;
    string piceOfPaper;
    cin >> piceOfPaper;

    search_KMP(password, number, piceOfPaper);
}