#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const int INF = 1e9; // Бесконечность

vector<vector<int>> generateRandomAdjMatrix(int n) {
    vector<vector<int>> adj_matrix(n, vector<int>(n));

    srand(time(nullptr)); // Инициализация генератора случайных чисел

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) { // Исключаем петли
                adj_matrix[i][j] = rand() % 100; // Генерируем случайное число от 0 до 99
            }
        }
    }

    return adj_matrix;
}

int longestPathWithZeroes(vector<vector<int>> adj_matrix) {
    int n = adj_matrix.size();

    // Вычисление длиннейших путей
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (adj_matrix[i][k] != 0 && adj_matrix[k][j] != 0) { // Пропускаем пути через нули
                    adj_matrix[i][j] = max(adj_matrix[i][j], adj_matrix[i][k] + adj_matrix[k][j]);
                }
            }
        }
    }

    // Находим длиннейший путь
    int longest = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            longest = max(longest, adj_matrix[i][j]);
        }
    }

    return longest != 0 ? longest : -1; // Если длиннейший путь равен нулю, возвращаем -1
}

int main() {

    vector<vector<int>> adj_matrix = generateRandomAdjMatrix(28);

    clock_t start = clock();
    int longestPath = longestPathWithZeroes(adj_matrix);
    clock_t end = clock();

    double duration = double(end - start) / CLOCKS_PER_SEC;
    if (longestPath != -1) {
        cout << duration << "c, Длиннейший путь в графе: " << longestPath << endl;
    } else {
        cout << duration << "c, Длиннейший путь в графе не существует." << endl;
    }

    return 0;
}
