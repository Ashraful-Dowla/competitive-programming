/*
https://atcoder.jp/contests/abc278/tasks/abc278_a
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

	for (int i = 0; i < k; ++i) {
		q.pop();
		q.push(0);
	}

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}