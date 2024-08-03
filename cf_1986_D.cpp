//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1986/problem/D
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long ll;
vector<int> temp;
ll dp[25];

ll resolve(int i) {

	if (i >= temp.size()) {
		return 0;
	}
	if (dp[i] != -1) return dp[i];

	ll ans = LLONG_MAX, curr = 1;
	for (int j = i; j < temp.size(); ++j) {
		if (curr < LLONG_MAX / (temp[j] == 0 ? 1 : temp[j])) {
			curr *= temp[j];
		}
		ans = min(ans, curr + resolve(j + 1));
	}

	return dp[i] = ans;
}

void solve() {

	int n;
	cin >> n;
	string s;
	cin >> s;

	ll ans = LLONG_MAX;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				temp.push_back(stoi(s.substr(j, 2)));
				j++;
			}
			else {
				temp.push_back((s[j] - '0'));
			}
		}

		for (int j = 0; j <= n; ++j) {
			dp[j] = -1;
		}

		ans = min(ans, resolve(0));
		temp.clear();
	}

	cout << ans << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}