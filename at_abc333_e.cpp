/*
https://atcoder.jp/contests/abc333/tasks/abc333_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {

	int n;
	cin >> n;

	vector<pii> v(n);

	for (int i = 0; i < n; ++i) {
		int t, x;
		cin >> t >> x;
		v[i] = {t, x};
	}

	multiset<int> monsters;

	vector<pii> res;
	for (int i = n - 1; i >= 0; --i) {

		int t = v[i].first;
		int x = v[i].second;

		if (t == 1) {
			if (monsters.size()) {
				if (monsters.find(x) == monsters.end()) {
					res.push_back({i, 0});
				}
				else {
					monsters.erase(monsters.find(x));
					res.push_back({i, 1});
				}
			}
			else {
				res.push_back({i, 0});
			}
		}
		else {
			monsters.insert(x);
			res.push_back({i, -1});
		}
	}

	if (monsters.size()) {
		cout << -1 << endl;
	}
	else {

		reverse(res.begin(), res.end());

		multiset<int> potion;

		int k = 0;
		for (auto p : res) {

			int val = v[p.first].second;

			if (p.second == 1) {
				potion.insert(val);
				int sz = potion.size();
				k = max(k, sz);
			}
			else if (p.second == -1) {
				potion.erase(potion.find(val));
			}
		}

		cout << k << endl;
		for (auto p : res) {
			if (p.second == -1) continue;
			cout << p.second << " ";
		}
		cout << endl;

	}
}