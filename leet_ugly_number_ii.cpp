/*
https://leetcode.com/problems/ugly-number-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int nthUglyNumber(int n) {

	vector<ll>ugly(n);

	ugly[0] = 1;
	int i2 = 0, i3 = 0, i5 = 0;

	for (int i = 1; i < n; ++i) {
		ll nm2 = ugly[i2] * 2;
		ll nm3 = ugly[i3] * 3;
		ll nm5 = ugly[i5] * 5;

		ll mn = min({nm2, nm3, nm5});
		ugly[i] = mn;

		if (nm2 == mn) i2++;
		if (nm3 == mn) i3++;
		if (nm5 == mn) i5++;
	}

	return ugly[n - 1];
}

int main() {

	int n = 1690;
	cout << nthUglyNumber(n);
}