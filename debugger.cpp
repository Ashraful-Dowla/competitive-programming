#include <bits/stdc++.h>
using namespace std;

struct testcase {
	int n;
	vector<int> nums;
};

int random_number(int mn, int mx) {
	return mn + rand() % (mx - mn + 1);
}

testcase generate_testcase() {
	testcase randomTest;
	randomTest.n = random_number(1, 1005);
	for (int i = 0; i < randomTest.n; ++i) {
		int v = random_number(-100, 100);
		randomTest.nums.push_back(v);
	}

	return randomTest;
}

int brute_force(testcase T) {
	vector<int> nums = T.nums;
	int n = nums.size();

	int ans = INT_MIN, ii = 0;
	for (int i = 0; i < n; ++i) {

		int sum = 0;
		for (int j = 0; j < n - i; ++j) {
			sum += (ii + j) * nums[j];
		}
		ii++;

		for (int k = n - i, kk = 0; k < n; ++k, ++kk) {
			sum += kk * nums[k];
		}

		ans = max(ans, sum);
	}

	return ans;
}

int optimized_solution(testcase T) {

	vector<int> nums = T.nums;
	int n = nums.size();
	int rotate_sum = 0, sum = 0;
	for (int i = 0; i < n; ++i) {
		rotate_sum += i * nums[i];
		sum += nums[i];
	}

	int ans = rotate_sum;

	for (int i = n - 1; i >= 1; --i) {
		int d = sum - n * nums[i];
		rotate_sum += d;
		ans = max(ans, rotate_sum);
	}

	return ans;

}

void debugger() {
	testcase random = generate_testcase();
	int ans1 = brute_force(random);
	int ans2 = optimized_solution(random);

	if (ans1 != ans2) {
		cout << "Brute Force: " << endl;
		cout << random.n << " " << ans1 << endl;

		cout << "Optimized Solution: " << endl;
		cout << random.n << " " << ans2 << endl;

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