/*
https://leetcode.com/problems/rectangle-area/description/
*/
#include <bits/stdc++.h>
using namespace std;

int calcArea(int x1, int y1, int x2, int y2) {
	return (x2 - x1) * (y2 - y1);
}

int computeArea(int ax1, int ay1, int ax2, int ay2,
                int bx1, int by1, int bx2, int by2) {

	int area_a = calcArea(ax1, ay1, ax2, ay2);
	int area_b = calcArea(bx1, by1, bx2, by2);

	int x1 = max(ax1, bx1), y1 = max(ay1, by1);
	int x2 = min(ax2, bx2), y2 = min(ay2, by2);

	int intersect_area = 0;
	if (x2 > x1 && y2 > y1) {
		intersect_area = calcArea(x1, y1, x2, y2);
	}

	return area_a + area_b - intersect_area;

}

int main() {

	int ax1 = -3, ay1 = 0;
	int ax2 = 3, ay2 = 4;
	int bx1 = 0, by1 = -1;
	int bx2 = 9, by2 = 2;

	// int ax1 = -2, ay1 = -2;
	// int ax2 = 2, ay2 = 2;
	// int bx1 = -2, by1 = -2;
	// int bx2 = 2, by2 = 2;


	// int ax1 = 1, ay1 = 1;
	// int ax2 = 4, ay2 = 4;
	// int bx1 = 2, by1 = 2;
	// int bx2 = 5, by2 = 5;

	// int ax1 = 1, ay1 = 1;
	// int ax2 = 3, ay2 = 3;
	// int bx1 = 4, by1 = 4;
	// int bx2 = 5, by2 = 5;


	cout << computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
}