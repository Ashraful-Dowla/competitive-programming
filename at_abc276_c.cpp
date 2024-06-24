/*
https://atcoder.jp/contests/abc276/tasks/abc276_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;


	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	while (prev_permutation(v.begin(), v.end())) {
		for (int x : v) {
			cout << x << " ";
		}
		cout << endl;
		break;
	}
}