/*
https://atcoder.jp/contests/abc323/tasks/abc323_b
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

bool cmp(pii a, pii b) {

	if (a.second == b.second) {
		return a.first < b.first;
	}

	return a.second > b.second;
}

int main() {
	int n;
	cin >> n;

	vector<pii> vec;
	for (int i = 0; i < n; ++i) {
		int win = 0;
		for (int j = 0; j < n; ++j) {
			char ch;
			cin >> ch;

			if (ch == 'o') {
				win++;
			}
		}

		vec.push_back({i, win});
	}

	sort(vec.begin(), vec.end(), cmp);

	for (auto p : vec) {
		cout << p.first + 1 << " ";
	}
	cout << endl;
}