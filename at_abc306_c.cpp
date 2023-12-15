/*
https://atcoder.jp/contests/abc306/tasks/abc306_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {

	int n;
	cin >> n;

	vector<int> v[n + 5];
	for (int i = 1; i <= 3 * n; ++i) {
		int x;
		cin >> x;
		v[x].push_back(i);
	}

	vector<pii> vec;

	for (int i = 1; i <= n; ++i) {
		vec.push_back({v[i][1], i});
	}

	sort(vec.begin(), vec.end());

	for (auto p : vec) {
		cout << p.second << " ";
	}
	cout << endl;
}