//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1950/problem/C
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

	int hour = stoi(s.substr(0, 2));
	int mintues = stoi(s.substr(3));

	if (hour < 12) {
		if (hour == 0) {
			cout << 12 << ":" << s.substr(3) << " AM" << endl;
		}
		else {
			cout << s << " AM" << endl;
		}
	}
	else if (hour == 12) {
		cout << s << " PM" << endl;
	}
	else {
		hour %= 12;
		if (hour < 10) {
			cout << 0 << hour % 12 << ":";
		}
		else {
			cout << hour % 12 << ":";
		}
		cout << s.substr(3) << " PM" << endl;
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