//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1977/problem/B
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long ll;

void solve() {

	ll n;
	cin >> n;

	vector<int> b;
	for (int i = 31; i >= 0; --i) {
		b.push_back(((n >> i) & 1LL));
	}

	vector<int> ans;
	for (int i = 31; i >= 0; --i) {
		int ct = 0;

		while (i >= 0 && b[i] == 1) {
			ct++;
			--i;
		}

		if (ct > 1) {
			ans.push_back(-1);
			for (int j = 0; j < ct - 1; ++j) {
				ans.push_back(0);
			}
			b[i] = 1;
			++i;
		}
		else if (ct == 1) {
			ans.push_back(1);
			++i;
		}
		else {
			ans.push_back(0);
		}
	}

	cout << ans.size() << endl;
	for (int x : ans) {
		cout << x << " ";
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