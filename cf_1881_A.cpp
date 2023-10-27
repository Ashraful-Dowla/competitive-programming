//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1881/problem/A
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
	int n, m;
	cin >> n >> m;
 
	string x, s;
	cin >> x;
	cin >> s;
 
	int ans = -1;
 
	for (int i = 0; i <= 6; ++i) {
 
		if (x.find(s) != string::npos) {
			ans = i;
			break;
		}
 
		x = x + x;
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