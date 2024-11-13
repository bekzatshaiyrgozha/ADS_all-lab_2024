#include <iostream>
#include <vector>

using namespace std;

vector<int> computeLPS(const string &pattern)
{
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0;

    for (int i = 1; i < m; i++)
    {
        while (len > 0 && pattern[i] != pattern[len])
        {
            len = lps[len - 1];
        }
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
        }
    }
    return lps;
}

int KMP_search(const string &text, const string &pattern)
{
    vector<int> lps = computeLPS(pattern);
    int i = 0, j = 0;
    int n = text.size(), m = pattern.size();

    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        if (j == m) // Егер толық сәйкестік тапсақ
        {
            return i - j; // сәйкестіктің басталу индексін қайтару
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
    return -1; // ешқандай сәйкестік болмаса
}

int main()
{
    string tamerlanLine, alikhanLine;
    cin >> tamerlanLine >> alikhanLine;

    // Тек бір рет айналдыруды тексеріп шығамыз
    string combinedLine = tamerlanLine + tamerlanLine; // екі рет қайталап, барлық айналмалы комбинацияларды қамту

    // Алдымен сәйкестікті іздеу
    int position = KMP_search(combinedLine, alikhanLine);

    if (position != -1 && position < tamerlanLine.size()) // дұрыс орын табылғанда ғана шығару
    {
        cout << position << endl; // тікелей орын шығару
    }
    else
    {
        cout << -1 << endl; // сәйкестік болмаса
    }
}
