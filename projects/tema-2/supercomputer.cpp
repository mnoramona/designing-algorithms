#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 100002

int N;  // numarul de task-uri
int M;  // numarul de dependente

// vector in care retinem task-urile care depind de task-ul i
vector<int> v[MAXN];
// variabila in care retinem numarul de task-uri care depind de task-ul i
int grd_itrn[MAXN];
// variabila in care retinem setul de date cerut de task-ul i
int set_date[MAXN];
// variabila in care retinem timpul minim necesar pentru a rula task-ul i
int switches[MAXN];

int main() {
    freopen("supercomputer.in", "r", stdin);
    freopen("supercomputer.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cin >> M;

    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        set_date[i] = a;
    }

    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;  // task-ul a depinde de task-ul b
        v[a].push_back(b);  // task-urile care depind de task-ul a
        grd_itrn[b]++;  // numarul de task-uri care depind de task-ul b
    }

    vector<int> ordine;  // ordinea in care se vor executa task-urile
    // Adaugam in ordine task-urile care nu depind de niciun alt task
    for (int i = 1; i <= N; i++) {
        if (grd_itrn[i] == 0) {
            ordine.push_back(i);
        }
    }

    // Adaugam in ordine task-urile care depind de task-urile adaugate anterior
    for (int i = 0; i < ordine.size(); i++) {
        int x = ordine[i];  // task-ul curent
        for (auto current : v[x]) {
            grd_itrn[current]--;
            if (grd_itrn[current] == 0) {
                ordine.push_back(current);  // adaugam in ordine task-ul current
            }
        }
    }

    // Calculam timpul minim necesar pentru a rula fiecare task
    for (int i = 0; i < ordine.size(); i++) {
        for (auto current : v[ordine[i]]) {
            if (set_date[current] != set_date[ordine[i]]) {
            switches[current] = max(switches[current], switches[ordine[i]] + 1);
            } else {
                switches[current] = max(switches[current], switches[ordine[i]]);
            }
        }
    }

    // Calculam numarul minim de switch-uri
    int min_switches = 0;
    for (int i = 1; i <= N; i++) {
        min_switches = max(min_switches, switches[i]);
    }

    cout << min_switches;

    return 0;
}
