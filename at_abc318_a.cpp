/*
https://atcoder.jp/contests/abc318/tasks/abc318_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, p;

	cin >> n >> m >> p;

	int st = m, cnt = 0;

	while (st <= n) {
		cnt++;
		st += p;
	}

	cout << cnt << endl;
}