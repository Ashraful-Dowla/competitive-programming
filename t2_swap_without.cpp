#include <bits/stdc++.h>
using namespace std;

//swap without third variable

int main(){
	int a,b;
	cin>>a>>b;

	a=b-a;
	b=b-a;
	a=a+b;

	cout<<a<<" "<<b<<endl;
}