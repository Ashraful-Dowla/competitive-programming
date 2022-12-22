#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	return b==0 ? a: gcd(b,a%b);
}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b)<<endl;
	cout<<__gcd(a,b)<<endl;
	cout<<a*b/gcd(a,b)<<endl;
}