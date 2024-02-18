/*
https://atcoder.jp/contests/abc293/tasks/abc293_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> vvll;

vvll multiply(vvll &a, vvll &b, ll m) {

	vvll res(2, vector<ll>(2, 0LL));

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) {
				res[i][j] += a[i][k] * b[k][j];
				res[i][j] %= m;
			}
		}
	}

	return res;
}

vvll matrix_exp(vvll a, ll b, ll m) {

	vvll res(2, vector<ll>(2));

	for (int i = 0; i < 2; i++) {
		res[i][i] = 1;
	}

	while (b) {
		if (b & 1) {
			res = multiply(res, a, m);
		}
		a = multiply(a, a, m);
		b >>= 1;
	}

	return res;
}


int main() {

	ll a, x, m;
	cin >> a >> x >> m;

	vvll matrix = {
		{a, 1LL},
		{0LL, 1LL}
	};

	vvll ans = matrix_exp(matrix, x, m);
	cout << ans[0][1] << endl;

}