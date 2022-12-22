/*
https://codeforces.com/problemset/problem/760/B
*/
#include <bits/stdc++.h>
using namespace std;

int n,m,k,ans=1,cnt=1;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;

	m-=n;
	while(m>0){
		if(k+ans<=n) cnt++;
		if(k-ans>=1) cnt++;
		m-=cnt;
		ans++;
	}	
	cout<<ans;
}