//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1915/problem/B
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

	char ch[3][3];
	int row[3] = {0};

	vector<set<char>>v(3);

	for (int i = 0; i < 3; ++i) {
		v[i].insert('A');
		v[i].insert('B');
		v[i].insert('C');
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> ch[i][j];
			if (ch[i][j] != '?') {
				v[i].erase(ch[i][j]);
			}
		}
	}


	if (v[0].size()) {
		cout << (*v[0].begin()) << endl;
	}
	else if (v[1].size()) {
		cout << (*v[1].begin()) << endl;
	}
	else {
		cout << (*v[2].begin()) << endl;
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