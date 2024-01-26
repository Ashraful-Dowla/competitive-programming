/*
https://atcoder.jp/contests/abc337/tasks/abc337_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;
	unordered_map<int, int> mp;

	for (int i = 1; i <= n; ++i) {
		int v;
		cin >> v;
		mp[v] = i;
	}

	int v = -1;
	while (mp[v]) {
		cout << mp[v] << " ";
		v = mp[v];
	}
}