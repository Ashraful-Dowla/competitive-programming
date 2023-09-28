//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1873/problem/C
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

ll calc(int x, int y) {

	for (int i = 0; i < 5; ++i) {

		bool isValid = (x == i || x == 9 - i) && (y >= i && y <= 9 - i);
		if (isValid) return i + 1;

		isValid = (y == i || y == 9 - i) && (x >= i && x <= 9 - i);
		if (isValid) return i + 1;
	}
}

void solve() {

	char matrix[10][10];
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			cin >> matrix[i][j];
		}
	}

	ll ans = 0;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (matrix[i][j] == 'X') {
				ans += calc(i, j);
			}
		}
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