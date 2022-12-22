/*
https://codeforces.com/contest/1097/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

int n,arr[20],sum;

bool isPossible(int len){
	if(len==n && sum%360==0) return true;
	if(len==n) return false;

	bool check=false;
	sum+=arr[len];
	check|=isPossible(len+1);
	sum-=2*arr[len];
	check|=isPossible(len+1);
	sum+=arr[len];
	return check;
}

int main(){
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}
	cout<<(isPossible(0) ? "YES": "NO")<<endl;
}