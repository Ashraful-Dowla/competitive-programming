//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1950/problem/D
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

string s;
vi v;
map<int, bool> taken;

void precompute(int i) {

	if (i >= 6) {
		if (s.size() > 0 && !taken[stoi(s)]) {
			v.push_back(stoi(s));
			taken[stoi(s)] = true;
		}
		return ;
	}

	s.push_back('1');
	precompute(i + 1);
	s.pop_back();

	s.push_back('0');
	precompute(i + 1);
	s.pop_back();

	precompute(i + 1);

}

void solve() {

	int n;
	cin >> n;

	for (int i = 0; i < v.size() - 2; ++i) {
		while (n % v[i] == 0) {
			n /= v[i];
		}
	}

	cout << (n == 1 ? "YES" : "NO") << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	precompute(0);
	sort(v.rbegin(), v.rend());

	while (t--) {
		solve();
	}
}