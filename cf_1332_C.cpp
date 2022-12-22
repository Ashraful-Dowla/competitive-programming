/*
https://codeforces.com/problemset/problem/1332/C
*/
#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int n,k;
int cnt[N][30];
string s;

int calc(int x,int y){
	int res=0,mx=0;
	for(int i=0;i<26;++i){
		int ct = cnt[x][i]+cnt[y][i];
		res+=ct;
		mx = max(mx,ct);
	}

	return res-mx;	
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    cin>>n>>k;
	    cin>>s;

	    for(int i=0;i<k;++i){
	    	for(int j=0;j<26;++j){
	    		cnt[i][j]=0;
	    	}
	    }

	    for(int i=0;i<n;++i){
	    	cnt[i%k][s[i]-'a']++;
	    }

	    int ct=0;
	    for(int i=0;i<k;++i){
	    	ct+=calc(i,k-i-1);
	    }

	    cout<<ct/2<<endl;
	}
}