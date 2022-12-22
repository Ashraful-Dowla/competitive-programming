/*
https://codeforces.com/contest/750/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

int n,k;

bool possible(int n){
	int sum = n*(n+1);
	sum/=2;
	return (240-sum*5)>=k;
}

int main(){
	cin>>n>>k;

	int lo=0,hi=n,mid,ans=0;

	while(hi>lo) {
	    mid=(hi+lo)/2;
	    if(possible(mid)){
	    	lo=mid+1;
	    	ans=max(ans,mid);
	    }
	    else hi=mid;
	}
	if(possible(lo)) ans=max(ans,lo);
	cout<<ans<<endl;
}