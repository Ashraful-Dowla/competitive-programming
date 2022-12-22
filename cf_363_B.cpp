/*
https://codeforces.com/problemset/problem/363/B
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;

	int arr[n];
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}

	int sum=0,idx=0;
	sum = accumulate(arr,arr+k,sum);

	int minTotal = sum; 
	for(int i=k;i<n;++i){
		sum+=(arr[i]-arr[i-k]);
		if(sum<minTotal){
			idx=i-k+1;
			minTotal=sum;
		}
	}

	cout<<idx+1<<endl;
}