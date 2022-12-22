#include <bits/stdc++.h>
using namespace std;

tuple<int,int,int> gcd(int a,int b){
	if(b==0) return {1,0,a};

	int x,y,g;
	tie(x,y,g)=gcd(b,a%b);

	return {y,x-(a/b)*y,g};
}

//time complexity->O(logn)
int main(){
	int a,b;
	cin>>a>>b;

	int x,y,g;
	tie(x,y,g)=gcd(a,b);
	cout<<x<<" "<<y<<" "<<g<<endl;
}