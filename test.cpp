#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <stack>

struct TH {
    int v;
    float w;
};

class Graph {
private:
    std::vector<int> A;
    std::vector<float> w;
    int N;
    int n;
public:
    Graph(std::vector<int> cov, std::vector<float> weights) : A(cov), w(weights), N(cov.size()), n(std::sqrt(N)) {};

    ~Graph() = default;

    int GetVertexesCount() { return n; }

    bool operator()(const int from, const int to){
        return A[from * n + to] == 1;
    }

    float operator()(const int num){
        return w[num];
    }

    void changeColumn(int row, int num){
        for (int j = 0; j < n; ++j){
            if (A[row * n + j] == 0){
                for (int i = 0; i < n; ++i)
                    A[n * i + j] += num;
            }
        }
    }

};



std::pair<std::vector<int>, float> DepthFirstSearch(Graph &graph, const int start_vertex) {
    int n = graph.GetVertexesCount();

    if (start_vertex > n or start_vertex < 0)
        return {};

    float sum_weight = 0.;
    std::vector<int> longets_path;
    float max_weight = 0.;

    std::vector<int> enter_order;
    std::vector<short> visited(n);
    std::stack<int> s;

    visited[start_vertex] = true;
    s.push(start_vertex);

    enter_order.emplace_back(start_vertex);
    sum_weight += graph(start_vertex);

    max_weight = sum_weight;
    longets_path = enter_order;

    while (!s.empty())
    {
        auto from = s.top();
        bool is_found = false;

        for (int to = 0, size = n; to != size; ++to)
        {
            if (!visited[to] and graph(from, to))
            {
                is_found = true;
                visited[to] = true;
                s.push(to);
                enter_order.emplace_back(to);
                sum_weight += graph(to);
                if (sum_weight > max_weight)
                {
                    max_weight = sum_weight;
                    longets_path = enter_order;
                }
                from = to;
            }
        }

        if (!is_found)
        {
            s.pop();
            sum_weight -= graph(from);
        }
    }

    return {longets_path, max_weight};
}

int main() {

    std::vector<int> A(25);
    for (int i = 0; i < 5; ++i)
        A[i * 5 + i] = 0;
    A[1 * 5 + 0] = A[0 * 5 + 1] = 1;
    A[2 * 5 + 0] = A[0 * 5 + 2] = 1;
    A[1 * 5 + 3] = A[3 * 5 + 1] = 1;
    A[1 * 5 + 4] = A[4 * 5 + 1] = 1;

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
            std::cout<<A[i * 5 + j]<<' ';
        std::cout<<std::endl;
    }

    for (int j = 0; j < 5; ++j)
    {
        if (A[3 * 5 + j] == 0)
        {
            for (int i = 0; i < 5; ++i)
                A[5 * i + j] += 1;
        }
    }


    std::cout<<std::endl;

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
            std::cout<<A[i * 5 + j]<<' ';
        std::cout<<std::endl;
    }

//    Graph g(A, {0.1, 0.1, 0.1, 0.1, 0.1});
//    auto res = DepthFirstSearch(g, 0);
//    for (const auto el: res.first)
//        std::cout << el;
//    std::cout<<' '<<res.second;
    return 0;
}