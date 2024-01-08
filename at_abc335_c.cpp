/*
https://atcoder.jp/contests/abc335/tasks/abc335_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, q;
	cin >> n >> q;

	deque<pair<int, int>> dq;

	for (int i = 1; i <= n; ++i) {
		dq.push_back({i, 0});
	}

	while (q--) {
		int t;
		cin >> t;

		if (t == 1) {
			char c;
			cin >> c;

			auto p = dq.front();

			if (c == 'U') {
				p.second++;
			}
			else if (c == 'D') {
				p.second--;
			}
			else if (c == 'L') {
				p.first--;
			}
			else {
				p.first++;
			}

			dq.push_front(p);
			dq.pop_back();
		}
		else {
			int p;
			cin >> p;

			auto d = dq.at(p - 1);
			cout << d.first << " " << d.second << endl;
		}
	}
}