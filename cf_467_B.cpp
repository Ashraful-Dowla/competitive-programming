/*
https://codeforces.com/contest/467/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int n,m,k;
	cin>>n>>m>>k;

	ll arr[m];
	for(int i=0;i<m;++i){
		cin>>arr[i];
	}

	ll m1;
	cin>>m1;
	int cnt=0;
	for(int i=0;i<m;++i){
		int len = __builtin_popcountll(arr[i]^m1);
		if(len<=k) cnt++;
	}

	cout<<cnt<<endl;
}