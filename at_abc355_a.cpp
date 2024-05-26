/*
https://atcoder.jp/contests/abc355/tasks/abc355_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	vector<int> v(4, true);
	int a, b;
	cin >> a >> b;

	v[a] = v[b] = false;

	int ans = 0;
	for (int i = 1; i <= 3; ++i) {
		if (v[i]) {
			ans++;
		}
	}

	cout << (ans == 1 ? 6 - (a + b) : -1) << endl;
}