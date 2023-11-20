#include <bits/stdc++.h>
using namespace std;

struct testcase {
	int n;
	string s;
};

int random_number(int mn, int mx) {
	return mn + rand() % (mx - mn + 1);
}

testcase generate_testcase() {
	testcase randomTest;
	randomTest.n = random_number(1, 100);
	return randomTest;
}

string brute_force(testcase T) {

	int n = T.n;

	if ((n - 1) % 3 == 0 || (n + 1) % 3 == 0) {
		return "First";
	}
	else return "Second";
}

string optimized_solution(testcase T) {

	int n = T.n;
	if (n % 3 == 0)
	{
		return "Second";
	}
	else
	{
		return "First";
	}
}

void debugger() {

	testcase random = generate_testcase();
	auto ans1 = brute_force(random);
	auto ans2 = optimized_solution(random);

	if (ans1 != ans2) {

		cout << random.n << endl;
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