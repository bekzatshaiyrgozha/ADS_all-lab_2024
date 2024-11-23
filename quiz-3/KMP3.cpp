#include <iostream>
#include <vector>

using namespace std;

// Префикс-функцияны есептейтін функция
vector<int> compute(const string &pattern)
{
    int m = pattern.size();
    vector<int> prefix(m, 0); // Префикс-массивін құру
    int j = 0;

    // Префикс-функцияны есептеу
    for (int i = 0; i < m; i++)
    {
        while (j > 0 && pattern[i] != pattern[j]) // Егер сәйкес келмесе, алдыңғы префикске қайту
        {
            j = prefix[j - 1];
        }
        if (pattern[i] == pattern[j]) // Егер сәйкес келсе, префикс ұзындықты арттыру
        {
            j++;
        }
        prefix[i] = j; // Әр позициядағы префикс ұзындығын сақтау
    }
    return prefix;
}

// KMP алгоритмі
void kmp(const string &text, const string &pattern)
{
    int n = text.size();
    int m = pattern.size();
    vector<int> prefix = compute(pattern); // Паттерн үшін префикс-функцияны есептеу

    int j = 0; // Паттерннің индексы

    // Мәтінді іздеу
    for (int i = 0; i < n; i++)
    {
        while (j > 0 && text[i] != pattern[j]) // Егер сәйкес келмесе, префикс бойынша алға жылжу
        {
            j = prefix[j - 1];
        }

        if (pattern[j] == text[i]) // Егер сәйкес келсе, жүктемені арттыру
        {
            j++;
        }

        // Егер паттерн толық сәйкес келсе
        if (m == j)
        {
            cout << "index " << i - j + 1 << " "; // Индексті шығару
            j = prefix[j - 1];                    // Келесі іздеуді бастау
        }
    }
}

int main()
{
    string text, pattern;
    cin >> text >> pattern; // Мәтін мен паттернді енгізу

    kmp(text, pattern); // KMP алгоритмін орындау
}
