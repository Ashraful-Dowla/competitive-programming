//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1955/problem/C
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

const int N = 2e5 + 10;
const int MOD = 1e9 + 7;

void solve() {

	int n;
	ll k;
	cin >> n >> k;

	deque<ll> dq;
	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		dq.push_back(x);
	}

	while (dq.size() > 1 && k > 0) {

		ll mn = min(dq.front(), dq.back());

		if (k >= 2 * mn) {
			k -= 2 * mn;
			dq.front() -= mn;
			dq.back() -= mn;
		}
		else {
			dq.front() -= (k / 2) + (k % 2);
			dq.back() -= (k / 2);
			k = 0;
		}

		if (dq.front() == 0) {
			dq.pop_front();
		}
		if (dq.back() == 0) {
			dq.pop_back();
		}
	}

	cout << n - dq.size() + (dq.size() && dq.front() <= k) << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}