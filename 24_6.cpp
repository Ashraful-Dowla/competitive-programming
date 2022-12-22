/*
https://www.hackerearth.com/problem/algorithm/vaccination-time/
*/
#include <bits/stdc++.h>
using namespace std;

int hsh[1005][1005];

int main(){
	int m,n;
	cin>>m>>n;

	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			hsh[i][j]=x%2;
		}
	}

	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			hsh[i][j]+=(hsh[i-1][j]+hsh[i][j-1]-hsh[i-1][j-1]);
		}
	}

	int q;
	cin>>q;
	while(q--){
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		cout<<hsh[l2][r2]-hsh[l1-1][r2]-hsh[l2][r1-1]+hsh[l1-1][r1-1]<<endl;
	}
}