//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1851/problem/C
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

	int n, k;
	cin >> n >> k;

	int c[n], cnt[n + 5] = {0};

	for (int i = 0; i < n; ++i) {
		cin >> c[i];
		cnt[c[i]]++;
	}

	if (c[0] == c[n - 1] && cnt[c[0]] >= k) {
		cout << "YES" << endl;
		return ;
	}

	int l = -1, x = 0;
	for (int i = 0; i < n; ++i) {
		if (c[0] == c[i]) {
			x++;
		}
		if (x % k == 0) {
			l = i;
			break;
		}
	}

	int r = -1, y = 0;
	for (int j = n - 1; j > l; --j) {
		if (c[n - 1] == c[j]) {
			y++;
		}
		if (y % k == 0) {
			r = j;
			break;
		}
	}

	if (l == -1 || r == -1  || l > r) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
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