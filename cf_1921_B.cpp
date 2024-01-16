//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1921/problem/B
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

	string s, f;
	cin >> s;
	cin >> f;

	int oz = 0, zo = 0;

	for (int i = 0; i < n; ++i) {
		if (s[i] != f[i]) {
			if (s[i] == '1') oz++;
			else zo++;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] != f[i]) {
			if (s[i] == '1' && oz > 0) {
				if (zo > 0) zo--;
				ans++;
				oz--;
			}
			else if (s[i] == '0' && zo > 0) {
				if (oz > 0) oz--;
				ans++;
				zo--;
			}
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