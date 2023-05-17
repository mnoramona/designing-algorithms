#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#define infile "badgpt.in"
#define outfile "badgpt.out"

#define ll long long
ll a, b, c, d;

const uint64_t MOD = 1000000007;

// am folosit fast doubling method
void fib(uint64_t n, vector <ll>& res) {
  /*
    F(2k) = F(k) * [2 * F(k + 1) - F(k)]
    F(2k + 1) = F(k + 1) ^ 2 + F(k) ^ 2
  */

    if (n == 0) {  // caz de baza
        res[0] = 0;
        res[1] = 1;
        return;
    }

    // daca n e impar
    fib((n / 2), res);

    a = res[0];  // F(k)
    b = res[1];  // F(k + 1)

    c = 2 * b - a;  // 2 * F(k + 1) - F(k)

    if (c < 0) {  // daca e negativ
      c += MOD;
    }
    // aplic F(2n) = F(n) * [2 * F(n + 1) - F(n)]
    c = (1ULL * a * c) % MOD;

    // aplic F(2n + 1) = F(n) ^ 2 + F(n + 1) ^ 2
    d = (1ULL * a * a + 1ULL * b * b) % MOD;

    if (n % 2 == 0) {  // pentru n par
        res[0] = c;
        res[1] = d;
    } else {  // pentru n impar
        res[0] = d;
        res[1] = c + d;
        if (res[1] >= MOD) {
          res[1] -= MOD;  // verificare continua ca nu am incredere
        }
    }
}

int main() {
  ifstream fin(infile);

  char c;  // pentru literele n si u
  uint64_t nr;  // pentru numarul de elemente
  uint64_t res = 1;  // rezultatul final
  vector<ll> f(2, 0);  // vectorul de rezultate

  while (fin >> c >> nr) {
    if (c == 'n') {  // daca e n
      fib(nr + 1, f);  // calculez F(nr + 1)
      res = (1ULL * res * f[0]) % MOD;  // inmultesc cu rezultatul final
      // grija la % MOD
    } else if (c == 'u') {  // daca e u
      fib(nr + 1, f);  // la fel
      res = (1ULL * res * f[0]) % MOD;
      }
    }

    fin.close();
    ofstream fout(outfile);

    fout << res << endl;

    fout.close();
    return 0;
}
