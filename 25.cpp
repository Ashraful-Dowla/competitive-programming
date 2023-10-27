#include <bits/stdc++.h>
using namespace std;

void func(int n){
	if(n==0) return;
	func(n-1);
	cout<<n<<endl;
}

int fac(int n){
	if(n==0) return 1;
	return n*fac(n-1); 
}

int main(){
	// func(5);
	int n;
	cin>>n;	
	cout<<fac(n)<<endl;
}

//1.Number of function calls
//2. complexity of each function
// total complexity = 1*2