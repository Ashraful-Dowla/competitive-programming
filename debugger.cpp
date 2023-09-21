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
	randomTest.n = random_number(1, 10);
	for (int i = 0; i < randomTest.n; ++i) {
		int v = random_number(-100, 100);
		randomTest.nums.push_back(v);
	}

	return randomTest;
}

int brute_force(testcase T) {

	vector<int> nums = T.nums;

	sort(nums.begin(), nums.end());
	nums.erase( unique( nums.begin(), nums.end() ), nums.end());
	reverse(nums.begin(), nums.end());

	if (nums.size() > 2) return nums[2];
	else return nums[0];
}

int optimized_solution(testcase T) {

	vector<int> nums = T.nums;

	long long VAL = 10000000007;
	long long first = -VAL, second = -VAL, third = -VAL;

	for (int i = 0; i < nums.size(); ++i) {
		if (first < nums[i]) {
			first = nums[i];
		}
	}

	for (int i = 0; i < nums.size(); ++i) {
		if (first > nums[i] * 1LL) {
			if (nums[i] > second) {
				third = second;
				second = nums[i];
			}
			else if (nums[i] * 1LL > third && second != nums[i] * 1LL) {
				third = nums[i];
			}
		}
	}

	if (nums.size() > 2 && third != -VAL) return third;
	else return first;
}

void debugger() {
	testcase random = generate_testcase();
	int ans1 = brute_force(random);
	int ans2 = optimized_solution(random);

	if (ans1 != ans2) {
		for (int i = 0; i < random.nums.size(); ++i) {
			cout << random.nums[i] << " ";
		}
		cout << endl;
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