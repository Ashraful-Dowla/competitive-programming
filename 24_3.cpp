/*
https://www.hackerearth.com/problem/algorithm/maximum-fruits-4/
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n+5],pf[n+5];
	memset(pf,0,sizeof(pf));

	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	int q;
	cin>>q;
	while(q--){
		int x,l,r;
		cin>>x>>l>>r;
		pf[l+1]+=x;
		pf[r+2]-=x;
	}

	int mx=-1;
	for(int i=1;i<=n;i++){
		pf[i]+=pf[i-1];
	}
	for(int i=1;i<=n;i++){
		mx = max(mx, pf[i]+arr[i]);
	}
	cout<<mx<<endl;
}