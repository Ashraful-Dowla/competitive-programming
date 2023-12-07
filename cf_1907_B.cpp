//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1907/problem/B
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

bool cmp(pair<char, int> a, pair<char, int> b) {
	return a.second < b.second;
}

void solve() {

	string s;
	cin >> s;

	vector<pair<char, int>> low, up, res;

	for (int i = 0; i < s.size(); ++i) {

		if (s[i] == 'b') {
			if (low.size()) {
				low.pop_back();
			}
		}
		else if (s[i] == 'B') {
			if (up.size()) {
				up.pop_back();
			}
		}
		else if (s[i] >= 'a' && s[i] <= 'z') {
			low.push_back({s[i], i});
		}
		else {
			up.push_back({s[i], i});
		}
	}

	for (auto p : low) {
		res.push_back(p);
	}

	for (auto p : up) {
		res.push_back(p);
	}

	sort(res.begin(), res.end(), cmp);

	for (auto p : res) {
		cout << p.first;
	}
	cout << endl;

}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}