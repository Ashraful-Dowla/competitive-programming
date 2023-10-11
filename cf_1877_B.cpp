//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1877/problem/B
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


bool cmp(pii x, pii y) {
	return x.second < y.second;
}

void solve() {
	int n, p;
	cin >> n >> p;

	vector<int> a(n), b(n);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];

	}

	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	vector<pii> vec;

	for (int i = 0; i < n; ++i) {
		vec.push_back({a[i], b[i]});
	}

	sort(vec.begin(), vec.end(), cmp);
	ll cost = p;
	int m = n - 1;

	for (int i = 0; i < n; ++i) {
		int num = min(m, vec[i].first);
		m = max(0, m - num);
		cost += num * 1LL * min(p, vec[i].second);
	}

	cout << min(p * 1LL * n, cost) << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}