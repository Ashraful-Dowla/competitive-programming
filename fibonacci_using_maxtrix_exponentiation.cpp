#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

// matrix multiplication
// time complexity(n^3)
// here, n = 2 always

vvll multiply(vvll &a, vvll &b) {

	int n = a.size();

	vvll ans(n, vll(n, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				ans[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	return ans;
}

// matrix exponentiation
// time complexity -> O(2^3log(n)) =  O(log(n))
vvll matrix_exp(vvll &a, int n) {

	// return identity matrix
	if (n == 0) {

		int sz = a.size();
		vvll ans(sz, vll(sz, 0));

		for (int i = 0; i < sz; ++i) {
			ans[i][i] = 1;
		}

		return ans;
	}

	if (n == 1) return a;

	vvll temp = matrix_exp(a, n / 2);

	vvll ans = multiply(temp, temp);

	if (n & 1) {
		ans = multiply(ans, a);
	}

	return ans;
}

int main() {

	int n;
	cin >> n;

	vvll a = {
		{1, 1},
		{1, 0}
	};

	vvll ans = matrix_exp(a, n);

	int sz = ans.size();
	for (int i = 0; i < sz; ++i) {
		for (int j = 0; j < sz; ++j) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	cout << ans[0][sz - 1] << endl;
}