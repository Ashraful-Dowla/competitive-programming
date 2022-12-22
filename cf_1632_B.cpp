#include <bits/stdc++.h>
using namespace std;


void printBinary(int num){
	cout<<num<<"->";
	for(int i=5;i>=0;--i){
		cout<<((num>>i)&1);
	}
	cout<<endl;
}

int main(){

	// int arr[5] = {3,2,1,0,4};
	int arr[10] = {4,6,3,2,0,8,9,1,7,5};

	int sz=sizeof(arr)/sizeof(arr[0]);

	for(int i=0;i<sz;++i){
		printBinary(arr[i]);
	}

	int mx = 0;
	for(int i=1;i<sz;++i){
		mx = max(mx,arr[i]^arr[i-1]);
	}
	cout<<mx<<endl;

	int t;
	cin>>t;
	while(t--) {
	   int n;
	   cin>>n;
	}
}