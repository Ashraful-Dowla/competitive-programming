/*
https://atcoder.jp/contests/abc365/tasks/abc365_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i].first;
		v[i].second = i + 1;
	}

	sort(v.begin(), v.end());

	cout << v[n - 2].second << endl;
}