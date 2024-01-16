/*
https://cses.fi/problemset/task/1083/
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int ans = 0;
	for (int i = 1; i < n; ++i) {
		int x;
		cin >> x;
		ans ^= x;
	}

	for (int i = 1; i <= n; ++i) {
		ans ^= i;
	}

	cout << ans << endl;
}