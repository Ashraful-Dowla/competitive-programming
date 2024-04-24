//Author: Ashraful Dowla
/*
https://codeforces.com/problemset/problem/872/B
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

	int n, k;
	cin >> n >> k;

	vi v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	if (k == 1) {
		cout << *min_element(v.begin(), v.end()) << endl;
	}
	else if (k == 2) {
		vector<int> pf(n), sf(n);
		for (int i = 0; i < n; ++i) {
			if (i == 0) {
				pf[i] = v[i];
			}
			else {
				pf[i] = min(pf[i - 1], v[i]);
			}
		}

		for (int i = n - 1; i >= 0; --i) {
			if (i == n - 1) {
				sf[i] = v[i];
			}
			else {
				sf[i] = min(sf[i + 1], v[i]);
			}
		}

		int mx = INT_MIN;
		for (int i = 0; i + 1 < n; ++i) {
			mx = max({ mx, pf[i], sf[i + 1]});
		}

		cout << mx << endl;
	}
	else {
		cout << *max_element(v.begin(), v.end()) << endl;
	}
}

int main() {
	Faster;

	solve();
}