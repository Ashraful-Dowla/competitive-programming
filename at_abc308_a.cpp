/*
https://atcoder.jp/contests/abc308/tasks/abc308_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	vector<int> v(8);

	for (int i = 0; i < 8; ++i) {
		cin >> v[i];
	}

	for (int i = 0; i + 1 < 8; ++i) {
		if (v[i] <= v[i + 1]) {
			continue;
		}
		cout << "No" << endl;
		return 0;
	}

	for (int i = 0; i < 8; ++i) {
		if (v[i] >= 100 && v[i] <= 675 && v[i] % 25 == 0) {
			continue;
		}
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
}