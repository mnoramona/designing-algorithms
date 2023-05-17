#include <cstdint>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

vector<int> ReadVector(istream& is, int size) {
    vector<int> vec(size);
    for (auto& num : vec) {
        is >> num;
    }
    return vec;
}

// functie auxiliara care afiseaza vectorii a si b
void PrintVector(const vector<int>& vec, ostream& os) {
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << " ";
    }
    os << "\n";
}


int64_t SolveTask1(const vector<int>& a, const vector<int>& b) {
    // formeaza vectorul c prin concatenarea lui a si b
    auto c = a;
    c.insert(c.end(), b.begin(), b.end());

    // 2 * n
    int64_t len = c.size();
    // sorteaza vectorul c descrescator

    sort(c.begin(), c.end(), greater<int>());
    int64_t res = 0;
    // aduna primele n elemente din c = suma maximelor
    for (int i = 0; i < len / 2; i++) {
        res += c[i];
    }
    return res;
}

int64_t SolveTask2(const vector<int>& a, const vector<int>& b, int moves) {
    return 0;
}

int main() {
    ifstream fin("nostory.in");
    ofstream fout("nostory.out");

    int task;
    fin >> task;

    uint64_t n, moves;
    if (task == 1) {
        fin >> n;
    } else {
        fin >> n >> moves;
    }

    auto a = ReadVector(fin, n);
    auto b = ReadVector(fin, n);

    auto res = task == 1 ? SolveTask1(a, b) : SolveTask2(a, b, moves);
    fout << res << "\n";

    return 0;
}
