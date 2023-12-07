/*
https://atcoder.jp/contests/abc308/tasks/abc308_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node {
	int idx;
	ll h, t;
};

bool cmp(node a, node b) {
	if (a.h * b.t == b.h * a.t) {
		return a.idx < b.idx;
	}
	return a.h * b.t > b.h * a.t;
}

int main() {
	int n;
	cin >> n;

	vector<node> v;
	for (int i = 1; i <= n; ++i) {
		ll h, t;
		cin >> h >> t;

		v.push_back({i, h, h + t});
	}

	sort(v.begin(), v.end(), cmp);

	for (auto p : v) {
		cout << p.idx << " ";
	}
	cout << endl;
}