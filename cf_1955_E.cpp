//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1955/problem/E
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
	string s;
	cin >> s;

	s = "_" + s;

	int ans = 1;
	for (int k = 1; k <= n; ++k) {

		int pf[n + 5] = {0};

		for (int i = 1; i <= n; ++i) {

			pf[i] += pf[i - 1];

			if (s[i] == '1' && pf[i] % 2 == 0) {
				continue;
			}
			else if (s[i] == '0' && pf[i] % 2 == 1) {
				continue;
			}
			else if (i + k <= n + 1) {
				pf[i]++;
				pf[i + k]--;
			}
			else {
				break;
			}
		}

		bool ok = true;
		for (int i = 1; i <= n; ++i) {
			if (s[i] == '1' && pf[i] % 2 == 0) {
				continue;
			}
			else if (s[i] == '0' && pf[i] % 2 == 1) {
				continue;
			}
			else {
				ok = false;
				break;
			}
		}

		if (ok) {
			ans = max(ans, k);
		}
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