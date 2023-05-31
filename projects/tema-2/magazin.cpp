#include <iostream>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

const int MAXN = 100001;

int N;  // Numărul de depozite
int Q;  // Numărul de întrebări
int D;  // Depozitul de la care începe expedierea
int E;  // Numărul de expedieri consecutive

// depozite[i] = depozitele spre care poate trimite colete depozitul i
vector<int> depozite[MAXN];

int depozit_final;

// Functia dfs parcurge graful
void dfs(int k, int &E) {
    // Daca am ajuns la final si nu am gasit un depozit final
    if (E == 0 && depozit_final == -1) {
        depozit_final = k;  // Atunci depozitul final este k
    }
    E--;

    for (int i = 0; i < depozite[k].size(); i++) {
        dfs(depozite[k][i], E);
    }
}

int main() {
    freopen("magazin.in", "r", stdin);
    freopen("magazin.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    scanf("%d %d", &N, &Q);

    // Citim depozitele
    for (int i = 2; i <= N; i++) {
        int depozit;
        scanf("%d", &depozit);
        depozite[depozit].push_back(i);
    }

    // Citim întrebările
    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &D, &E);

        depozit_final = -1;

        // Apelam functia dfs care parcurge graful
        dfs(D, E);

        // Afisam depozitul final
        printf("%d\n", depozit_final);
    }
    return 0;
}


