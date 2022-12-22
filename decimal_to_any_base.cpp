#include <bits/stdc++.h>
using namespace std;

//b -> positive or negative

void convert10tob(int n,int b){	
	if(n==0) return ;

	int x=n%b;
	n/=b;

	if(x<0) n+=1;

	convert10tob(n,b);
	cout<<(x<0 ? x+(b*-1) : x);
}

int main(){
	int n,b;
	cin>>n>>b;

	if(n==0) cout<<n<<endl;
	else convert10tob(n,b);
}