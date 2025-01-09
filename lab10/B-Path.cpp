#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

int shortestPath(const vector<vector<int>> &graph, int start, int end)
{
    int n = graph.size();
    vector<int> distance(n, numeric_limits<int>::max()); // Қашықтық массиві
    queue<int> q;

    distance[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int i = 0; i < n; ++i)
        {
            if (graph[current][i] == 1 && distance[i] == numeric_limits<int>::max())
            {
                distance[i] = distance[current] + 1;
                q.push(i);
            }
        }
    }

    return (distance[end] == numeric_limits<int>::max()) ? -1 : distance[end];
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> graph[i][j];
        }
    }

    int start, end;
    cin >> start >> end;

    start--;
    end--;

    cout << shortestPath(graph, start, end) << endl;
}