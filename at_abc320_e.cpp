/*
https://atcoder.jp/contests/abc320/tasks/abc320_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node {
	ll t, w, s;
};

struct cmp {
	bool operator()(node a, node b) {
		if (a.t == b.t) {
			if (a.w == b.w) {
				return !(a.s < b.s);
			}
			return !(a.w < b.w);
		}
		return !(a.t < b.t);
	}
};

int main() {

	int n, m;
	cin >> n >> m;

	priority_queue<node, vector<node>, cmp> pq;

	for (int i = 0; i < m; ++i) {
		ll t, w, s;
		cin >> t >> w >> s;
		pq.push({t, w, s});
	}

	set<int> ms;

	for (int i = 1; i <= n; ++i) {
		ms.insert(i);
	}

	ll ans[n + 1] = {0};

	while (pq.size() > 0) {

		auto v = pq.top();
		ll t = v.t, w = v.w, s = v.s;
		pq.pop();

		if (w == -1) {
			ms.insert(s);
		}
		else if (ms.size()) {
			ans[*ms.begin()] += w;
			pq.push({t + s, -1, *ms.begin()});
			ms.erase(ms.begin());
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << endl;
	}

}