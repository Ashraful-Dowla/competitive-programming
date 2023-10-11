/*
https://www.spoj.com/problems/MAS/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll M = 2760727302517;
ll sumA, sumB;

vector<ll>vec;

ll binaryMul(ll a, ll b) {
	ll ans = 0;
	while (b) {
		if (b & 1) ans = (ans + a) % M;
		a = (a + a) % M;
		b >>= 1;
	}

	return ans;
}

void sumOfSquareDiff(ll n) {
	for (int i = 0; i < n; ++i) {
		sumA = (sumA + vec[i] * vec[i]) % M;
		sumB = (sumB + vec[i]) % M;
	}
}

void add(ll p, ll val) {
	val %= M;
	sumA = (sumA + M - binaryMul(vec[p], vec[p])) % M;
	sumA = (sumA + binaryMul(val, val)) % M;

	sumB = (sumB + M - vec[p]) % M;
	sumB = (sumB + val) % M;

	vec[p] = val;
}

int main() {
	int t;
	cin >> t;
	int cse = 1;
	while (t--) {
		int x, n;
		sumA = 0, sumB = 0;
		vec.clear();
		cin >> x >> n;
		for (int i = 0; i < x; ++i) {
			ll val;
			cin >> val;
			vec.push_back(val);
		}

		sumOfSquareDiff(x);

		cout << "Case " << cse++ << ":" << endl;
		while (n--) {
			int a, b, c;
			cin >> a;
			if (a == 3) cout << (x * 1LL * sumA % M + M - binaryMul(sumB, sumB)) % M << endl;
			else {
				cin >> b >> c;
				if (a == 2) add(b - 1, vec[b - 1] + c);
				else add(b - 1, c);
			}
		}
	}
}
