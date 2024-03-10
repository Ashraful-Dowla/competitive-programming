//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1934/problem/C
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

ll n, m;

ll query(ll x, ll y) {

	cout << "? " << x << " " << y << endl;
	cout << flush;

	ll d;
	cin >> d;

	return d;
}

pll lower_axis(ll x, ll y, ll n, ll d) {

	x = x + min(n - 1, d);
	y = y + (d > n - 1 ? d - n + 1 : 0);

	return {x, y};
}

pll upper_axis(ll x, ll y, ll m, ll d) {

	y = y + min(m - 1, d);
	x = x + (d > m - 1 ? d - m + 1 : 0);

	return {x, y};
}

void solve() {

	cin >> n >> m;

	ll dd = query(1, 1);

	auto p = lower_axis(1, 1, n, dd);
	ll x1 = p.first, y1 = p.second;

	auto q = upper_axis(1, 1, m, dd);
	ll x2 = q.first, y2 = q.second;

	ll dxy1 = query(x1, y1);
	ll dxy2 = query(x2, y2);

	ll a = x1 - dxy1 / 2, b = y1 + dxy1 / 2;
	ll c = x2 + dxy2 / 2, d = y2 - dxy2 / 2;

	if (query(a, b) == 0) {
		cout << "! " << a << " " << b << endl;
	}
	else {
		cout << "! " << c << " " << d << endl;
	}

	cout << flush;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}