/*
https://codeforces.com/problemset/problem/339/B
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
long long arr[N];

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;++i) cin>>arr[i];

	long long pos=1, cnt=0;
	for(int i=1;i<=m;++i){
		long long val = arr[i];
		if(val==pos) continue;
		else if(pos<val){
			cnt+=(val-pos);
			pos = val;
		}
		else {
			cnt+=(n-pos+1);
			cnt+=(val-1);
			pos=val; 
		}
	}
	cout<<cnt<<endl;
}