//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1934/problem/B
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

	int ans = INT_MAX;
	for (int one = 0; one <= 10; ++one) {
		for (int three = 0; three <= 10; ++three) {
			for (int six = 0; six <= 10; ++six) {
				for (int ten = 0; ten <= 10; ++ten) {
					int sum = one + 3 * three + 6 * six + 10 * ten;
					if (n >= sum && (n - sum) % 15 == 0) {
						ans = min(ans, one + three + six + ten + (n - sum) / 15);
					}
				}
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