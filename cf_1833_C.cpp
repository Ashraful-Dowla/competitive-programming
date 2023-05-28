//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1833/problem/C
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

	vi a(n);
	int even = 0, odd = 0, m_e = INT_MAX, m_o = INT_MAX;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] % 2 == 0) {
			even++;
			m_e = min(m_e, a[i]);
		}
		else {
			odd++;
			m_o = min(m_o, a[i]);
		}
	}

	if (odd == 0 || even == 0) {
		prnt1("Yes");
		return ;
	}

	// prnt2(m_o, m_e);

	if (m_o < m_e) prnt1("Yes");
	else prnt1("No");
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}