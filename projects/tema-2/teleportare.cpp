#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int destination;
    int weight;
};

vector<vector<Edge>> graph;
vector<int> dp;

int main() {
    ifstream in("teleportare.in");
    ofstream out("teleportare.out");

    // Citim datele de intrare
    int N, M, K;
    in >> N >> M >> K;

    // Initializam graful si vectorul de distante
    graph.resize(N + 1);
    dp.resize(N + 1, INT_MAX);

    // Citim muchiile normale
    for (int i = 0; i < M; i++) {
        int X, Y, T;
        in >> X >> Y >> T;
        graph[X].push_back({ Y, T });
        graph[Y].push_back({ X, T });
    }

    // Citim muchiile de teleportare
    for (int i = 0; i < K; i++) {
        int X, Y, P;
        in >> X >> Y >> P;
        for (int j = X; j <= N; j += P) {
            graph[j].push_back({ Y, P });
            graph[Y].push_back({ j, P });
        }
    }

    // Initializam distanta de la nodul 1 la el insusi cu 0
    dp[1] = 0;

    // Aplicam algoritmul lui Dijkstra
    for (int i = 1; i <= N; i++) {
        for (const Edge& edge : graph[i]) {
            dp[edge.destination] = min(dp[edge.destination],
                                    dp[i] + edge.weight);
        }
    }

    // Afisam rezultatul
    out << dp[N] << endl;

    return 0;
}

