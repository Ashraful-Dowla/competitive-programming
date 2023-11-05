/*
https://atcoder.jp/contests/abc323/tasks/abc323_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> score(m);

	for (int i = 0; i < m; ++i) {
		cin >> score[i];
	}

	char ch[n][m];

	vector<int> points(n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> ch[i][j];

			if (ch[i][j] == 'o') {
				points[i] += score[j];
			}
		}

		points[i] += (i + 1);
	}

	int mx = *max_element(points.begin(), points.end());

	for (int i = 0; i < n; ++i) {

		vector<int> res;
		for (int j = 0; j < m; ++j) {
			if (ch[i][j] == 'x') {
				res.push_back(score[j]);
			}
		}

		sort(res.rbegin(), res.rend());

		int cnt = 0;
		while (points[i] < mx) {
			points[i] += res[cnt++];
		}

		cout << cnt << endl;
	}

}