#include <bits/stdc++.h>
using namespace std;

int main()
{
	//operator precedence
	cout<<7/2<<endl;
	cout<<7/2.0<<endl;
	cout<<'c'+1<<endl;

	int a=3/2;
	cout<<a<<endl;
	double b = 3/2;
	cout<<b<<endl;

	cout<<7/2 *3<<endl;
	cout<<3*7/2<<endl;


	//overflow
	int d=100000;
	int e=100000;
	int f = d*e;
	cout<<f<<endl;
	int mx = INT_MAX;
	cout<<INT_MAX + 1<<endl;
	long long g = d*1LL*e;
	cout<<g<<endl;

	double h = 100000;
	double i = 100000;
	double j = h*i;
	cout<<fixed<<setprecision(0)<<j<<endl;
	j=1e24;
	cout<<j<<endl;


}