/*
https://cses.fi/problemset/task/1617/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll M = 1e9 + 7;

ll binaryExp(ll a, ll b) {

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

	ll n;
	cin >> n;

	cout << binaryExp(2, n) << endl;
}