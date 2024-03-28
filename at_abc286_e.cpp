/*
https://atcoder.jp/contests/abc286/tasks/abc286_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e9;
const int N = 305;

ll matrix[N][N], a[N], sov[N][N];

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<string> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (s[i][j] == 'Y') {
				matrix[i][j] = 1;
				sov[i][j] = a[j];
			}
			else {
				matrix[i][j] = INF;
			}
		}
	}

	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][k] + matrix[k][j] < matrix[i][j]) {
					matrix[i][j] = matrix[i][k] + matrix[k][j];
					sov[i][j] = sov[i][k] + sov[k][j];
				}
				else if (matrix[i][k] + matrix[k][j] == matrix[i][j]) {
					sov[i][j] = max(sov[i][j], sov[i][k] + sov[k][j]);
				}
			}
		}
	}

	int q;
	cin >> q;

	while (q--) {
		int u, v;
		cin >> u >> v;

		--u, --v;

		if (matrix[u][v] == INF) {
			cout << "Impossible" << endl;
		}
		else {
			cout << matrix[u][v] << " " << sov[u][v] + a[u] << endl;
		}
	}
}