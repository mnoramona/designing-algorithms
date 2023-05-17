#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int task1(int n, int m, int x, vector <int>& p, vector <vector <int> >& g) {
	int size = x * n;  // bugetul maxim

	// rezolvam problema cu DP
	vector<vector<int>> dp(m + 1, vector<int>(size + 1));

    // cazul de baza
    for (int k = 0; k <= size; k++) {
        dp[0][k] = 0;
    }

	// vector de note totale
	vector <int> total_grades(m, 0);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (g[j][i] >= 1) {
				total_grades[i] += g[j][i];
			}
		}
	}

	// cazul general
    for (int i = 1; i <= m; i++) {  // pentru fiecare fel de sushi
        for (int k = 0; k <= size; k++) {  // pentru fiecare optiune de buget
            dp[i][k] = dp[i - 1][k];  // presupunem ca nu il alegem

            if (k - p[i - 1] >= 0) {  // daca putem sa il alegem
				// alegem maximul dintre alegerea lui si alegerea lui fara el
                int sol_aux = dp[i - 1][k - p[i - 1]] + total_grades[i - 1];

                dp[i][k] = max(dp[i - 1][k], sol_aux);  // alegem maximul
            }
        }
    }
	return dp[m][size];  // returnam rezultatul
}

int task2(int n, int m, int x, vector<int>& p, vector<vector<int>>& g) {
    int size = n * x;  // bugetul maxim

    // vector de note totale
    vector<int> total_grades(m, 0);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (g[j][i] >= 1) {
                total_grades[i] += g[j][i];
            }
        }
    }

	// dublam vectorii
    total_grades.resize(m * 2 + 1);
    for (int i = 0; i < m; i++) {
        total_grades[i + m] = total_grades[i];
    }

    p.resize(m * 2 + 1);
    for (int i = 0; i < m; i++) {
        p[i + m] = p[i];
    }

	// rezolvam problema cu DP ca anterior,
	// doar ca modificam vectorii si dimensiunile
    vector<vector<int>> dp(2 * m + 1, vector<int>(size + 1));

    // cazul de baza
    for (int k = 0; k <= size; k++) {
        dp[0][k] = 0;
    }

    for (int i = 1; i <= 2 * m; i++) {
        for (int k = 0; k <= size; k++) {
            dp[i][k] = dp[i - 1][k];

            if (k - p[i - 1] >= 0) {
                int sol_aux = dp[i - 1][k - p[i - 1]] + total_grades[i - 1];
                dp[i][k] = max(dp[i - 1][k], sol_aux);
            }
        }
    }
    return dp[2 * m][size];
}


int task3(int n, int m, int x, vector<int> &p, vector<vector<int>> &g) {
    return 0;
}

int main() {
	freopen("sushi.in", "r", stdin);
	freopen("sushi.out", "w", stdout);

	int task;  // task number

	int n;  // number of friends
	int m;  // number of sushi types
	int x;  // how much each of you is willing to spend

	vector <int> prices;  // prices of each sushi type
	// the grades you and your friends gave to each sushi type
	vector <vector <int> > grades;

	cin >> task;
	cin >> n >> m >> x;

	prices.assign(m, 0);
	grades.assign(n, vector <int> (m, 0));

	// price of each sushi
	for(int i = 0; i < m; ++i) {
		cin >> prices[i];
	}

	// each friends rankings of sushi types
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> grades[i][j];
		}
	}

	int ans = -1;

	switch(task) {
		case 1:
			ans = task1(n, m, x, prices, grades);
			break;
		case 2:
			ans = task2(n, m, x, prices, grades);
			break;
		case 3:
			ans = task3(n, m, x, prices, grades);
			break;
		default:
			cout << "wrong task number" << endl;
	}
	cout << ans << endl;

	return 0;
}
