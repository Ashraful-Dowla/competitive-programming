//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1895/problem/D
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

	vector<int> a(n), b(n), c(n, 0);

	for (int i = 1; i < n; ++i) {
		cin >> a[i];
		c[i] = c[i - 1] ^ a[i];
	}

	for (int i = 0; i < 20; ++i) {

		int one = 0, zero = 0;
		for (int j = 0; j < n; ++j) {
			if (c[j] & (1 << i)) one++;
			else zero++;
		}

		if (zero < one) {
			for (int j = 0; j < n; ++j) {
				c[j] ^= (1 << i);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << c[i] << " ";
	}
	cout << endl;
}

int main() {
	Faster;

	solve();
}