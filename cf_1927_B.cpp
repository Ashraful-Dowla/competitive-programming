//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1927/problem/B
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

	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int cnt[26] = {0};
	string ans;
	for (int i = 0; i < n; ++i) {
		for (char ch = 'a'; ch <= 'z'; ++ch) {
			if (cnt[ch - 'a'] == a[i]) {
				ans.push_back(ch);
				cnt[ch - 'a']++;
				break;
			}
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