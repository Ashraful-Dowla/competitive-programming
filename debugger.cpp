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

	char ch[2] = {'A', 'B'};
	for (int i = 0; i < randomTest.n; ++i) {
		int j = random_number(0, 1);
		randomTest.s.push_back(ch[j]);
	}

	return randomTest;
}

int brute_force(testcase T) {

	string s = T.s;
	int n = s.length(), cnt = 0;
	bool all = (s[0] == 'B' || s[n - 1] == 'B');
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1] && s[i] == 'B') {all = true;}
	}
	vector<int> lens;
	int curr = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A') {curr++;}
		else {
			if (curr != 0) {lens.push_back(curr);}
			curr = 0;
		}
	}
	if (curr != 0) {lens.push_back(curr);}
	sort(lens.begin(), lens.end());

	if (lens.empty()) {
		return 0;
	}

	int tot = 0;
	if (all) {tot += lens[0];}
	for (int i = 1; i < lens.size(); i++) {
		tot += lens[i];
	}

	return tot;
}

int optimized_solution(testcase T) {

	string s = T.s;

	int n = s.size();
	int ans = 0;

	vector<int> b;
	b.push_back(-1);

	for (int i = 0; i < n; ++i) {
		if (s[i] == 'B') {
			b.push_back(i);
		}
	}

	b.push_back(n);

	int sz = b.size();
	for (int i = 1; i + 1 < sz; ++i) {
		int len1 = b[i + 1] - b[i] - 1;
		int len2 = b[i] - b[i - 1] - 1;

		ans += max(len1, len2);

		if (len1 > len2) {
			b[i] = b[i + 1] - 1;
		}
	}

	return ans;
}

void debugger() {

	testcase random = generate_testcase();
	int ans1 = brute_force(random);
	int ans2 = optimized_solution(random);

	if (ans1 != ans2) {

		cout << random.s << endl;
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