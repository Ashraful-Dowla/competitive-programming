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
#define pii pair<int,int>
#define pll pair<ll,ll>


#define pb push_back
#define all(c) (c).begin(),(c).end()

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"
#define prnt1(x) cout<<x<<endl;
#define prnt2(x,y) cout<<x<<" "<<y<<endl;

const int N = 1e5 + 10;
const int MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;

	int arr[n + 2], pf[n + 2];
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	//O(N)
	for (int i = 1; i <= n; ++i) {
		pf[i] = pf[i - 1] + arr[i];
	}

	int q;
	cin >> q;


	// 1........r
	// 1...l-1

	// l...r

	//O(Q)
	for (int i = 0; i < q; ++i) { // -> q
		int l, r;
		cin >> l >> r;
		cout << pf[r] - pf[l - 1] << endl;
	}


	// time complexity -> O(N+Q)

}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}