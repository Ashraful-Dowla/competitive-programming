/*
https://atcoder.jp/contests/abc343/tasks/abc343_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;

ll mp[N];
map<ll, int> cnt;

int main() {

	int n, m;
	cin >> n >> m;

	set<ll> s;
	int z = n;

	for (int i = 0; i < m; ++i) {
		int idx;
		ll x;
		cin >> idx >> x;

		if (mp[idx] == 0) {
			z--;
		}
		else {
			if (cnt[mp[idx]] == 1) {
				s.erase(mp[idx]);
			}
			cnt[mp[idx]]--;
		}

		mp[idx] += x;
		s.insert(mp[idx]);
		cnt[mp[idx]]++;

		cout << s.size() + (z > 0) << endl;
	}
}