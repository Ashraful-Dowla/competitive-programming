/*
https://cses.fi/problemset/task/1091/
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<int> t(m);
	multiset<int> ms;

	for (int i = 0; i < n; ++i) {
		int h;
		cin >> h;

		ms.insert(h);
	}

	for (int i = 0; i < m; ++i) {
		cin >> t[i];
	}

	for (int i = 0; i < m; ++i) {

		auto it = ms.lower_bound(t[i]);

		if (it != ms.end()) {
			if (*it == t[i]) {
				cout << *it << endl;
				ms.erase(it);
			}
			else if (it != ms.begin()) {
				--it;
				cout << *it << endl;
				ms.erase(it);
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (it != ms.begin())  {
			--it;
			cout << *it << endl;
			ms.erase(it);
		}
		else {
			cout << -1 << endl;
		}
	}
}