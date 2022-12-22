/*
https://codeforces.com/problemset/problem/1661/B
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD=1<<15;

int main(){
	int n;
	cin>>n;

	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		int ans = INT_MAX;
		for(int j=0;j<=15;++j){
			for(int k=0;k<=15;++k){
				if(((x+j)<<k)%MOD==0){
					ans = min(ans,j+k);
				}
			}
		}
		cout<<ans<<" ";
	}
}