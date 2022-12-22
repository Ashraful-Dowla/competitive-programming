/*
https://codeforces.com/problemset/problem/702/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];

	for(int i=0;i<n;++i){
		cin>>arr[i];
	}

	int len=1,mx=1;

	for(int i=1;i<n;++i){
		if(arr[i-1]<arr[i]) mx = max(mx,++len);
		else len=1;
	}

	cout<<mx<<endl;
}