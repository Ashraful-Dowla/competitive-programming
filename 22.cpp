/*
https://www.hackerrank.com/challenges/crush/problem
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
long long arr[N];

int main() {
	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b, k;
		cin >> a >> b >> k;
		arr[a] += k;
		arr[b + 1] -= k;
	}

	for (int i = 1; i <= n; i++) {
		arr[i] += arr[i - 1];
	}

	long long mx = -1;
	for (int i = 1; i <= n; i++) {
		mx = max(mx, arr[i]);
	}
	cout << mx << endl;
}