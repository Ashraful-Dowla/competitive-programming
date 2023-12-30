//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1915/problem/E
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
	vector<ll> v(n + 1);

	for (int i = 1; i <= n; ++i) {
		cin >> v[i];

		if (i % 2 == 0) {
			v[i] *= -1;
		}
	}

	map<ll, bool> mp;

	ll sum = 0;
	for (int i = 1; i <= n; ++i) {

		sum += v[i];
		if (mp[sum]) {
			cout << "YES" << endl;
			return ;
		}

		mp[sum] = true;
	}

	cout << (mp[0] ? "YES" : "NO") << endl;

}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}