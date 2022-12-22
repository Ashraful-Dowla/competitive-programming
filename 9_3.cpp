/*
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/micro-and-array-update/
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int arr[n];
		int mn = INT_MAX;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			mn = min(mn, arr[i]);
		}
		if(mn>=k) cout<<0<<endl;
		else cout<<k-mn<<endl;
	}
}