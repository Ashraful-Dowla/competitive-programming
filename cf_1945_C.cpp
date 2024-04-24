//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1945/problem/C
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define ll long long
#define ld long double
#define vi vector<int>
#define vs vector<string>
#define vb vector<bool>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>


#define pb push_back
#define eb emplace_back
#define all(c) (c).begin(),(c).end()

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"
#define prnt1(x) cout<<x<<endl
#define prnt2(x,y) cout<<x<<" "<<y<<endl

const int N = 1e5 + 10;
const int MOD = 1e9 + 7;

void solve() {

	int n;
	cin >> n;

	string s;
	cin >> s;

	s = "_" + s;

	int pf[n + 3] = {0};

	for (int i = 1; i <= n; ++i) {
		pf[i] = pf[i - 1] + (s[i] == '1');
	}

	vector<pair<int, int>> ans;
	for (int i = 0; i <= n; ++i) {
		int z = i - pf[i];
		int o = pf[n] - pf[i];

		if (z >= (i + 1) / 2 && o >= (n - i + 1) / 2) {
			ans.push_back({abs((n - 2 * i) / 2), i});
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans[0].second << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}