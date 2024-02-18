/*
https://atcoder.jp/contests/abc291/tasks/abc291_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	multiset<int> ms;

	for (int i = 0; i < 5 * n; ++i) {
		int x;
		cin >> x;
		ms.insert(x);
	}

	for (int i = 0; i < n; ++i) {
		auto it = ms.begin();
		ms.erase(it);
	}

	for (int i = 0; i < n; ++i) {
		auto it = (--ms.end());
		ms.erase(it);
	}


	double ans = 0;
	for (int x : ms) {
		ans += x;
	}

	int sz = ms.size();
	ans /= (1.0 * sz);
	cout << ans << endl;
}