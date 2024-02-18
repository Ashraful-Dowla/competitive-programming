//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1931/problem/A
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

	for (int i = 1; i <= 26; ++i) {
		for (int j = 1; j <= 26; ++j) {
			for (int k = 1; k <= 26; ++k) {
				if (i + j + k == n) {
					cout << char(i - 1 + 'a') << char(j - 1 + 'a') << char(k - 1 + 'a') << endl;
					return ;
				}
			}
		}
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