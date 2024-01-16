/*
https://atcoder.jp/contests/abc336/tasks/abc336_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	ll n;
	cin >> n;

	vector<int> v = {0, 2, 4, 6, 8};

	vector<int> ans;

	ans.push_back(v[(n - 1) % 5]);

	n = (n - 1) / 5;

	while (n) {
		ans.push_back(v[n % 5]);
		n /= 5;
	}

	reverse(ans.begin(), ans.end());

	for (int x : ans) {
		cout << x;
	}
	cout << endl;

}