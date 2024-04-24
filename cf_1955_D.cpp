//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1955/problem/D
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

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> a(n), b(m);

	map<int, int> mp;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < m; ++i) {
		cin >> b[i];
		mp[b[i]]++;
	}


	int kk = 0;
	for (int i = 0; i < m; ++i) {
		if (mp.find(a[i]) != mp.end()) {
			mp[a[i]]--;
			if (mp[a[i]] >= 0) {
				kk++;
			}
		}
	}

	int ans = 0;
	if (kk >= k) {
		ans++;
	}

	for (int i = m; i < n; ++i) {
		if (mp.find(a[i - m]) != mp.end()) {
			mp[a[i - m]]++;
			if (mp[a[i - m]] > 0) {
				kk--;
			}
		}
		if (mp.find(a[i]) != mp.end()) {
			mp[a[i]]--;
			if (mp[a[i]] >= 0) {
				kk++;
			}
		}

		if (kk >= k) {
			ans++;
		}
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