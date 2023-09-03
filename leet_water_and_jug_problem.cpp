/*
https://leetcode.com/problems/water-and-jug-problem/description/
*/
#include <bits/stdc++.h>
using namespace std;

unordered_map<int, bool> seen;

bool solve(int j1, int j2, int target, int total) {

	if (total == target) return true;
	if (total < 0 || total > j1 + j2 || seen[total]) return false;


	seen[total] = true;

	bool isPossible = false;
	isPossible |= solve(j1, j2, target, total + j1);
	isPossible |= solve(j1, j2, target, total - j1);
	isPossible |= solve(j1, j2, target, total + j2);
	isPossible |= solve(j1, j2, target, total - j2);

	return isPossible;
}

bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
	return solve(jug1Capacity, jug2Capacity, targetCapacity, 0);
}

int main() {

	// int jug1Capacity = 3, jug2Capacity = 5, targetCapacity = 4;
	// int jug1Capacity = 2, jug2Capacity = 6, targetCapacity = 5;
	int jug1Capacity = 1, jug2Capacity = 2, targetCapacity = 3;

	cout << canMeasureWater(jug1Capacity, jug2Capacity, targetCapacity);
}