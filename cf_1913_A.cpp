//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1913/problem/A
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

	string s;
	cin >> s;

	for (int i = 1; i < s.size(); ++i) {

		string a = s.substr(0, i);
		string b = s.substr(i);

		if (a.size() == 0 || b.size() == 0 || a[0] == '0' || b[0] == '0') {
			continue;
		}

		if (stoi(a) < stoi(b)) {
			cout << a << " " << b << endl;
			return ;
		}
	}

	cout << -1 << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}