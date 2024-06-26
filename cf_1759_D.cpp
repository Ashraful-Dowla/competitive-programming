//Author: Ashraful Dowla
/*
https://codeforces.com/problemset/problem/1759/D
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

	ll n, m;
	cin >> n >> m;

	ll n0 = n, k = 1;
	int cnt2 = 0, cnt5 = 0;

	while (n > 0 && n % 2 == 0) {
		cnt2++;
		n /= 2;
	}

	while (n > 0 && n % 5 == 0) {
		cnt5++;
		n /= 5;
	}

	while (cnt2 < cnt5 && k * 2 <= m) {
		cnt2++;
		k *= 2;
	}

	while (cnt5 < cnt2 && k * 5 <= m) {
		cnt5++;
		k *= 5;
	}

	while (k * 10 <= m) {
		k *= 10;
	}

	if (k == 1) {
		cout << n0*m << endl;
	}
	else {
		k *= (m / k);
		cout << n0*k << endl;
	}
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}