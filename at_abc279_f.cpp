/*
https://atcoder.jp/contests/abc279/tasks/abc279_f
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int parent[N], sz[N], inv[N], pos[N];


void make(int n) {
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
		sz[i] = 1;
		inv[i] = i;
		pos[i] = i;
	}
}

int find(int v) {
	if (v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}

void Union(int a, int b) {

	a = find(a);
	b = find(b);

	if (a != b) {
		if (sz[a] < sz[b]) {
			swap(a, b);
		}
		parent[b] = a;
		sz[a] += sz[b];
	}
}

int main() {

	int n, q;
	cin >> n >> q;

	make(n + q + 100);

	int balls = n + 1;
	while (q--) {

		int t;
		cin >> t;

		if (t == 1) {
			int x, y;
			cin >> x >> y;

			if (inv[y] == -1) {
				continue;
			}
			else if (inv[x] != -1) {

				int rx = inv[x];
				int ry = inv[y];

				Union(rx, ry);

				int r = find(rx);
				pos[r] = x;
				inv[x] = r;

				inv[y] = -1;
			}
			else {
				int ry = inv[y];
				inv[y] = -1;

				int r = find(ry);
				pos[r] = x;
				inv[x] = r;
			}
		}
		else if (t == 2) {

			int x;
			cin >> x;

			if (inv[x] != -1) {

				int rx = inv[x];
				Union(rx, balls);

				int r = find(rx);

				pos[r] = x;
				inv[x] = r;
			}
			else {
				pos[balls] = x;
				inv[x] = balls;
			}

			balls++;
		}
		else {

			int x;
			cin >> x;

			cout << pos[find(x)] << endl;
		}
	}
}