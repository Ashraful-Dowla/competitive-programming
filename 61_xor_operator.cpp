#include <bits/stdc++.h>
using namespace std;

int main(){
	int a = 4, b = 6;

	// a^a = 0
	// a^0 = a
	a = a^b;
	b = b^a; // b^(a^b) => a
	a = a^b; // (a^b)^a => b

	cout<<a<<" "<<b<<endl;
}