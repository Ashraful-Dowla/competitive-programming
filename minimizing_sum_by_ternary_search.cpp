#include <bits/stdc++.h>
using namespace std;


//min sum =  |a1 - x| + |a2 - x| + ... + |an - x|
int convex_func(vector<int>& v, int x) {

	int sum = 0;
	for (int a : v) {
		sum += abs(a - x);
	}

	return sum;
}

//min sum =  (a1 - x)^2 + (a2 - x)^2 + ... + (an - x)^2
int convex_func_2(vector<int>&v, int x) {

	int sum = 0;
	for (int a : v) {
		sum += (a - x) * (a - x);
	}

	return sum;
}

int main() {


	vector<int> v = {1, 2, 9, 2, 6};

	int lo = 1, hi = 10;

	while (hi - lo > 1) {

		int mid1 = lo + (hi - lo) / 3;
		int mid2 = hi - (hi - lo) / 3;

		int res1 = convex_func(v, mid1);
		int res2 = convex_func(v, mid2);

		if (res1 < res2) {
			hi = mid1;
		}
		else {
			lo = mid2;
		}
	}

	if (convex_func(v, lo) < convex_func(v, hi)) {
		cout << lo << endl;
	}
	else {
		cout << hi << endl;
	}
}