/*
https://atcoder.jp/contests/abc337/tasks/abc337_d
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int solve(string s) {

	vector<int> sz, o;

	o.push_back(0);
	sz.push_back(0);

	int res = INT_MAX;
	for (int i = 0; i < s.size(); ++i) {

		if (s[i] == 'x') {

			for (int j = k; j < sz.size(); ++j) {
				int vo = o[j] - o[j - k];
				int vsz = sz[j] - sz[j - k];

				if (vsz >= k) {
					res = min(res, vsz - vo);
				}
			}

			o.clear();
			sz.clear();

			o.push_back(0);
			sz.push_back(0);

		}
		else if (s[i] == 'o') {

			int vo = o.back();
			int vsz = sz.back();

			o.push_back(vo + 1);
			sz.push_back(vsz + 1);
		}
		else {

			int vsz = sz.back();
			int vo = o.back();

			o.push_back(vo);
			sz.push_back(vsz + 1);
		}
	}

	for (int j = k; j < sz.size(); ++j) {
		int vo = o[j] - o[j - k];
		int vsz = sz[j] - sz[j - k];

		if (vsz >= k) {
			res = min(res, vsz - vo);
		}
	}

	return res;

}

int main() {

	cin >> n >> m >> k;

	char ch[n][m];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> ch[i][j];
		}
	}

	int ans = INT_MAX;

	for (int i = 0; i < n; ++i) {
		string s;
		for (int j = 0; j < m; ++j) {
			s.push_back(ch[i][j]);
		}

		ans = min(ans, solve(s));
	}

	for (int i = 0; i < m; ++i) {
		string s;
		for (int j = 0; j < n; ++j) {
			s.push_back(ch[j][i]);
		}

		ans = min(ans, solve(s));

	}

	cout << (ans == INT_MAX ? -1 : ans) << endl;

}