/*
https://codeforces.com/contest/489/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n;

	int boys[n];

	for(int i=0;i<n;++i){
		cin>>boys[i];
	}
	sort(boys,boys+n);

	cin>>m;
	int girls[m];
	for(int i=0;i<m;++i){
		cin>>girls[i];
	}
	sort(girls,girls+m);

	int ans=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(abs(boys[i]-girls[j])<=1) {
				ans++;
				girls[j]=INT_MAX;
				break;
			}
		}
		
	}
	cout<<ans<<endl;
}	