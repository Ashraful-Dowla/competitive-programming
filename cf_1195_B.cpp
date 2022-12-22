/*
https://codeforces.com/contest/1195/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,k;

bool calc(ll nn){
	ll sum = nn*(nn+1);
	sum/=2;
	sum+=(nn-n);

	return sum<=k;
}

int main(){
	cin>>n>>k;
	ll lo=1,hi=n,mid,ans=0;

	while(hi>=lo){
	   mid=(hi+lo)/2;
	   if(calc(mid)) {
		  lo=mid+1;
		  ans=mid;
	   }
	   else hi=mid-1;
	}

	cout<<(n-ans)<<endl;
}