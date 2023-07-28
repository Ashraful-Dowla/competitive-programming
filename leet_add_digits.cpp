/*
https://leetcode.com/problems/add-digits/description/
*/
#include <bits/stdc++.h>
using namespace std;

int addDigits(int num) {
	if (num == 0) return 0;
	return num % 9 == 0 ? 9 : num % 9;
}

int main() {

	int num = 123;
	cout << addDigits(num);
}