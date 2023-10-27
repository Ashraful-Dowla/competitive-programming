#include<bits/stdc++.h>
using namespace std;

void increment(int &n) {
	n++;
}

// void swap(int &a, int &b){
// 	int temp = a;
// 	a = b;
// 	b = temp;
// }

void func(string &s) {
	s = "";
}

void func2(int arr[]) {
	arr[0] = 5;
}
int main() {
	int a = 3;
	cout << a << endl;
	increment(a);
	cout << a << endl;
	int b = 5, c = -1;
	swap(b, c);
	cout << b << " " << c << endl;
	string s = "abc";
	cout << s << endl;
	func(s);
	cout << s << endl;

	int arr[10];
	arr[0] = 7;
	cout << arr[0] << endl;
	func2(arr);
	cout << arr[0] << endl;
}