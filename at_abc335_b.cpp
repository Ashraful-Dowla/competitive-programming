/*
https://atcoder.jp/contests/abc335/tasks/abc335_b
*/
#include <bits/stdc++.h>
using namespace std;

struct node {
	int x, y, z;
};

bool cmp(node a, node b) {
	if (a.x == b.x) {
		if (a.y == b.y) {
			return a.z < b.z;
		}
		return a.y < b.y;
	}
	return a.x < b.x;
}

int main() {

	int n;
	cin >> n;

	vector<node> v;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; i + j <= n; ++j) {
			for (int k = 0; i + j + k <= n; ++k) {
				// cout << i << " " << j << " " << k << endl;
				v.push_back({i, j, k});
			}
		}
	}

	sort(v.begin(), v.end(), cmp);

	for (auto p : v) {
		cout << p.x << " " << p.y << " " << p.z << endl;
	}
}