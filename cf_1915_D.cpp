//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1915/problem/D
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

bool isVowel(char ch) {
	return ch == 'a' || ch == 'e';
}

void solve() {

	int n;
	cin >> n;

	string s;
	cin >> s;

	string p;

	for (char ch : s) {
		if (isVowel(ch)) {
			p.push_back('v');
		}
		else {
			p.push_back('c');
		}
	}

	if (n <= 3) {
		cout << s << endl;
	}
	else {
		vector<string> ans;
		for (int i = 0; i + 1 < n; ++i) {
			if (p[i] == 'c' && p[i + 1] == 'v') {
				string q;
				q.push_back(s[i]);
				q.push_back(s[i + 1]);

				if (i + 2 < n && p[i + 2] == 'c') {
					q.push_back(s[i + 2]);
					if (i + 3 < n && p[i + 3] == 'c') {
						i += 2;
					}
					else if (i + 3 < n) {
						q.pop_back();
						i += 1;
					}
				}
				else {
					i += 1;
				}
				ans.push_back(q);
			}
		}

		cout << ans[0];
		for (int i = 1; i < ans.size(); ++i) {
			cout << "." << ans[i];
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