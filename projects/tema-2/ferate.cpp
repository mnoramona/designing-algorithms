#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <cstdio>

using namespace std;

// Lista de adiacenta
vector<vector<int>> adjacencyList;
// low[node] = cel mai mic index al unui nod accesibil din nodul node
vector<int> low;
// visited[node] = indexul nodului
vector<int> visited;
// stiva
vector<int> st;
// Vectorul de componente conexe
vector<vector<int>> components;

int index = 0;  // Indexul curent
int numSCC = 0;  // Numărul de componente tare conexe
int N;  // N = numărul de noduri,
int M;  // M = numărul de muchii,
int S;  // S = nodul de start

void tarjan(int node) {
    low[node] = index;
    visited[node] = index;
    index++;
    st.push_back(node);  // adăugăm nodul în stivă

    for (int neighbor : adjacencyList[node]) {  // parcurgem vecinii nodului
        if (visited[neighbor] == -1) {
            tarjan(neighbor);
            low[node] = min(low[node], low[neighbor]);
        } else if (visited[neighbor] < visited[node]) {
            if (visited[neighbor] != -1) {
                low[node] = min(low[node], visited[neighbor]);
            }
        }
    }

    if (low[node] == visited[node]) {
        vector<int> component;
        while (true) {
            int top = st.back();
            st.pop_back();
            visited[top] = N;
            component.push_back(top);

            if (top == node) {
                break;
            }
        }
        numSCC++;  // creștem numărul de componente tare conexe
        components.push_back(component);
    }
}

int main() {
    freopen("ferate.in", "r", stdin);
    freopen("ferate.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    scanf("%d %d %d", &N, &M, &S);

    adjacencyList.resize(N + 1);
    low.resize(N + 1, -1);
    visited.resize(N + 1, -1);

    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        adjacencyList[x].push_back(y);
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i] == -1) {
            tarjan(i);
        }
    }

    vector<int> inDegree(numSCC, 0);
    for (int i = 0; i < numSCC; i++) {
        for (int node : components[i]) {
            for (int neighbor : adjacencyList[node]) {
                bool isSameComponent = false;
                for (int j = 0; j < numSCC; j++) {
                    if (j == i) continue;  // Sărim peste componenta curentă
                    for (int node2 : components[j]) {
                        if (node2 == neighbor) {
                            isSameComponent = true;
                            break;
                        }
                    }
                    if (isSameComponent) {
                        inDegree[j]++;
                        break;
                    }
                }
            }
        }
    }
    int numSCCWithoutNeighbors = 0;

    for (int i = 0; i < numSCC; i++) {
        if (inDegree[i] == 0) {
            bool containsSource = false;
            for (int node : components[i]) {
                if (node == S) {
                    containsSource = true;
                    break;
                }
            }
            if (!containsSource) {
                numSCCWithoutNeighbors++;
            }
        }
    }
    printf("%d\n", numSCCWithoutNeighbors);

    return 0;
}
