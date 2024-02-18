#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> vvll;

struct testcase {
	ll a, x, m;
};

int random_number(int mn, int mx) {
	return mn + rand() % (mx - mn + 1);
}

testcase generate_testcase() {
	testcase randomTest;
	randomTest.a = random_number(1, 1e9);
	randomTest.x = random_number(1, 1e9);
	randomTest.m = random_number(1, 1e9);
	return randomTest;
}

vvll multiply(vvll & a, vvll & b, ll m) {

	vvll res(2, vector<ll>(2, 0LL));

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) {
				res[i][j] += a[i][k] * b[k][j];
				res[i][j] %= m;
			}
		}
	}

	return res;
}

vvll matrix_exp(vvll & a, ll x, ll m) {

	if (x == 0) {
		return {
			{1LL, 0LL},
			{0LL, 1LL}
		};
	}
	if (x == 1) return a;

	vvll temp = matrix_exp(a, x / 2, m);
	vvll res =	multiply(temp, temp, m);

	if (x & 1LL) {
		res = multiply(res, a, m);
	}

	return res;
}

ll brute_force(testcase T) {

	ll a = T.a;
	ll x = T.x;
	ll m = T.m;

	vvll matrix = {
		{a, 1LL},
		{0LL, 1LL}
	};

	vvll ans = matrix_exp(matrix, x, m);
	return ans[0][1];
}

vector<vector<ll>> mat_mul(vector<vector<ll>> a, vector<vector<ll>> b, ll mod) {
	// 行列乗算
	int n = a.size();
	vector<vector<ll>> res(n, vector<ll>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				res[i][j] += a[i][k] * b[k][j];
				res[i][j] %= mod;
			}
		}
	}
	return res;
}
vector<vector<ll>> mat_pow(vector<vector<ll>> a, ll b, ll mod) {
	// Matrix exponentiation
	int n = a.size();
	vector<vector<ll>> res(n, vector<ll>(n));
	for (int i = 0; i < n; i++) res[i][i] = 1;
	while (b) {
		if (b & 1) res = mat_mul(res, a, mod);
		a = mat_mul(a, a, mod);
		b >>= 1;
	}
	return res;
}

ll optimized_solution(testcase T) {

	ll a = T.a;
	ll x = T.x;
	ll m = T.m;

	vvll matrix = {
		{a, 1LL},
		{0LL, 1LL}
	};

	vvll ans = matrix_exp(matrix, x, m);
	return ans[0][1];

}

void debugger() {

	testcase random = generate_testcase();
	auto ans1 = brute_force(random);
	auto ans2 = optimized_solution(random);

	if (ans1 != ans2) {

		cout << random.a << " " << random.x << " " << random.m << endl;
		cout << "Brute Force: " << endl;
		cout << ans1 << endl;

		cout << "Optimized Solution: " << endl;
		cout << ans2 << endl;

		cout << "------------------------------" << endl;
	}
}

int main() {

	int t = 25;
	srand(time(NULL));
	while (t--) {
		debugger();
	}

	return 0;
}