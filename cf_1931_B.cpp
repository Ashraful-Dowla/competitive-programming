//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1931/problem/B
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

	vector<ll> v(n);

	ll sum = 0;

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		sum += v[i];
	}

	ll avg = sum / n;
	ll hav = 0;

	for (int i = 0; i < n; ++i) {
		if (v[i] < avg) {
			hav -= (avg - v[i]);
			if (hav < 0) {
				cout << "NO" << endl;
				return ;
			}
		}
		else {
			hav += v[i] - avg;
		}
	}

	cout << "YES" << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}