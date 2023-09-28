//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1878/problem/E
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

int arr[N], tree[4 * N];

void build(int node, int st, int nd) {

	if (st == nd) {
		tree[node] = arr[st];
		return ;
	}

	int mid = (st + nd) / 2;

	build(2 * node, st, mid);
	build(2 * node + 1, mid + 1, nd);

	tree[node] = tree[2 * node] & tree[2 * node + 1];
}

int query(int node, int l, int r, int st, int nd) {

	if (st > r || nd < l) return INT_MAX;
	if (l <= st && nd <= r) return tree[node];

	int mid = (st + nd) / 2;

	int q1 = query(2 * node, l, r, st, mid);
	int q2 = query(2 * node + 1, l, r, mid + 1, nd);

	return q1 & q2;
}

void solve() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	build(1, 0, n - 1);

	int q;
	cin >> q;

	while (q--) {
		int l, k;
		cin >> l >> k;

		int lo = l, hi = n, r = -1;

		while (lo <= hi) {
			int mid = (lo + hi) / 2;

			if (query(1, l - 1, mid - 1, 0, n - 1) >= k) {
				lo = mid + 1;
				r = max(r, mid);
			}
			else {
				hi = mid - 1;
			}
		}
		cout << r << " ";
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