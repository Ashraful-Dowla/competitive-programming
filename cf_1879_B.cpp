//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1879/problem/B
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

	ll sum_a = 0, mn_a = MOD;
	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		sum_a += x;
		mn_a = min(mn_a, x);
	}


	ll sum_b = 0, mn_b = MOD;
	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		sum_b += x;
		mn_b = min(mn_b, x);
	}

	cout << (min(sum_a + mn_b * n, sum_b + mn_a * n)) << endl;

}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}