//Author: Ashraful Dowla
/*
https://codeforces.com/problemset/problem/1832/C
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

	vi v;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (v.empty() || v.back() != x) {
			v.pb(x);
		}
	}

	int cnt = 0;
	for (int i = 1; i < v.size() - 1; ++i) {
		if (v[i - 1] < v[i] && v[i] < v[i + 1]) cnt++;
		else if (v[i - 1] > v[i] && v[i] > v[i + 1]) cnt++;
	}

	prnt1(v.size() - cnt);
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}