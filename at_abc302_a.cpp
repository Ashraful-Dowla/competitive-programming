/*
https://atcoder.jp/contests/abc302/tasks/abc302_a
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	ll a, b;
	cin >> a >> b;

	ll ans = a / b;

	if (a % b) {
		ans++;
	}

	cout << ans << endl;
}