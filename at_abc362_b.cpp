/*
https://atcoder.jp/contests/abc362/tasks/abc362_b
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dis(ll x1, ll y1, ll x2, ll y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {

	ll xa, ya, xb, yb, xc, yc;

	cin >> xa >> ya;
	cin >> xb >> yb;
	cin >> xc >> yc;

	ll ab = dis(xa, ya, xb, yb);
	ll ac = dis(xa, ya, xc, yc);
	ll bc = dis(xb, yb, xc, yc);

	if (ab + ac == bc || ab + bc == ac || ac + bc == ab) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}