//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1907/problem/A
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

	char ch, d;

	cin >> ch >> d;

	set<string> st;
	for (char c = 'a'; c <= 'h'; ++c) {
		string s;
		s.push_back(c);
		s.push_back(d);

		st.insert(s);
	}

	for (char c = '1'; c <= '8'; c++) {
		string s;
		s.push_back(ch);
		s.push_back(c);

		st.insert(s);
	}

	string ss;

	ss.push_back(ch);
	ss.push_back(d);

	st.erase(ss);

	for (string s : st) {
		cout << s << endl;
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