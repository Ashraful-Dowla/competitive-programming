//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1867/problem/B
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

	int lo = 0, hi = n - 1;
	int diff = 0, mx_pr = 0;

	while (lo < hi) {
		if (s[lo] == s[hi]) mx_pr += 2;
		else diff++;
		lo++, hi--;
	}

	vector<int> ans(n + 1, 0);
	for (int i = 0; i <= n; ++i) {
		int ones = i;
		if (ones < diff) continue;

		ones -= diff;
		int pr = mx_pr;
		while (pr > 0 && ones > 1) {
			ones -= 2;
			pr -= 2;
		}

		if (ones == 0) ans[i] = 1;
		else if (ones == 1 && n % 2 == 1) {
			ans[i] = 1;
		}
		else ans[i] = 0;
	}

	for (int i = 0; i <= n; ++i) {
		cout << ans[i];
	}
	cout << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}