//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1950/problem/E
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

const int N = 2e5 + 10;
const int MOD = 1e9 + 7;

vector<int> divisors[N];

void precompute() {

	for (int i = 1; i < N; ++i) {
		for (int j = i; j < N; j += i) {
			divisors[j].push_back(i);
		}
	}
}

void solve() {

	int n;
	cin >> n;

	string s;
	cin >> s;

	for (int x : divisors[n]) {

		int cnt = 2;
		for (int i = 0; i < x; ++i) {
			for (int j = i + x; j < n; j += x) {
				if (s[i] != s[j]) {
					cnt--;
				}
			}
		}

		if (cnt > 0) {
			cout << x << endl;
			break;
		}

		cnt = 2;
		for (int i = n - x; i < n; ++i) {
			for (int j = i - x; j >= 0; j -= x) {
				if (s[i] != s[j]) {
					cnt--;
				}
			}
		}

		if (cnt > 0) {
			cout << x << endl;
			break;
		}
	}
}

int main() {
	Faster;

	int t;
	cin >> t;

	precompute();

	while (t--) {
		solve();
	}
}