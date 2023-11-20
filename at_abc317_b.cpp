/*
https://atcoder.jp/contests/abc317/tasks/abc317_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> vec(n);

	for (int i = 0; i < n; ++i) {
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i + 1 < n; ++i) {
		if (vec[i + 1] - vec[i] == 2) {
			cout << vec[i] + 1 << endl;
			break;
		}
	}
}