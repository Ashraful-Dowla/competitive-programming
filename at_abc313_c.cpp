/*
https://atcoder.jp/contests/abc313/tasks/abc313_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	cin >> n;

	ll sum = 0;

	vector<ll> vec(n);

	for (int i = 0; i < n; ++i) {
		cin >> vec[i];
		sum += vec[i];
	}

	sort(vec.begin(), vec.end());

	vector<ll> res(n, sum / n);


	for (int i = 0; i < sum % n; ++i) {
		res[n - 1 - i]++;
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += abs(vec[i] - res[i]);
	}

	cout << ans / 2 << endl;
}