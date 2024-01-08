/*
https://atcoder.jp/contests/abc298/tasks/abc298_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll M = 998244353;

ll binaryExp(ll a, int b) {

	ll res = 1;

	while (b) {
		if (b & 1) {
			res = (res * a) % M;
		}
		a = (a * a) % M;
		b >>= 1;
	}

	return res;
}

int main() {

	int t;
	cin >> t;

	queue<int>q;

	q.push(1);

	ll res = 1;

	while (t--) {

		int tt;
		cin >> tt;

		if (tt == 1) {
			int x;
			cin >> x;
			q.push(x);
			res = (res * 10 + x * 1LL) % M;

		}
		else if (tt == 2) {
			int x = q.front();
			q.pop();
			res = (res - (x * 1LL * binaryExp(10, q.size())) % M + M) % M;
		}
		else {
			cout << res << endl;
		}
	}
}