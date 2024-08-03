/*
https://atcoder.jp/contests/abc360/tasks/abc360_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	cin >> n;
	ll t;
	cin >> t;

	string s;
	cin >> s;

	vector<ll> right, left;

	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;

		if (s[i] == '1') {
			right.push_back(x);
		}
		else {
			left.push_back(x);
		}
	}

	sort(right.begin(), right.end());
	sort(left.begin(), left.end());

	int l = 0, r = 0;
	ll ans = 0;

	for (int i = 0; i < right.size(); ++i) {

		while (l < left.size() && right[i] > left[l]) {
			l++;
		}
		while (r < left.size() && left[r] <= right[i] + 2 * t) {
			r++;
		}

		ans += r - l;
	}

	cout << ans << endl;
}