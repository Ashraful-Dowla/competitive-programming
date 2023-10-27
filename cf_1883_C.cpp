//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1883/problem/C
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

	vector<int> vec(n);
	for (int i = 0; i < n; ++i) {
		cin >> vec[i];
	}

	for (int i = 0; i < n; ++i) {
		if (vec[i] % k == 0) {
			cout << 0 << endl;
			return ;
		}
	}

	int ans = INT_MAX;
	for (int i = 0; i < n; ++i) {
		int d = vec[i] / k;
		int rem = (d + 1) * k - vec[i];
		ans = min(ans, rem);
	}

	if (k == 4) {
		int one = 0, even = 0;
		for (int i = 0; i < n; ++i) {
			if (vec[i] == 1) {
				one++;
			}
			else if (vec[i] % 2 == 0) {
				even++;
			}
		}

		if (one >= 2) {
			ans = min(ans, 2);
		}
		ans = min(ans, max(0, 2 - even));
	}

	cout << ans << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}