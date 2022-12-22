/*
https://codeforces.com/contest/1385/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

int n,res;
string s;

int cnt(int l,int r,char ch){
	int ct=0;
	for(int i=l;i<=r;++i){
		if(s[i]==ch) ct++;
	}
	return ct;
}

int generate(int l,int r, char c){
	if(l==r) return s[l]!=c;

	int mid = (l+r)/2;
	int len = mid-l+1;

	char nw = c+1;
	int cnt1 = len - cnt(l,mid,c) + generate(mid+1,r,nw);
	int cnt2 = len - cnt(mid+1,r,c) + generate(l,mid,nw);
	
	return min(cnt1,cnt2);
}

int main(){
	int t;
	cin>>t;
	while(t--) {
	   cin>>n;
	   cin>>s;
	   cout<<generate(0,n-1,'a')<<endl;
	}
}