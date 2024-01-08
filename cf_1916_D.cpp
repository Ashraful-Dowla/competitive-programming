//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1916/problem/D
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

string make(string s, int n) {

	string t;
	for (char ch : s) {
		t.push_back(ch);
		for (int i = 0; i < n; ++i) {
			t.push_back('0');
		}
	}

	while (t.back() == '0') {
		t.pop_back();
	}
	return t;
}

void solve() {

	int n;
	cin >> n;

	vector<vector<string>> v(100);

	v[1] = {"1"};
	v[3] = {"169", "196", "961"};

	if (n == 1 || n == 3) {
		for (auto s : v[n]) {
			cout << s << endl;
		}
	}
	else {

		for (int i = 5; i <= n; i += 2) {

			string z;
			for (int j = 0; j < 2; ++j) {
				z.push_back('0');
			}

			for (int j = 0; j < v[i - 2].size(); ++j) {
				v[i].push_back(v[i - 2][j] + z);
			}

			v[i].push_back(make("169", (i - 3) / 2));
			v[i].push_back(make("961", (i - 3) / 2));
		}

		for (string s : v[n]) {
			cout << s << endl;
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