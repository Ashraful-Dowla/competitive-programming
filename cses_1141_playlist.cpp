/*
https://cses.fi/problemset/task/1141/
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N];

int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	map<int, int>mp;

	int ans = 1, st = 0;
	for (int i = 1; i <= n; ++i) {
		if (mp[a[i]] > st) {
			st = mp[a[i]];
		}
		ans = max(ans, i - st);
		mp[a[i]] = i;
	}

	cout << ans << endl;
}