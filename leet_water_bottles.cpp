/*
https://leetcode.com/problems/water-bottles/description/?envType=daily-question&envId=2024-07-07
*/
#include <bits/stdc++.h>
using namespace std;

int numWaterBottles(int numBottles, int numExchange) {

	int ans = numBottles, rem = 0;

	while (numBottles >= numExchange) {
		ans += numBottles / numExchange;
		numBottles = numBottles / numExchange + numBottles % numExchange;
	}

	return ans;
}

int main() {

	int numBottles = 9;
	int numExchange = 3;


	cout << numWaterBottles(numBottles, numExchange) << endl;
}