/*
https://leetcode.com/problems/nim-game/description/
*/
#include <bits/stdc++.h>
using namespace std;

bool canWinNim(int n) {
	return n % 4;
}

int main() {

	int n = 3;
	cout << canWinNim(n);
}