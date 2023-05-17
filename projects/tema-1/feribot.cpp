#include <iostream>

using namespace std;

#define infile "feribot.in"
#define outfile "feribot.out"

#define NMAX 10000010

uint64_t G[NMAX];  // greutatea fiecarei masini
uint64_t N, K;  // numarul de masini, si numarul de feriboturi
uint64_t Gtot;  // greutatea tuturor masinilor
uint64_t i;

void citire() {
    scanf("%ld %ld\n", &N, &K);

    for (i = 1; i <= N; i++) {
        scanf("%ld", &G[i]);  // citim
        Gtot += G[i];  // adaugam la greutatea tuturor masinilor
    }
}

int verifica(uint64_t x) {
    uint64_t Gc = 0;  // greutatea curenta
    uint64_t nr = 1;  // numarul de feriboturi
    for (i = 1; i <= N; i++) {  // trecem pe la fiecare masina
        if (G[i] > x) {  // daca greutatea unei masini este mai mare decat x,
            return 0;  // nu se poate
        }
        Gc += G[i];  // adaugam greutatea masinii la greutatea curenta
        if (Gc > x) {  // daca s-a depasit greutatea maxima a unui feribot,
            Gc = G[i];  // resetam greutatea curenta
            nr++;  // si adaugam un feribot
        }
    }
    if (nr <= K) {
        return 1;  // daca s-a putut efectua
    }
    return 0;  // altfel nu
}

// cauta binar costul minim
uint64_t binarySearch(uint64_t a, uint64_t b) {
    uint64_t cmin = b;  // costul minim, initializat cu valoarea maxima
    uint64_t m;  // mijlocul
    while (a <= b) {
        m = (a + b) / 2;
        if (verifica(m)) {  // daca se poate
            cmin = m;  // actualizam costul minim
            b = m - 1;  // cautam mai mic
        } else {
            a = m + 1;  // cautam mai mare
        }
    }
    return cmin;  // returnam costul minim
}

int main() {
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);

    citire();
    printf("%ld", binarySearch(1, Gtot));  // afisam costul minim

    fclose(stdin);
    fclose(stdout);

    return 0;
}
