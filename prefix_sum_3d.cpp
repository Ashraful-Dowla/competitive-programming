#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int pf[N][N][N];

int main() {

	int n;
	cin >> n;

	int a[n + 1][n + 1][n + 1];

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				cin >> a[i][j][k];
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				pf[i][j][k]  = pf[i - 1][j][k] + pf[i][j - 1][k] + pf[i][j][k - 1]
				               - pf[i - 1][j - 1][k] - pf[i - 1][j][k - 1]
				               - pf[i][j - 1][k - 1] + pf[i - 1][j - 1][k - 1] + a[i][j][k];
			}
		}
	}

	int q;
	cin >> q;

	while (q--) {
		int lx, rx, ly, ry, lz, rz;
		cin >> lx >> rx >> ly >> ry >> lz >> rz;
		
		cout << pf[rx][ry][rz] - pf[lx - 1][ry][rz] - pf[rx][ly - 1][rz]
		     - pf[rx][ry][lz - 1] + pf[lx - 1][ly - 1][rz] + pf[lx - 1][ry][lz - 1]
		     + pf[rx][ly - 1][lz - 1] - pf[lx - 1][ly - 1][lz - 1] << endl;
	}

}