//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1932/problem/D
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

string concat(char c1, char c2) {
	string s;
	s.push_back(c1);
	s.push_back(c2);
	return s;
}

void solve() {

	int n;
	char t;
	cin >> n;
	cin >> t;

	map<char, vector<char>> mp;
	for (int i = 0; i < 2 * n; ++i) {
		string s;
		cin >> s;
		mp[s[1]].push_back(s[0]);
	}

	string s = "CDHS";

	vector<char> cc;
	cc.push_back(t);
	for (char ch : s) {
		if (ch != t) {
			cc.push_back(ch);
		}
		sort(mp[ch].begin(), mp[ch].end());
	}

	vector<pair<string, string>> ans;

	int tp = 0;
	for (int i = 1; i < 4; ++i) {
		char ch = cc[i];
		for (int j = 0; j < mp[ch].size();) {
			if (j + 1 < mp[ch].size()) {
				string s1 = concat(mp[ch][j], ch);
				string s2 = concat(mp[ch][j + 1], ch);
				ans.push_back({s1, s2});
				j += 2;
			}
			else if (tp < mp[t].size()) {
				string s1 = concat(mp[ch][j], ch);
				string s2 = concat(mp[t][tp], t);
				ans.push_back({s1, s2});
				++j, ++tp;
			}
			else {
				cout << "IMPOSSIBLE" << endl;
				return ;
			}
		}
	}

	int r = mp[t].size() - tp;

	if (r % 2) {
		cout << "IMPOSSIBLE" << endl;
		return ;
	}
	else {
		for (int j = tp; j < mp[t].size(); j += 2) {
			string s1 = concat(mp[t][j], t);
			string s2 = concat(mp[t][j + 1], t);
			ans.push_back({s1, s2});
		}
	}

	for (auto p : ans) {
		cout << p.first << " " << p.second << endl;
	}

	mp.clear();
	cc.clear();
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}