//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1913/problem/B
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

	string s, t;

	cin >> s;

	vector<int> cnt(2, 0);
	for (char ch : s) {
		if (ch == '1') {
			t.push_back('0');
			cnt[1]++;
		}
		else {
			t.push_back('1');
			cnt[0]++;
		}
	}

	int ans = 0;
	for (int i = 0, j = 0; i < s.size() && j < s.size(); ++j) {

		if (s[i] != t[j] && cnt[t[j] - '0'] > 0) {
			cnt[t[j] - '0']--;
			i++;
		}
		else {
			ans++;
		}
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