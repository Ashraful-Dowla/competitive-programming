/*
https://atcoder.jp/contests/abc368/tasks/abc368_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	multiset<int> ms;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		ms.insert(x);
	}

	int k = 0;
	while (true) {
		auto it = (--ms.end());
		auto t = (--ms.end());
		auto it2 = --t;
		int x = *it, y = *it2;

		if (x == 0 || y == 0) {
			cout << k << endl;
			break;
		}

		--x, --y;
		ms.erase(it);
		ms.erase(it2);
		ms.insert(x);
		ms.insert(y);
		++k;
	}

}