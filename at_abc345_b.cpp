/*
https://atcoder.jp/contests/abc345/tasks/abc345_b
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	ll x;
	cin >> x;

	if (x > 0) {
		if (x % 10 == 0) cout << x / 10 << endl;
		else cout << (x + 10) / 10 << endl;
	}
	else {
		cout << x / 10 << endl;
	}
}