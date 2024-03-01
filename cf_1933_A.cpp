//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1933/problem/A
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


	ll ans = -1e9, sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		sum += v[i];
		ans = max(ans, sum);
	}

	sort(v.begin(), v.end());

	for (int l = 0; l < n; ++l) {
		for (int r = l; r < n; ++r) {
			sum = 0;
			for (int i = 0; i < n; ++i) {
				if (l <= i && i <= r) {
					sum -= v[i];
				}
				else {
					sum += v[i];
				}
			}
			ans = max(ans, sum);
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