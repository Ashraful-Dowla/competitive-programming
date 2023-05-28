#include <bits/stdc++.h>
using namespace std;


bool taken[10][10];

bool isValid(int n, int x, int y) {

	for (int row = 0; row < x; ++row) {
		if (taken[row][y]) {
			return false;
		}
	}

	int row = x, col = y;

	while (row >= 0 && col >= 0) {
		if (taken[row][col]) {
			return false;
		}
		row--, col--;
	}

	row = x, col = y;

	while (row >= 0 && col < n) {
		if (taken[row][col]) {
			return false;
		}
		row--, col++;
	}

	return true;
}


void prnt(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << taken[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

//time complexity -> O(N!)
void nqueen(int n, int x) {

	if (x == n) {
		prnt(n);
		return ;
	}

	for (int col = 0; col < n; ++col) {
		if (isValid(n, x, col)) {
			taken[x][col] = true;
			nqueen(n, x + 1);
			taken[x][col] = false;
		}
	}
}

int main() {
	int n;
	cin >> n;

	nqueen(n, 0);
}