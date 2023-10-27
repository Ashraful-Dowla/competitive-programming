//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1883/problem/E
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


/*
	2^y * a(i-1) <= 2^x * ai
	2^x * ai >= 2^y *a(i-1)
	2^x /2^y >= a(i-1)/ai
	2^(x-y) >=  a(i-1)/ai

	(x-y)log2(2) >= log2(a(i-1)/ai)
	x >= y + log2(a(i-1)/ai)
*/

void solve() {
	int n;
	cin >> n;

	vector<ll> vec(n);

	for (int i = 0; i < n; ++i) {
		cin >> vec[i];
	}

	ll ans = 0, y = 0;
	for (int i = 1; i < n; ++i) {
		ll curr = ceil(log2(1.0 * vec[i - 1] / vec[i]));
		y = max(0LL, curr + y);
		ans += y;
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