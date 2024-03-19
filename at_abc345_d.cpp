/*
https://atcoder.jp/contests/abc345/tasks/abc345_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int, int>> vii;

int n, h, w;
vii v;

bool can() {

	vector<vector<bool>> matrix(h, vector<bool>(w, false));

	int idx = 0;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {

			if (matrix[i][j]) {
				continue;
			}

			if (idx == n) {
				return false;
			}

			int ch = v[idx].first, cw = v[idx].second;

			if (i + ch > h || j + cw > w) {
				return false;
			}

			for (int ii = 0; ii < ch; ++ii) {
				for (int jj = 0; jj < cw; ++jj) {
					if (matrix[i + ii][j + jj]) {
						return false;
					}
					matrix[i + ii][j + jj] = true;
				}
			}
			idx++;
		}
	}

	return true;
}

bool solve(int i) {

	if (i == n) {
		return can();
	}

	bool isPossible = solve(i + 1);

	swap(v[i].first, v[i].second);
	isPossible |= solve(i + 1);
	swap(v[i].first, v[i].second);

	return isPossible;
}

bool resolve() {

	sort(v.begin(), v.end());
	do {
		if (solve(0)) {
			return true;
		}
	} while (next_permutation(v.begin(), v.end()));

	return false;
}



int main() {

	cin >> n >> h >> w;

	v.assign(n, {0, 0});
	for (int i = 0; i < n; ++i) {
		cin >> v[i].first >> v[i].second;
	}

	cout << (resolve() ? "Yes" : "No") << endl;
}