/*
https://atcoder.jp/contests/abc324/tasks/abc324_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<int> cnt(10);

	for (char &ch : s) {
		cnt[ch - '0']++;
	}

	ll ans = 0;
	for (ll i = 0; i <= 1e7; ++i) {
		string num = to_string(i * i);

		vector<int> mp(10);

		for (char &ch : num) {
			mp[ch - '0']++;
		}

		mp[0] = max(cnt[0], mp[0]);

		if (mp == cnt) {
			ans++;
		}
	}

	cout << ans << endl;
}