/*
https://atcoder.jp/contests/abc278/tasks/abc278_b
*/
#include <bits/stdc++.h>
using namespace std;

bool check(string h, string m) {
	return stoi(h) >= 0 && stoi(h) < 24 && stoi(m) >= 0 && stoi(m) < 60;
}

int main() {

	string h, m;
	cin >> h >> m;

	if (h.size() == 1) {
		h.push_back('0');
		swap(h[0], h[1]);
	}

	if (m.size() == 1) {
		m.push_back('0');
		swap(m[0], m[1]);
	}

	swap(h[1], m[0]);

	if (check(h, m)) {
		swap(h[1], m[0]);
		cout << h << " " << m << endl;
	}
	else {
		swap(h[1], m[0]);
		for (int i = 1; i < 24; ++i) {
			int k = (stoi(h) + i) % 24;

			string q = "00";

			string p = to_string(k);

			if (p.size() == 1) {
				p.push_back('0');
				swap(p[0], p[1]);
			}

			swap(p[1], q[0]);

			if (check(p, q)) {
				swap(p[1], q[0]);
				cout << p << " " << q << endl;
				break;
			}
		}
	}
}