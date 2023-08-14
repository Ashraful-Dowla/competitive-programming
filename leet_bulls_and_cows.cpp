/*
https://leetcode.com/problems/bulls-and-cows/description/
*/
#include <bits/stdc++.h>
using namespace std;

string getHint(string secret, string guess) {

	int bulls = 0, cows = 0;
	int n = secret.size();

	bool taken[n], g_taken[n];
	memset(taken, false, sizeof(taken));
	memset(g_taken, false, sizeof(g_taken));

	for (int i = 0; i < n; ++i) {
		if (secret[i] == guess[i]) {
			bulls++;
			taken[i] = true;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (taken[i]) continue;
		for (int j = 0; j < n; ++j) {
			if (taken[j] || g_taken[j]) continue;
			if (secret[i] == guess[j]) {
				cows++;
				g_taken[j] = true;
				break;
			}
		}
	}

	return to_string(bulls) + "A" + to_string(cows) + "B";

}

int main() {

	string secret = "1807";
	string guess = "7810";

	// string secret = "1123";
	// string guess = "0111";

	cout << getHint(secret, guess);
}