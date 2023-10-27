//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1883/problem/B
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

	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	int cnt[30] = {0};

	for (char ch : s) {
		cnt[ch - 'a']++;
	}

	int odd = 0;
	for (char ch = 'a'; ch <= 'z'; ch++) {
		int val = cnt[ch - 'a'];
		if (val % 2 == 1) {
			odd++;
		}
	}

	if (odd - 1 > k) cout << "NO" << endl;
	else cout << "YES" << endl;

}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}