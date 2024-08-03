/*
https://atcoder.jp/contests/abc360/tasks/abc360_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> a(n), w(n);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	map<int, vector<int>>mp;
	for (int i = 0; i < n; ++i) {
		cin >> w[i];
		mp[a[i]].push_back(w[i]);
	}

	long long sum = 0;
	for (auto p : mp) {
		vector<int> &v = mp[p.first];
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size() - 1; ++i) {
			sum += v[i];
		}
	}

	cout << sum << endl;

}