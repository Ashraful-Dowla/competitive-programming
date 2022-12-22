#include <bits/stdc++.h>
using namespace std;

//forward and reversed order
int main(){
	int n=3;

	int arr[n];
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}

	for(int i=0;i<n;++i){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	for(int i=n-1;i>=0;--i){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}