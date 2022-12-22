/*
https://codeforces.com/problemset/problem/1176/B
*/
#include <bits/stdc++.h>
using namespace std;


int main(){
	int t;
	cin>>t;

	while(t--) {
	   int n;
	   cin>>n;

	   int cnt[3];
	   memset(cnt,0,sizeof(cnt));

	   for(int i=0;i<n;++i){
	   	int x;
	   	cin>>x;
	   	cnt[x%3]++;
	   }

	   int ct=cnt[0];
	   if(cnt[1]&&cnt[2]){
	   	int mn=min(cnt[1],cnt[2]);
	   	ct+=mn, cnt[1]-=mn, cnt[2]-=mn;
	   }
	   if(cnt[1]){
	   	 ct+=(cnt[1])/3;
	   }
	   if(cnt[2]){
	   	 ct+=(cnt[2])/3;
	   }

	   cout<<ct<<endl;
	}
}