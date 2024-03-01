//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1926/problem/C
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

ll dp[N];

ll resolve(int n) {

	ll sum = 0;
	while (n) {
		sum += (n % 10);
		n /= 10;
	}

	return sum;
}

void precompute() {
	for (int i = 1; i < N; ++i) {
		dp[i] = dp[i - 1] + resolve(i);
	}
}

void solve() {

	int n;
	cin >> n;
	cout << dp[n] << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	precompute();

	while (t--) {
		solve();
	}
}