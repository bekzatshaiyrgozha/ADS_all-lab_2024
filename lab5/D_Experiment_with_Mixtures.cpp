#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, D;
    cin >> n >> D;

    priority_queue<int, vector<int>, greater<int> > densities;

    for (int i = 0; i < n; ++i) {
        int density;
        cin >> density;
        densities.push(density);
    }

    int operations = 0;

    // Продолжаем смешивать, пока есть более одной плотности и минимальная плотность меньше D
    while (densities.size() > 1 && densities.top() < D) {
        int smallest = densities.top();
        densities.pop();
        int second_smallest = densities.top();
        densities.pop();

        int new_density = smallest + second_smallest;  // Используем правильную формулу
        densities.push(new_density);
        operations++;
    }

    // Проверяем, достигли ли мы плотности D для всех смесей
    if (densities.top() < D) {
        cout << -1 << endl;
    } else {
        cout << operations << endl;
    }

    return 0;
}
