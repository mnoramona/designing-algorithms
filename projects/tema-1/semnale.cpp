#include <iostream>

#define ll long long

using namespace std;

const int mod = 1000000007;

// functie auxiliara pentru a calcula inversul unui numar mare
ll invers_modular(ll a, ll m) {
    ll m0 = m;  // copie a lui mod
    ll y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1) {  // algoritmul Euclid
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}

// functie auxiliara pentru a calcula combinari de x luate cate y
ll combinari(ll x, ll y) {
    ll numarator = 1LL;
    ll numitor = 1LL;
    for (ll i = x - y + 1; i <= x; i++) {
        numarator = (numarator * i) % mod;
    }
    for (ll i = 1; i <= y; i++) {
        numitor = (numitor * i) % mod;
    }
    numitor = invers_modular(numitor, mod);
    return (numarator * numitor) % mod;
}

int type1(int x, int y) {
    return 1ULL * combinari(x + 1, y) % mod;  // combinari de x + 1 luate cate y
}

int type2(int x, int y) {
    return 0;
}

int main() {
    freopen("semnale.in", "r", stdin);
	freopen("semnale.out", "w", stdout);

	int sig_type, x, y;
	cin >> sig_type >> x >> y;

    switch (sig_type) {
		case 1:
			cout << type1(x, y);;
			break;
		case 2:
			cout << type2(x, y);
			break;
		default:
			cout << "wrong task number" << endl;
	}

    return 0;
}
