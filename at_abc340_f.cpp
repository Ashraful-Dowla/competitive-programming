/*
https://atcoder.jp/contests/abc340/tasks/abc340_f
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct triplet
{
	ll gcd, x, y;
};

triplet extend_eulcid(ll a, ll b) {

	if (b == 0) {
		triplet res;
		res.x = 1;
		res.gcd = a;
		res.y = 0;

		return res;
	}


	triplet res = extend_eulcid(b, a % b);
	triplet ans;

	ans.x = res.y;
	ans.gcd = res.gcd;
	ans.y = res.x - (a / b) * res.y;

	return ans;

}

int main() {

	ll x, y;
	cin >> x >> y;

	ll gcd = __gcd(abs(x), abs(y));

	if (gcd > 2) {
		cout << -1 << endl;
	}
	else {

		triplet ans = extend_eulcid(abs(y), abs(x));

		ll a = ans.x * (2 / gcd);
		ll b = ans.y * (2 / gcd);

		if (x < 0) {
			b *= -1;
		}
		if (y < 0) {
			a *= -1;
		}

		cout << a << " " << -b << endl;
	}


}