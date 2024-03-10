/*
https://atcoder.jp/contests/abc344/tasks/abc344_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	vector<int> v;
	while (true) {
		int x;
		cin >> x;
		v.push_back(x);
		if (x == 0) break;
	}

	for (int i = v.size() - 1; i >= 0; --i) {
		cout << v[i] << endl;
	}
}