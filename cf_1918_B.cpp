//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1918/problem/B
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

	vector<int> a(n), b(n);
	vector<pii> aa(n), bb(n);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		aa[i] = {a[i], i};
	}


	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		bb[i] = {b[i], i};
	}


	sort(aa.begin(), aa.end());
	sort(bb.begin(), bb.end());

	vector<int> bp(n);
	for (int i = 0; i < n; ++i) {
		bp[i] = b[aa[i].second];
	}

	vector<int> ap(n);
	for (int i = 0; i < n; ++i) {
		ap[i] = a[bb[i].second];
	}

	if (ap < bp) {
		for (int i = 0; i < n; ++i) {
			cout << ap[i] << " ";
		}
		cout << endl;
		for (int i = 1; i <= n; ++i) {
			cout << i << " ";
		}
		cout << endl;
	}
	else {

		for (int i = 1; i <= n; ++i) {
			cout << i << " ";
		}
		cout << endl;
		for (int i = 0; i < n; ++i) {
			cout << bp[i] << " ";
		}
		cout << endl;
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