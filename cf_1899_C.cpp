//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1899/problem/C
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

ll max_sub(vector<ll>& v) {

	ll sum = v[0], best = v[0];
	for (int i = 1; i < v.size(); ++i) {
		sum = max(v[i], sum + v[i]);
		best = max(best, sum);
	}

	return best;
}

void solve() {

	int n;
	cin >> n;

	vector<ll> vec(n);

	ll ans = -1e9;
	for (int i = 0; i < n; ++i) {
		cin >> vec[i];
		ans = max(ans, vec[i]);
	}

	vector<vector<ll>> par;
	vector<ll> temp;

	for (int i = 0; i < n; ++i) {
		if (temp.empty() || abs(temp.back()) % 2 != abs(vec[i]) % 2) {
			temp.push_back(vec[i]);
		}
		else {
			par.push_back(temp);
			temp.clear();
			temp.push_back(vec[i]);
		}
	}

	if (temp.size()) {
		par.push_back(temp);
	}

	for (auto v : par) {
		ans = max(ans, max_sub(v));
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