//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1877/problem/C
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

	if (k == 1) cout << 1 << endl;
	else if (k == 2) {
		if (m <= n) cout << m << endl;
		else cout << n + (m - n) / n << endl;
	}
	else if (k == 3) {
		if (m <= n) cout << 0 << endl;
		else cout << m - (n + (m - n) / n) << endl;
	}
	else {
		cout << 0 << endl;
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