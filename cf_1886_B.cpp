//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1886/problem/B
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

double dis_calc(double x1, double y1, double x2, double y2) {
	double d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	return sqrt(d);
}

bool exists_inside_circle(double x1, double y1, double x2, double y2, double r) {
	return dis_calc(x1, y1, x2, y2) <= r;
}

bool overlap_cicle(double x1, double y1, double x2, double y2, double r) {
	return dis_calc(x1, y1, x2, y2) <= 2.0 * r;
}

void solve() {
	double px, py, ax, ay, bx, by;
	cin >> px >> py;
	cin >> ax >> ay;
	cin >> bx >> by;


	double lo = 0, hi = 10000, eps = 1e-6;

	while (hi - lo > eps) {
		double mid = (hi + lo) / 2.0;

		if (exists_inside_circle(ax, ay, 0, 0, mid)) {
			if (exists_inside_circle(ax, ay, px, py, mid)) {
				hi = mid;
			}
			else if (exists_inside_circle(bx, by, px, py, mid)
			         && overlap_cicle(ax, ay, bx, by, mid)) {
				hi = mid;
			}
			else {
				lo = mid;
			}
		}
		else if (exists_inside_circle(bx, by, 0, 0, mid)) {
			if (exists_inside_circle(bx, by, px, py, mid)) {
				hi = mid;
			}
			else if (exists_inside_circle(ax, ay, px, py, mid)
			         && overlap_cicle(ax, ay, bx, by, mid)) {
				hi = mid;
			}
			else {
				lo = mid;
			}
		}
		else {
			lo = mid;
		}
	}

	cout << setprecision(10) << lo << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}