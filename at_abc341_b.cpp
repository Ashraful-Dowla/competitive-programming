#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	cin >> n;

	ll a[n];

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}


	ll s[n - 1], t[n - 1];

	for (int i = 0; i < n - 1; ++i) {
		cin >> s[i] >> t[i];
	}

	for (int i = 0; i < n - 1; ++i) {
		ll p = a[i] / s[i];
		a[i + 1] += p * t[i];
	}

	cout << a[n - 1] << endl;
}