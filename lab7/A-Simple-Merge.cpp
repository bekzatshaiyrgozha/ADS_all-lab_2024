#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void merge(vector<pair<string, int>> &words, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<pair<string, int>> leftWords(n1), rightWords(n2);

    for (int i = 0; i < n1; i++)
    {
        leftWords[i] = words[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        rightWords[j] = words[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftWords[i].first.size() < rightWords[j].first.size() ||
            (leftWords[i].first.size() == rightWords[j].first.size() && leftWords[i].second < rightWords[j].second))
        {
            words[k] = leftWords[i];
            i++;
        }
        else
        {
            words[k] = rightWords[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        words[k] = leftWords[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        words[k] = rightWords[j];
        j++;
        k++;
    }
}

void mergeSort(vector<pair<string, int>> &words, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(words, left, mid);
        mergeSort(words, mid + 1, right);
        merge(words, left, mid, right);
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        string line;
        getline(cin, line);

        stringstream ss(line);
        vector<pair<string, int>> words;
        string word;
        int idx = 0;
        while (ss >> word)
        {
            words.push_back({word, idx++});
        }

        mergeSort(words, 0, words.size() - 1);

        for (int j = 0; j < words.size(); j++)
        {
            if (j > 0)
                cout << " ";
            cout << words[j].first;
        }
        cout << endl;
    }
}
