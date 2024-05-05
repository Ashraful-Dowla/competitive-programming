//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1851/problem/A
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

	int n, m, k, H;
	cin >> n >> m >> k >> H;

	int h[n];
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			bool ok = false;
			for (int l = j + 1; l < m; ++l) {
				int d = (l - j) * k;
				if (H + d == h[i] || H == d + h[i]) {
					ans++;
					ok = true;
					break;
				}
			}
			if (ok) {
				break;
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