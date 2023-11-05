/*
https://atcoder.jp/contests/abc324/tasks/abc324_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	ll n;
	string t;

	cin >> n >> t;

	vector<string> v;

	for (ll i = 0; i < n; ++i) {
		string s;
		cin >> s;
		v.push_back(s);
	}


	vector<ll> fow, back;

	for (string &s : v) {

		ll j = 0;
		for (ll i = 0; i < s.size() && j < t.size(); ++i) {
			if (s[i] == t[j]) {
				++j;
			}
		}

		fow.push_back(j);
	}

	reverse(t.begin(), t.end());

	for (string s : v) {

		ll j = 0;
		for (ll i = s.size() - 1; i >= 0 && j < t.size(); --i) {
			if (s[i] == t[j]) {
				++j;
			}
		}

		back.push_back(j);
	}

	sort(back.begin(), back.end());

	ll ans = 0;
	for (ll x : fow) {

		auto it = lower_bound(back.begin(), back.end(), t.size() - x);

		ll k = it - back.begin();

		ans += (back.size() - k);

	}

	cout << ans << endl;
}