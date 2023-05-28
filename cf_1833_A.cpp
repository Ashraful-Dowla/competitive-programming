//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1833/problem/A
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

	string s;
	cin >> s;

	map<string, bool>mp;

	for (int i = 0; i < s.size() - 1; ++i) {
		string t = s.substr(i, 2);
		mp[t] = true;
	}

	prnt1(mp.size());
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}