/*
https://atcoder.jp/contests/abc344/tasks/abc344_e
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

map<int, int> f, b;
vector<int> v(N);

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	for (int i = 0; i + 1 < n; ++i) {
		f[v[i]] = v[i + 1];
		b[v[i + 1]] = v[i];
	}

	int q;
	cin >> q;

	int st = v[0];
	while (q--) {
		int t;
		cin >> t;

		if (t == 1) {
			int x, y;
			cin >> x >> y;

			int xf = f[x];
			b[xf] = 0;
			f[x] = 0;

			b[xf] = y;
			f[y] = xf;

			b[y] = x;
			f[x] = y;
		}
		else {
			int x;
			cin >> x;

			if (b[x] == 0) {
				int xf = f[x];

				b[xf] = 0;
				f[x] = 0;
				st = xf;
			}
			else if (f[x] == 0) {
				int xb = b[x];
				f[xb] = 0;
				b[x] = 0;
			}
			else {
				int xb = b[x], xf = f[x];

				b[x] = 0;
				f[x] = 0;

				f[xb] = xf;
				b[xf] = xb;
			}
		}
	}

	while (st > 0) {
		cout << st << " ";
		st = f[st];
	}
	cout << endl;
}