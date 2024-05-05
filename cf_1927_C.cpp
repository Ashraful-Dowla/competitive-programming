//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1927/problem/C
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

	int n, m, k;
	cin >> n >> m >> k;

	set<int> a, b;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		a.insert(x);
	}

	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		b.insert(x);
	}

	map<int, int> mp1, mp2;
	for (int x : a) {
		mp1[x]++;
	}

	for (int x : b) {
		mp2[x]++;
	}

	int k1 = k / 2, k2 = k / 2, ck = 0;
	for (int i = 1; i <= k; ++i) {
		if (mp1[i] + mp2[i] == 1) {
			if (mp1[i] && k1 > 0) k1--;
			else if (mp2[i] && k2 > 0) k2--;
		}
		else if (mp1[i] + mp2[i] == 2) {
			ck++;
		}
		else {
			cout << "NO" << endl;
			return ;
		}
	}

	if (k1 + k2 == ck) {
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