//Author: Ashraful Dowla
/*
https://codeforces.com/contest/2001/problem/D
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	int n;
	cin >> n;

	int a[n];

	map<int, int> lst_idx;
	map<int, bool> vis;
	set<int> s;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		lst_idx[a[i]] = i;
		s.insert(a[i]);
	}

	multiset<int> ms = {a[0]};

	cout << s.size() << endl;
	for (int l = 0, r = 0, cur = 1; cur <= s.size(); ++cur) {

		while (r + 1 < n && (vis[a[r]] || lst_idx[a[r]] != r)) {
			++r;
			if (!vis[a[r]]) {
				ms.insert(a[r]);
			}
		}

		int nxt = (cur % 2 == 0 ? *ms.begin() : *ms.rbegin());
		cout << nxt << " ";

		while (l < r && a[l] != nxt) {
			if (!vis[a[l]]) {
				ms.erase(ms.find(a[l]));
			}
			++l;
		}
		vis[nxt] = true;
		ms.erase(nxt);
	}
	cout << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}