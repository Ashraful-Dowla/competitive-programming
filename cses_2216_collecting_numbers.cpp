/*
https://cses.fi/problemset/task/2216
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N];

int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		a[x] = i;
	}

	int ans = 1;
	for (int i = 2; i <= n; ++i) {
		if (a[i - 1] > a[i]) {
			ans++;
		}
	}

	cout << ans << endl;
}