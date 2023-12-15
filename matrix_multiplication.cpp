#include <bits/stdc++.h>
using namespace std;

// time complexity -> O(N^3)
// (n*m)* (m*p) = (n*p)

int main() {

	int n = 3, m = 2, p = 2;
	int a[n][m] = {
		{1, 4},
		{3, 9},
		{8, 6}
	};

	int b[m][p] = {
		{1, 6},
		{2, 9}
	};


	int c[n][p];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < p; ++j) {
			c[i][j] = 0;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < p; ++j) {
			for (int k = 0; k < m; ++k) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < p; ++j) {
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
}