/*
https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/description/?envType=daily-question&envId=2024-06-13
*/
#include <bits/stdc++.h>
using namespace std;

int minMovesToSeat(vector<int>& seats, vector<int>& students) {

	sort(seats.begin(), seats.end());
	sort(students.begin(), students.end());

	int ans = 0;
	for (int i = 0; i < seats.size(); ++i) {
		ans += abs(seats[i] - students[i]);
	}

	return ans;
}

int main() {

	vector<int> seats = {3, 1, 5};
	vector<int> students = {2, 7, 4};

	cout << minMovesToSeat(seats, students);
}