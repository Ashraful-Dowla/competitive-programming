//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1851/problem/D
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

	vector<ll> v(n - 1);

	for (int i = 0; i < n - 1; ++i) {
		cin >> v[i];
	}

	ll sum = n * 1LL * (n + 1);
	sum /= 2;

	if (v[n - 2] > sum) {
		cout << "NO" << endl;
	}
	else if (v[n - 2] == sum) {

		vector<ll> a;

		a.push_back(v[0]);
		for (int i = n - 2; i >= 1; --i) {
			a.push_back(v[i] - v[i - 1]);
		}

		map<ll, bool> vis;
		for (ll x : a) {
			vis[x] = true;
		}

		vector<ll> mis;

		for (int i = 1; i <= n; ++i) {
			if (!vis[i]) {
				mis.push_back(i);
			}
		}

		if (mis.size() != 2) {
			cout << "NO" << endl;
			return ;
		}

		for (ll x : a) {
			if (mis[0] + mis[1] == x) {
				cout << "YES" << endl;
				return ;
			}
		}

		cout << "NO" << endl;
	}
	else {

		v.push_back(sum);

		vector<ll> a;
		for (int i = n - 1; i >= 1; --i) {
			a.push_back(v[i] - v[i - 1]);
		}

		a.push_back(v[0]);
		vector<bool> vis(n + 1, false);

		for (ll x : a) {
			if (x > n || vis[x]) {
				cout << "NO" << endl;
				return ;
			}
			vis[x] = true;
		}

		for (int i = 1; i <= n; ++i) {
			if (vis[i]) continue;
			cout << "NO" << endl;
			return ;
		}

		cout << "YES" << endl;
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