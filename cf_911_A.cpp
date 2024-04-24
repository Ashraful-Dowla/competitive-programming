//Author: Ashraful Dowla
/*
https://codeforces.com/contest/911/problem/A
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

	vi v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	int mn = *min_element(v.begin(), v.end());

	map<int, int> mp;

	int ans = INT_MAX;
	for (int i = 0; i < n; ++i) {
		if (mp.find(v[i]) == mp.end()) {
			mp[v[i]] = i;
		}
		else {
			if (v[i] == mn) {
				ans = min(ans, i - mp[v[i]]);
			}
			mp[v[i]] = i;
		}
	}

	cout << ans << endl;
}

int main() {
	Faster;

	solve();
}