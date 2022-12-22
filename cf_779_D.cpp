/*
https://codeforces.com/contest/779/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int del[N];

string t,p,tc;

bool maxPossible(int mid){
	tc=t;
	for(int i=0;i<mid;++i){
		tc[del[i]]='-';
	}

	int cnt=0;
	for(int i=0,j=0;i<tc.size()&&j<p.size();++i){
		if(tc[i]==p[j]) {
			cnt++;
			++j;
		}
	}

	return cnt==p.size();
}

int main(){
	cin>>t>>p;
	for(int i=0;i<t.size();++i){
		cin>>del[i];
		del[i]--;
	}

	int lo=1,hi=t.size(),mid,ans=0;

	while(hi>lo) {
	    mid = (hi+lo)/2;
	    if(maxPossible(mid)){
	    	lo=mid+1;
	    	ans=max(ans,mid);
	    }
	    else hi=mid;
	}
	cout<<ans<<endl;
}