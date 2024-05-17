/*
https://atcoder.jp/contests/abc353/tasks/abc353_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	queue<int> q;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		q.push(x);
	}

	int ans = 0;
	while (!q.empty()) {
		int sum = 0;
		while (!q.empty() && sum + q.front() <= k) {
			sum += q.front();
			q.pop();
		}
		if (sum > 0) {
			ans++;
		}
	}

	cout << ans << endl;
}