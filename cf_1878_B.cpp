//Author: Ashraful Dowla

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

	vector<ll> vec(n);

	vec[0] = 2, vec[1] = 3;

	for (int i = 2, x = 4; i < n; ++i, ++x) {
		int d = vec[i - 1] + vec[i - 2];
		int v = 3 * x;
		if (v % d == 0) {
			vec[i] = ++x;
		}
		else vec[i] = x;
	}

	vec_prnt(vec);
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}