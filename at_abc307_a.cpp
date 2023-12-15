/*
https://atcoder.jp/contests/abc307/tasks/abc307_a
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;

	ll sum = 0;
	for (int i = 0; i < n * 7; ++i) {
		ll x;
		cin >> x;
		sum += x;

		if ((i + 1) % 7 == 0) {
			cout << sum << " ";
			sum = 0;
		}
	}

	cout << endl;
}