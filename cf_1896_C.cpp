//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1896/problem/C
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

	int n, x;
	cin >> n >> x;

	vector<pair<int, int>> a(n);
	vector<int> b(n);

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;

		a[i] = {x, i};
	}

	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	vector<int> ans(n);

	bool ok = true;
	for (int i = 0; i < x; ++i) {
		ans[a[n - x + i].second] = b[i];
		ok &= (a[n - x + i].first > b[i]);
	}


	for (int i = 0; x + i < n; ++i) {
		ans[a[i].second] = b[x + i];
		ok &= (a[i].first <= b[x + i]);
	}

	if (ok) {
		cout << "YES" << endl;
		vec_prnt(ans);
	}
	else {
		cout << "NO" << endl;
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