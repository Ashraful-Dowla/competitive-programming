//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1955/problem/B
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

const int N = 505;
const int MOD = 1e9 + 7;

int n;
ll c, d, matrix[N][N];
multiset<ll> ms, ms2;

bool check(ll a1) {

	matrix[0][0] = a1;

	ms2.clear();
	for (ll x : ms) {
		ms2.insert(x);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			matrix[i + 1][j] = matrix[i][j] + c;
			matrix[i][j + 1] = matrix[i][j] + d;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			auto it = ms2.find(matrix[i][j]);
			if (it != ms2.end()) {
				ms2.erase(it);
			}
		}
	}

	return ms2.size() == 0;
}

void solve() {

	cin >> n >> c >> d;

	ms.clear();
	for (int i = 0; i < n * n; ++i) {
		ll x;
		cin >> x;
		ms.insert(x);
	}

	if (check(*ms.begin())) {
		cout << "YES" << endl;
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