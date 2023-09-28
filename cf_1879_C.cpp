//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1879/problem/C
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
	string s;
	cin >> s;

	ll mod = 998244353;

	int x = 0, op = 0;
	ll fact = 1;
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] == s[i - 1]) {
			x++;
		}
		else {
			op += x;
			x++;
			fact = ((fact % mod) * (x % mod)) % mod;
			x = 0;
		}
	}

	if (x > 0) {
		op += x;
		x++;
		fact = ((fact % mod) * (x % mod)) % mod;
	}

	for (int i = 1; i <= op; ++i) {
		fact = ((fact % mod) * (i % mod)) % mod;
	}

	cout << op << " " << fact << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}
