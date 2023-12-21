//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1913/problem/C
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

unordered_map<ll, ll> cnt;

void solve() {

	int t;
	ll v;
	cin >> t >> v;

	if (t == 1) {
		cnt[v]++;
	}
	else {
		for (int i = 29; i >= 0; --i) {
			if (v > 0 && v >= (1LL << i)) {
				ll d = v / (1LL << i);
				v -= min(d, cnt[i]) * (1LL << i);
			}
		}
		cout << (v == 0 ? "YES" : "NO") << endl;
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