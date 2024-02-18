#include <bits/stdc++.h>
using namespace std;

struct triplet
{
	int gcd, x, y;
};

// ax + by = gcd(a,b)
// if b = 0 , x = 1, y = 0

triplet extended_gcd(int a, int b) {

	if (b == 0) {
		triplet t;
		t.x = 1;
		t.gcd = a;
		t.y = 0;

		return t;
	}

	triplet res = extended_gcd(b, a % b);
	triplet ans;

	ans.x = res.y;
	ans.gcd = res.gcd;
	ans.y = res.x - (a / b) * res.y;

	return ans;
}

//time complexity->O(logn)
int main() {

	int a, b;
	cin >> a >> b;

	triplet ans = extended_gcd(a, b);
	cout << ans.x << " " << ans.y << " " << ans.gcd << endl;

}