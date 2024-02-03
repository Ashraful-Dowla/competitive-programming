//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1918/problem/C
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


	ll a, b, r;
	cin >> a >> b >> r;

	if (a > b) swap(a, b);

	ll x = 0LL;
	bool fb = true;

	for (int i = 60; i >= 0; --i) {

		ll ba = (a & (1LL << i)) > 0 ? 1 : 0;
		ll bb = (b & (1LL << i)) > 0 ? 1 : 0;

		if (ba != bb) {
			if (fb) {
				fb = false;
			}
			else if (bb && (x + (1LL << i)) <= r) {
				x |= (1LL << i);
			}
		}
	}

	cout << llabs((b ^ x) - (a ^ x)) << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}