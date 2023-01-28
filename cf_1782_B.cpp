/*
https://codeforces.com/contest/1782/problem/B
*/
#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	int arr[n];

	int zero=0;
	for(int i=0;i<n;++i){
		cin>>arr[i];
		if(arr[i]==0) zero++;
 	}

	sort(arr,arr+n);

	int cnt = zero>0 ? 1:2;

	for(int i=1;i<n;++i){
		if(i>arr[i-1] && arr[i]>=i+1) cnt++;
	}

	cout<<cnt<<endl;
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    solve();
	}
}