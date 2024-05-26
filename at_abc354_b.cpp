/*
https://atcoder.jp/contests/abc354/tasks/abc354_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<string> v(n);

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> v[i] >> x;
		sum += x;
	}

	sort(v.begin(), v.end());
	cout << v[sum % n] << endl;
}