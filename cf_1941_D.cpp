//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1941/problem/D
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

	int n, m, x;
	cin >> n >> m >> x;

	x--;

	set<int> q;

	q.insert(x);
	for (int i = 0; i < m; ++i) {
		int r;
		char c;
		cin >> r >> c;

		set<int> t;
		if (c == '0') {
			while (!q.empty()) {
				int v = *q.begin();
				q.erase(v);

				int node = (v + r) % n;
				t.insert(node);
			}
		}
		else if (c == '1') {
			while (!q.empty()) {
				int v = *q.begin();
				q.erase(v);

				int node = (v - r + n) % n;
				t.insert(node);
			}
		}
		else {
			while (!q.empty()) {
				int v = *q.begin();
				q.erase(v);

				int node1 = (v + r) % n;
				int node2 = (v - r + n) % n;
				t.insert(node1);
				t.insert(node2);
			}
		}

		q = t;
	}


	set<int> ans;
	while (!q.empty()) {
		ans.insert(*q.begin());
		q.erase(q.begin());
	}

	cout << ans.size() << endl;
	for (int v : ans) {
		cout << v + 1 << " ";
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