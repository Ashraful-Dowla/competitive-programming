//Author: Ashraful Dowla
/*
https://codeforces.com/contest/624/problem/A
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

const double eps = 1e-6;

void solve() {

	double d, l, v1, v2;
	cin >> d >> l >> v1 >> v2;

	double ans = 0, lo = 0, hi = 1e9;
	while (hi - lo > eps) {

		double mid = (lo + hi) / 2.0;
		if ((l - d) >= (v1 + v2)*mid) {
			ans = max(ans, mid);
			lo = mid;
		}
		else {
			hi = mid;
		}
	}

	cout << fixed << setprecision(10) << ans << endl;
}

int main() {
	Faster;

	int t = 1;

	while (t--) {
		solve();
	}
}