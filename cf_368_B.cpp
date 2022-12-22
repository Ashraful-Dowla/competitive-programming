/*
https://codeforces.com/contest/368/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
bool chk[N];

int main(){
	int n,m;
	cin>>n>>m;
	int sf[n+2],arr[n+2];
	memset(sf,0,sizeof(sf));
	for(int i=1;i<=n;++i){
		cin>>arr[i];
	}

	for(int i=n;i>=1;--i){
		sf[i]=sf[i+1];
		if(chk[arr[i]]) continue;
		chk[arr[i]]=true;
		sf[i]++;
	}

	for(int i=0;i<m;++i){
		int x;
		cin>>x;
		cout<<sf[x]<<endl;
	}
}