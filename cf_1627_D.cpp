/*
https://codeforces.com/problemset/problem/1627/D
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e6+10;
bool taken[N];

int main(){
	int n;
	cin>>n;

	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		taken[x]=true;
	}

	int ans=0;
	for(int i=1;i<N;++i){
		int g=0;
		for(int j=i;j<N;j+=i){
			if(taken[j]){
				g=__gcd(g,j);
			}
		}

		if(g==i && !taken[i]){
			ans++;
		} 
	}

	cout<<ans<<endl;
}