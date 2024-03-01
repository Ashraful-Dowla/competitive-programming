//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1932/problem/C
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

const int N = 1e6 + 10;
const int MOD = 1e9 + 7;

ll tree[4 * N], a[N], m;

void build(int node, int st, int nd) {

	if (st == nd) {
		tree[node] = a[st] % m;
		return ;
	}

	int mid = (st + nd) / 2;
	build(2 * node, st, mid);
	build(2 * node + 1, mid + 1, nd);

	tree[node] = (tree[2 * node] * tree[2 * node + 1]) % m;
}

ll query(int node, int st, int nd, int l, int r) {

	if (st > r || nd < l) return 1;
	if (l <= st && nd <= r) return tree[node];

	int mid = (st + nd) / 2;
	ll q1 = query(2 * node, st, mid, l, r);
	ll q2 = query(2 * node + 1, mid + 1, nd, l, r);

	return (q1 * q2) % m;
}


void solve() {

	int n;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	string s;
	cin >> s;

	build(1, 0, n - 1);

	int l = 0, r = n - 1;
	for (int i = 0; i < n; ++i) {
		cout << query(1, 0, n - 1, l, r) << " ";

		if (s[i] == 'L') l++;
		else r--;
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