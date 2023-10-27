//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1881/problem/C
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

	char ch[n][n];
	bool visited[n][n];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> ch[i][j];
			visited[i][j] = false;
		}
	}

	int r = 0, c = n - 1, ans = 0;

	while (r < c) {
		for (int i = r; i <= c; ++i) {
			if (!visited[r][i]) {

				visited[r][i] = visited[i][c] = true;
				visited[c][n - i - 1] = visited[n - i - 1][r] = true;

				vector<char> v;
				v.push_back(ch[r][i]);
				v.push_back(ch[i][c]);
				v.push_back(ch[c][n - i - 1]);
				v.push_back(ch[n - i - 1][r]);

				sort(v.rbegin(), v.rend());

				for (int i = 0; i < 4; ++i) {
					ans += (v[0] - v[i]);
				}
			}

		}
		r++, c--;
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