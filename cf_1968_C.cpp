//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1968/problem/C
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

	vector<int> x(n + 1);

	for (int i = 2; i <= n; ++i) {
		cin >> x[i];
	}

	vector<int> a(n + 1);

	a[1] = x[2] + 1;
	a[n] = x[n];

	for (int i = 2; i + 1 <= n; ++i) {
		if (x[i] > x[i + 1]) {
			a[i] = x[i];
		}
		else {
			int d = (x[i + 1] + a[i - 1] - 1) / a[i - 1];
			a[i] = d * a[i - 1] + x[i];
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << a[i] << " ";
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