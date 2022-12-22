/*
https://codeforces.com/problemset/problem/682/A
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int n,m;
	cin>>n>>m;

	ll cnt[5];
	memset(cnt,0,sizeof(cnt));

	for(int i=1;i<=m;++i){
		cnt[i%5]++;
	}

	ll sum=0;
	for(int i=1;i<=n;++i){
		int idx = (5-i%5)%5;
		sum+=cnt[idx];
	}

	cout<<sum<<endl;
}