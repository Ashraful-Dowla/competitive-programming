//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1881/problem/D
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

const int N = 1e6 + 10;
const int MOD = 1e9 + 7;

unordered_map<int, int> mp;

void generate(int n) {

	for (int i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			mp[i]++;
			n /= i;
		}
	}

	if (n > 1) mp[n]++;
}



void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	mp.clear();

	for (int i = 0; i < n; ++i) {
		generate(a[i]);
	}

	for (auto p : mp) {
		if (p.second % n > 0) {
			cout << "NO" << endl;
			return ;
		}
	}

	cout << "YES" << endl;
	return;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}