/*
https://codeforces.com/contest/1777/problem/A
*/
#include <bits/stdc++.h>
using namespace std;
 
void solve(){
	int n;
	cin>>n;
 
	int arr[n];
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}
 
	int cnt=0;
	for(int i=0;i+1<n;++i){
		if(arr[i]%2==arr[i+1]%2) cnt++;
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