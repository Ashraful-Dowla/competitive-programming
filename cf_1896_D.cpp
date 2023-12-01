//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1896/problem/D
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

int arr[N], tree[4 * N];

void build(int node, int st, int nd) {

	if (st == nd) {
		tree[node] = arr[st];
		return ;
	}

	int mid = (st + nd) / 2;

	build(2 * node, st, mid);
	build(2 * node + 1, mid + 1, nd);

	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int st, int nd, int l, int r) {

	if (nd < l || r < st) return 0;
	if (l <= st && nd <= r) return tree[node];

	int mid = (st + nd) / 2;

	int q1 = query(2 * node, st, mid, l, r);
	int q2 = query(2 * node + 1, mid + 1, nd, l, r);

	return q1 + q2;
}

void update(int node, int st, int nd, int idx, int val) {

	if (st == nd) {
		tree[node] = arr[idx] = val;
		return ;
	}

	int mid = (st + nd) / 2;

	if (idx <= mid) update(2 * node, st, mid, idx, val);
	else update(2 * node + 1, mid + 1, nd, idx, val);

	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void solve() {

	int n, q;
	cin >> n >> q;

	set<int> s;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];

		if (arr[i] == 1) {
			s.insert(i);
		}
	}

	build(1, 1, n);

	while (q--) {
		int t;
		cin >> t;

		if (t == 1) {
			int x;
			cin >> x;
			int sum = tree[1];

			if (x > sum) {
				cout << "NO" << endl;
			}
			else {
				int diff = sum - x;

				if (diff % 2 == 0) {
					cout << "YES" << endl;
				}
				else {

					int mx = 0;
					if (s.size()) {
						int l = *s.begin(), r = *(--s.end());
						mx = max(mx, query(1, 1, n, l, n));
						mx = max(mx, query(1, 1, n, 1, r));
					}

					if (x <= mx) {
						cout << "YES" << endl;
					}
					else {
						cout << "NO" << endl;
					}
				}
			}

		}
		else {
			int idx, v;
			cin >> idx >> v;

			if (arr[idx] == 1) {
				s.erase(idx);
			}

			if (v == 1) {
				s.insert(idx);
			}

			update(1, 1, n, idx, v);
		}
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